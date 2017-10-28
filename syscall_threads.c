/* This program never terminates. */
#define _GNU_SOURCE
#include <errno.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pthread_t main_tid;

void *f(void *arg)
{
    puts("thread");
    sleep(2);
    printf("mtid=%ld\n", main_tid);
    errno = pthread_join(main_tid, 0);
    perror("join");
    return NULL;
}

int main()
{
    pid_t pid = syscall(SYS_fork);

    if (pid == 0) {
        pthread_t tid;
        main_tid = pthread_self();
        pthread_create(&tid, 0, f, 0);

        puts("child done");
        pthread_exit(0);
    }

    wait(0);
    puts("main done");
}
