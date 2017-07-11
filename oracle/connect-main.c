/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <stdlib.h>
#include "connect.h"

int main(int argc, char **argv)
{
    name_t username;
    name_t password;
    name_t database;
    conn_t conn;

    if (check_args(argc - 1, argv + 1, &username, &password, &database) != 0) {
        fprintf(stderr, "Usage: %s username password [database]\n", argv[0]);
        return 1;
    }

    if (init_env() != 0) {
        return 1;
    }

    printf("Connecting to Oracle\n");
    if (oracle_connect(&conn, &username, &password, &database) != 0) {
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
