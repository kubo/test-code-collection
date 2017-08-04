/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#ifndef UTIL_H
#define UTIL_H 1

#include <oci.h>

extern OCIEnv *g_envhp;

#define chk_env(func, envhp) check_error(func, #func, envhp, OCI_HTYPE_ENV)
#define chk(func, errhp) check_error(func, #func, errhp, OCI_HTYPE_ERROR)

#define SUCCESS(rv) ((rv) == OCI_SUCCESS || (rv) == OCI_SUCCESS_WITH_INFO)

/* error on return */
#define CHK_ENV(func, envhp) do { \
    sword rv__ = check_error(func, #func, envhp, OCI_HTYPE_ENV); \
    if (!SUCCESS(rv__)) { \
        return rv__; \
    } \
} while (0)

/* error on return */
#define CHK(func, errhp) do { \
    sword rv__ = check_error(func, #func, errhp, OCI_HTYPE_ERROR); \
    if (!SUCCESS(rv__)) { \
        return rv__; \
    } \
} while (0)

typedef struct {
    OraText *name;
    ub4 len;
} name_t;

int check_args(int argc, char **argv, name_t *username, name_t *password, name_t *database);
sword init_env(void);
sword check_error(sword result, const char *func, void *hndl, ub4 type);

int message(const char *format, ...);
int green_message(const char *format, ...);
int red_message(const char *format, ...);

#endif /* UTIL_H */
