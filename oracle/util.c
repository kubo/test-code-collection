/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <string.h>
#include "test-oracle.h"

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
