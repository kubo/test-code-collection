/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#ifdef _WIN32
#include <io.h>
#endif
#include "util.h"

OCIEnv *g_envhp;

int check_args(int argc, char **argv, name_t *username, name_t *password, name_t *database)
{
    if (argc != 2 && argc != 3) {
        return -1;
    }
    username->name = (OraText*)argv[0];
    username->len = strlen(argv[0]);
    password->name = (OraText*)argv[1];
    password->len = strlen(argv[1]);
    if (argc > 2) {
        database->name = (OraText*)argv[2];
        database->len = strlen(argv[2]);
    } else {
        database->name = NULL;
        database->len = 0;
    }
    return 0;
}

sword init_env(void)
{
    sword rv;

    rv = OCIEnvCreate(&g_envhp, OCI_DEFAULT, NULL, NULL, NULL, NULL, 0, NULL);
    check_error(rv, "OCIEnvCreate", g_envhp, OCI_HTYPE_ENV);
    return rv;
}

sword check_error(sword result, const char *func, void *hndl, ub4 type)
{
    char msg[OCI_ERROR_MAXMSG_SIZE2];
    sb4 code;

    switch (result) {
    case OCI_SUCCESS:
    case OCI_SUCCESS_WITH_INFO:
        green_message("%s => %d (Success)", func, result);
        return result;
    case OCI_NO_DATA:
    case OCI_ERROR:
        OCIErrorGet(hndl, 1, NULL, &code, (OraText*)msg, sizeof(msg), type);
        strtok(msg, "\n");
        break;
    case OCI_INVALID_HANDLE:
        strcpy(msg, "Invalid Handle");
        break;
    case OCI_NEED_DATA:
        strcpy(msg, "Need Data");
        break;
    default:
        sprintf(msg, "Unknown error code %d", result);
        break;
    }
    red_message("%s => %d (%s)", func, result, msg);
    return result;
}

#ifdef _WIN32
#define COLOR_DEFAULT  (0xFFFF)
#define COLOR_GREEN    (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_RED      (FOREGROUND_RED | FOREGROUND_INTENSITY)
static int vmessage(WORD color, const char *format, va_list ap)
{
#if 0 /* not testted */
    HANDLE hConsole = NULL;
    WORD oldcolor = (WORD)-1;
    int rv;

    if (color != COLOR_DEFAULT && _isatty(_fileno(stdout))) {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole != NULL) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
                oldcolor = csbi.wAttributes;
            }
        }
    }

    if (oldcolor != (WORD)-1) {
        SetConsoleTextAttribute(hConsole, color);
    }
#endif
    rv = vprintf(format, ap);
    fflush(stdout);
#if 0 /* not testted */
    if (oldcolor != (WORD)-1) {
        SetConsoleTextAttribute(hConsole, oldcolor);
    }
#endif
    putchar('\n');
    return rv;
}
#else
#define COLOR_DEFAULT   NULL
#define COLOR_GREEN     "32"
#define COLOR_RED       "31"
static int vmessage(const char *color, const char *format, va_list ap)
{
    int rv;

    if (color != COLOR_DEFAULT) {
        printf("\033[%sm", color);
    }
    rv = vprintf(format, ap);
    if (color != COLOR_DEFAULT) {
        printf("\033[0m");
    }
    putchar('\n');
    return rv;
}
#endif

int message(const char *format, ...)
{
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = vmessage(COLOR_DEFAULT, format, ap);
    va_end(ap);
    return rv;
}

int green_message(const char *format, ...)
{
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = vmessage(COLOR_GREEN, format, ap);
    va_end(ap);
    return rv;
}

int red_message(const char *format, ...)
{
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = vmessage(COLOR_RED, format, ap);
    va_end(ap);
    return rv;
}
