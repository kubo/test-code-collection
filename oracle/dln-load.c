/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <dlfcn.h>
#include <link.h>

typedef struct OCIEnv OCIEnv;
typedef unsigned int ub4;

typedef int (*OCIEnvCreate_t)(OCIEnv **envp, ub4 mode, void *ctxp,
                              void *(*malocfp)(void *ctxp, size_t size),
                              void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize),
                              void (*mfreefp)(void *ctxp, void *memptr),
                              size_t xtramem_sz, void **usrmempp);

int main(int argc, char **argv)
{
    void *hndl;
    OCIEnvCreate_t env_create;
    OCIEnv *envhp;
    int rv;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s path/to/libclntsh.so\n", argv[0]);
        return 1;
    }
    hndl = dlopen(argv[1], RTLD_LAZY);
    if (hndl == NULL) {
        printf("dlopen error: %s\n", dlerror());
        return 1;
    }
    env_create = (OCIEnvCreate_t)dlsym(hndl, "OCIEnvCreate");
    if (env_create == NULL) {
        printf("dlsym error: %s\n", dlerror());
        return 1;
    }
    rv = env_create(&envhp, 0, NULL, NULL, NULL, NULL, 0, NULL);
    printf("OCIEnvCreate() => %d\n", rv);
    if (rv == 0) {
        struct link_map *lmap;
        printf("link map:\n");
        for (lmap = _r_debug.r_map; lmap != NULL; lmap = lmap->l_next) {
            printf(" %p: %s\n", (void*)lmap->l_addr, lmap->l_name);
        }
    }
    return 0;
}
