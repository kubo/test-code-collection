/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <string.h>
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
        strcpy(msg, "Success");
        break;
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
    fprintf(stderr, "%s => %d (%s)\n", func, result, msg);
    return result;
}
