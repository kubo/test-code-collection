/*
 * Get the current thread ID.
 *
 * pthread_self() returns the pointer to struct pthread on Linux and macOS.
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

int main()
{
#ifdef __APPLE__
  uint64_t tid = 0;

  printf("pthread_self = %p\n", pthread_self());
  pthread_threadid_np(NULL, &tid);
  printf("thread_id = %llu\n", tid);
#endif
#ifdef __linux
  printf("pthread_self = %lu\n", pthread_self());
  printf("thread_id = %ld\n", syscall(SYS_gettid));
#endif
}
