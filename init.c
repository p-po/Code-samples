/*
 gcc -fPIC -g -c -Wall -Wextra -std=gnu99 init.c
 gcc -shared -Wl,-soname,libinit.1.0 -o libinit init.o
 */
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>

void exec_monitor(void);
//void exec_app(void);

static int set = 0;

/*void func() 
{
    puts("func");
}*/

void __attribute__ ((constructor)) init() {
    puts("Hello, init!");
//    func();
    if(!set) exec_monitor();
}

void exec_monitor(void)
{
    set = 1;

    puts("In monitor");
    switch (fork()) {
    case -1: exit(1);
    case 0: break; 
    default: return; //_exit(0);
    }
/*
    setsid();

    switch (fork()) {
    case -1: exit(1);
    case 0: break;
    default: _exit(0);
    }
    
    umask(0);
    chdir("/");
    printf("PID=%d PPID=%d\n", getpid(), getppid());

    for (int fd = 0; fd < sysconf(_SC_OPEN_MAX); fd++)
        close(fd);

    close(STDIN_FILENO);
    open("/dev/null", O_RDWR);
    dup2(STDIN_FILENO, STDOUT_FILENO);
    dup2(STDIN_FILENO, STDERR_FILENO);
*/
    fflush(stdout);
    execv("./monitor", (char*[]){(void*)0});
    perror("execv");
}

#if 0
void exec_app(void) 
{
    char *arr[256] = {0};
    char *val;
    char s[256] = "VAR_1";
    size_t i = 0;

    while((val=getenv(s))) {
        arr[i++] = strdup(val);
        snprintf(s, sizeof s, "VAR_%zu", i);       
    }

    arr[i] = (char*)0;

    for(int j=0; arr[j]; j++)
        printf("[%s] ", arr[j]);

    fflush(stdout);
}

#endif
