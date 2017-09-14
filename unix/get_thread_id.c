/*
 * Get the current thread ID.
 *
 * pthread_self() returns the pointer to struct pthread on Linux and macOS.
 *
 * On Linux:
 *  Return values of syscall(SYS_gettid) are same with IDs at the left of strace output.
 *
 *    $ cc -o get_thread_id get_thread_id.c -pthread
 *    $ strace -f -e trace=gettid -o strace.log ./get_thread_id
 *    main : pthread_self = 139940549068544
 *    main : thread_id = 14828
 *    child: pthread_self = 139940540798720
 *    child: thread_id = 14829
 *    $ cat strace.log
 *    14828 gettid()                          = 14828
 *    14829 gettid()                          = 14829
 *    14829 +++ exited with 0 +++
 *    14828 +++ exited with 0 +++
 *
 */
#include <stdio.h>
#include <pthread.h>

#ifdef __linux
#include <unistd.h>
#include <sys/syscall.h>
#endif

#ifdef __APPLE__
#include <stdint.h>
#endif

void *print_thread_id(void *arg)
{
  const char *name = (const char *)arg;
#ifdef __APPLE__
  uint64_t tid = 0;

  printf("%s: pthread_self = %p\n", name, pthread_self());
  pthread_threadid_np(NULL, &tid);
  printf("%s: thread_id = %llu\n", name, tid);
#endif
#ifdef __linux
  printf("%s: pthread_self = %lu\n", name, pthread_self());
  printf("%s: thread_id = %ld\n", name, syscall(SYS_gettid));
#endif
}

int main()
{
    pthread_t thread;

    print_thread_id("main ");
    pthread_create(&thread, NULL, print_thread_id, "child");
    pthread_join(thread, NULL);
    return 0;
}
