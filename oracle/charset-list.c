#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include "util.h"

static int list_charset(void)
{
    ub4 csid;

    printf("  ID  |        Oracle name        |      IANA name     | IANA to Oracle\n");
    printf("------|---------------------------|--------------------|----------------\n");
    for (csid = 0; csid <= UB2MAXVAL; csid++) {
        char oraname[OCI_NLS_MAXBUFSZ];
        char iananame[OCI_NLS_MAXBUFSZ];
        char oraname2[OCI_NLS_MAXBUFSZ];

        if (OCINlsCharSetIdToName(g_envhp, (oratext*)oraname, sizeof(oraname), csid) != OCI_SUCCESS) {
            continue;
        }
        if (OCINlsNameMap(g_envhp, (oratext*)iananame, sizeof(iananame), (oratext*)oraname, OCI_NLS_CS_ORA_TO_IANA) != OCI_SUCCESS) {
            printf("%5u | %-25s |                    |\n", csid, oraname);
        } else if (OCINlsNameMap(g_envhp, (oratext*)oraname2, sizeof(oraname2), (oratext*)iananame, OCI_NLS_CS_IANA_TO_ORA) != OCI_SUCCESS) {
            printf("%5u | %-25s | %-18s | ERROR\n", csid, oraname, iananame);
        } else if (strcmp(oraname, oraname2) == 0) {
            printf("%5u | %-25s | %-18s | :+1:\n", csid, oraname, iananame);
        } else {
            printf("%5u | %-25s | %-18s | :-1: %s\n", csid, oraname, iananame, oraname2);
        }
    }
    return 0;
}

#define MAX_SRC_LENGTH 6

static void byte_sequence_to_unicode_sub(OCIError *errhp, uint8_t *src, int idx, ub2 srcid, ub4 dstid)
{
    int i;

    for (i = 0; i < 256; i++) {
        uint16_t dst[2];
        size_t rsize = 0;
        sword rv;

        src[idx] = i;
        rv = OCINlsCharSetConvert(g_envhp, errhp, dstid, dst, sizeof(dst), srcid, src, idx + 1, &rsize);
        if (rv == OCI_SUCCESS) {
            uint32_t ucs4;
            int j;

            switch (rsize) {
            case 2:
                dst[0] = ntohs(dst[0]);
                if (dst[0] == 0xFFFD) {
                    continue;
                }
                ucs4 = dst[0];
                break;
            case 4:
                dst[0] = ntohs(dst[0]);
                if ((dst[0] & 0xFC00) != 0xD800) {
                    continue;
                }
                dst[1] = ntohs(dst[1]);
                if ((dst[0] & 0xFC00) != 0xDC00) {
                    continue;
                }
                /* surrogate pair */
                ucs4 = (((dst[0] & 0x3FF) << 10) | (dst[1] & 0x3FF)) + 0x10000;
                break;
            default:
                continue;
            }
            for (j = 0; j <= idx; j++) {
                printf("%02X ", src[j]);
            }
            printf("=> U+%04X\n", ucs4);
        } else {
            if (idx + 1 < MAX_SRC_LENGTH) {
                byte_sequence_to_unicode_sub(errhp, src, idx + 1, srcid, dstid);
            }
        }
    }
}

static int byte_sequence_to_unicode(const char *csname)
{
    ub2 srcid = OCINlsCharSetNameToId(g_envhp, (const oratext*)csname);
    ub2 dstid = 2000; /* AL16UTF16 charset id */
    OCIError *errhp;
    uint8_t src[MAX_SRC_LENGTH];

    if (srcid == 0) {
        red_message("Failed to convert '%s' to character set name id.", csname);
        return 1;
    }
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&errhp, OCI_HTYPE_ERROR, 0, NULL),
            g_envhp);

    byte_sequence_to_unicode_sub(errhp, src, 0, srcid, dstid);
    return 0;
}

static int unicode_to_byte_sequence(const char *csname)
{
    ub2 srcid = 2000; /* AL16UTF16 charset id */
    ub2 dstid = OCINlsCharSetNameToId(g_envhp, (const oratext*)csname);
    OCIError *errhp;
    int unicode;
    uint8_t rep[MAX_SRC_LENGTH]; /* replacement character */
    size_t replen = 0;
    uint16_t rep_unicode = 0;

    if (dstid == 0) {
        red_message("Failed to convert '%s' to character set name id.", csname);
        return 1;
    }
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&errhp, OCI_HTYPE_ERROR, 0, NULL),
            g_envhp);

    if (strncmp(csname, "JA16SJIS", 8) == 0) {
        memcpy(rep, "\x81\x48", 2);
        replen = 2;
        rep_unicode = 0xFF1F;
    } else if (strncmp(csname, "JA16EUC", 7) == 0) {
        memcpy(rep, "\xa1\xa9", 2);
        replen = 2;
        rep_unicode = 0xFF1F;
    }
    for (unicode = 0; unicode < UINT16_MAX; unicode++) {
        uint16_t src = htons(unicode);
        uint8_t dst[MAX_SRC_LENGTH];
        size_t rsize = 0;
        sword rv, j;

        rv = OCINlsCharSetConvert(g_envhp, errhp, dstid, dst, sizeof(dst), srcid, &src, sizeof(src), &rsize);
        if (rv == OCI_SUCCESS) {
            if (rsize == replen && memcmp(dst, rep, replen) == 0 && unicode != rep_unicode) {
                /* exclude replacement characters */
                continue;
            }
            printf("U+%04X =>", unicode);
            for (j = 0; j < rsize; j++) {
                printf(" %02X", dst[j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

int main(int argc, char **argv)
{

    if (init_env() != 0) {
        return 1;
    }
    switch (argc) {
    case 1:
        return list_charset();
    case 2:
        return byte_sequence_to_unicode(argv[1]);
    case 3:
        if (strcmp(argv[1], "-r") == 0) {
            return unicode_to_byte_sequence(argv[2]);
        }
    }
    fprintf(stderr, "Usage: %s [[-r] charset]\n", argv[0]);
    return 1;
}
