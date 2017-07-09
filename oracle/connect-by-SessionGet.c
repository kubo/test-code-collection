/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <string.h>
#include "test-oracle.h"

sword oracle_connect(conn_t *conn, const char *username, const char *password, const char *dbname)
{
    OCIAuthInfo *authhp;
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->errhp, OCI_HTYPE_ERROR, 0, NULL),
            g_envhp);

    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&authhp, OCI_HTYPE_AUTHINFO, 0, NULL),
            g_envhp);
    CHK(OCIAttrSet(authhp, OCI_HTYPE_AUTHINFO, (char*)username, strlen(username),
                   OCI_ATTR_USERNAME, conn->errhp),
        conn->errhp);
    CHK(OCIAttrSet(authhp, OCI_HTYPE_AUTHINFO, (char*)password, strlen(password),
                   OCI_ATTR_PASSWORD, conn->errhp),
        conn->errhp);
#ifdef OCI_ATTR_DRIVER_NAME
    CHK(OCIAttrSet(authhp, OCI_HTYPE_AUTHINFO, "test", 4,
                   OCI_ATTR_DRIVER_NAME, conn->errhp),
        conn->errhp);
#endif

    CHK(OCISessionGet(g_envhp, conn->errhp, &conn->svchp, authhp, 
                      (OraText *)dbname, strlen(dbname),
                      NULL, 0, NULL, NULL, NULL, OCI_DEFAULT),
        conn->errhp);

    CHK(OCIAttrGet(conn->svchp, OCI_HTYPE_SVCCTX, &conn->srvhp, 0, OCI_ATTR_SERVER, conn->errhp),
        conn->errhp);
    CHK(OCIAttrGet(conn->svchp, OCI_HTYPE_SVCCTX, &conn->usrhp, 0, OCI_ATTR_SESSION, conn->errhp),
        conn->errhp);
    CHK(OCIHandleFree(authhp, OCI_HTYPE_AUTHINFO), NULL);
    return 0;
}

sword oracle_disconnect(conn_t *conn)
{
    CHK(OCISessionRelease(conn->svchp, conn->errhp, NULL, 0, OCI_DEFAULT), conn->errhp);
    CHK(OCIHandleFree(conn->errhp, OCI_HTYPE_ERROR), NULL);
    return 0;
}
