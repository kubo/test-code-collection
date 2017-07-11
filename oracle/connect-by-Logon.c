/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include "connect.h"

sword oracle_connect(conn_t *conn, const name_t *username, const name_t *password, const name_t *database)
{
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->errhp, OCI_HTYPE_ERROR, 0, NULL),
            g_envhp);
    CHK(OCILogon(g_envhp, conn->errhp, &conn->svchp,
                 username->name, username->len,
                 password->name, password->len,
                 database->name, database->len),
        conn->errhp);
    CHK(OCIAttrGet(conn->svchp, OCI_HTYPE_SVCCTX, &conn->srvhp, 0, OCI_ATTR_SERVER, conn->errhp),
        conn->errhp);
    CHK(OCIAttrGet(conn->svchp, OCI_HTYPE_SVCCTX, &conn->usrhp, 0, OCI_ATTR_SESSION, conn->errhp),
        conn->errhp);
    return 0;
}

sword oracle_disconnect(conn_t *conn)
{
    CHK(OCILogoff(conn->svchp, conn->errhp), conn->errhp);
    CHK(OCIHandleFree(conn->errhp, OCI_HTYPE_ERROR), NULL);
    return 0;
}
