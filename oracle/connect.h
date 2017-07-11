/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#ifndef CONNECT_H
#define CONNECT_H 1

#include <oci.h>
#include "util.h"

typedef struct {
    OCIError *errhp;
    OCISvcCtx *svchp;
    OCIServer *srvhp;
    OCISession *usrhp;
} conn_t;

sword oracle_connect(conn_t *conn, const name_t *username, const name_t *password, const name_t *database);
sword oracle_disconnect(conn_t *conn);

#endif /* CONNECT_H */
