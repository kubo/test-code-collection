/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#ifndef TEST_ORACLE_H
#define TEST_ORACLE_H 1

#include <oci.h>

extern OCIEnv *g_envhp;

#define chk_env(func, envhp) check_error(func, #func, envhp, OCI_HTYPE_ENV)
#define chk(func, errhp) check_error(func, #func, errhp, OCI_HTYPE_ERROR)

/* error on return */
#define CHK_ENV(func, envhp) do { \
    sword rv__ = check_error(func, #func, envhp, OCI_HTYPE_ENV); \
    if (rv__ != OCI_SUCCESS && rv__ != OCI_SUCCESS_WITH_INFO) { \
        return rv__; \
    } \
} while (0)

/* error on return */
#define CHK(func, errhp) do { \
    sword rv__ = check_error(func, #func, errhp, OCI_HTYPE_ERROR); \
    if (rv__ != OCI_SUCCESS && rv__ != OCI_SUCCESS_WITH_INFO) { \
        return rv__; \
    } \
} while (0)

typedef struct {
    OCIError *errhp;
    OCISvcCtx *svchp;
    OCIServer *srvhp;
    OCISession *usrhp;
} conn_t;

/* connect-by-*.c */
sword oracle_connect(conn_t *conn, const char *username, const char *password, const char *dbname);
sword oracle_disconnect(conn_t *conn);

/* util.c */
sword check_error(sword result, const char *func, void *hndl, ub4 type);

#endif /* TEST_ORACLE_H */
