/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <string.h>
#include "test-oracle.h"

sword oracle_connect(conn_t *conn, const char *username, const char *password, const char *dbname)
{
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->errhp, OCI_HTYPE_ERROR, 0, NULL),
            g_envhp);
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->svchp, OCI_HTYPE_SVCCTX, 0, NULL),
            g_envhp);
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->srvhp, OCI_HTYPE_SERVER, 0, NULL),
            g_envhp);
    CHK_ENV(OCIHandleAlloc(g_envhp, (dvoid*)&conn->usrhp, OCI_HTYPE_SESSION, 0, NULL),
            g_envhp);

    CHK(OCIServerAttach(conn->srvhp, conn->errhp, (OraText*)dbname, strlen(dbname), OCI_DEFAULT),
        conn->errhp);
    CHK(OCIAttrSet(conn->svchp, OCI_HTYPE_SVCCTX, conn->srvhp, 0, OCI_ATTR_SERVER, conn->errhp),
        conn->errhp);

    CHK(OCIAttrSet(conn->usrhp, OCI_HTYPE_SESSION, (char*)username, strlen(username),
                   OCI_ATTR_USERNAME, conn->errhp),
        conn->errhp);
    CHK(OCIAttrSet(conn->usrhp, OCI_HTYPE_SESSION, (char*)password, strlen(password),
                   OCI_ATTR_PASSWORD, conn->errhp),
        conn->errhp);
#ifdef OCI_ATTR_DRIVER_NAME
    CHK(OCIAttrSet(conn->usrhp, OCI_HTYPE_SESSION, "test", 4,
                   OCI_ATTR_DRIVER_NAME, conn->errhp),
        conn->errhp);
#endif
    CHK(OCIAttrSet(conn->svchp, OCI_HTYPE_SVCCTX, conn->usrhp, 0, OCI_ATTR_SESSION, conn->errhp),
        conn->errhp);

    CHK(OCISessionBegin(conn->svchp, conn->errhp, conn->usrhp, OCI_CRED_RDBMS, OCI_DEFAULT),
        conn->errhp);
    return 0;
}

sword oracle_disconnect(conn_t *conn)
{
    CHK(OCISessionEnd(conn->svchp, conn->errhp, conn->usrhp, OCI_DEFAULT), conn->errhp);
    CHK(OCIServerDetach(conn->srvhp, conn->errhp, OCI_DEFAULT), conn->errhp);
    CHK(OCIHandleFree(conn->errhp, OCI_HTYPE_ERROR), NULL);
    CHK(OCIHandleFree(conn->svchp, OCI_HTYPE_SVCCTX), NULL);
    CHK(OCIHandleFree(conn->srvhp, OCI_HTYPE_SERVER), NULL);
    CHK(OCIHandleFree(conn->usrhp, OCI_HTYPE_SESSION), NULL);
    return 0;
}
