/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <stdlib.h>
#include "test-oracle.h"

OCIEnv *g_envhp;

int main(int argc, char **argv)
{
    const char *username;
    const char *password;
    const char *database = "";
    conn_t conn;
    sword rv;

    switch (argc) {
    case 4:
        database = argv[3];
    case 3:
        password = argv[2];
        username = argv[1];
        break;
    default:
        fprintf(stderr, "Usage: %s username password [database]\n", argv[0]);
        return 1;
    }

    rv = OCIEnvCreate(&g_envhp, OCI_DEFAULT, NULL, NULL, NULL, NULL, 0, NULL);
    check_error(rv, "OCIEnvCreate", g_envhp, OCI_HTYPE_ENV);
    if (rv != 0) {
        exit(1);
    }

    printf("Connecting to Oracle\n");
    if (oracle_connect(&conn, username, password, database) != 0) {
        printf("failed\n");
        return 1;
    }
    printf("succeeded\n");

    printf("Disconnecting from Oracle\n");
    if (oracle_disconnect(&conn) != 0) {
        printf("failed\n");
        return 1;
    }
    printf("succeeded\n");
    return 0;
}
