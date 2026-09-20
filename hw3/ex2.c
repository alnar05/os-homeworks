#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int status;

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork 1 failed");
    } 
    else if (pid1 == 0) {
        printf("Child 1 pid = %d\n", getpid());
        exit(101);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork 2 failed");
    } 
    else if (pid2 == 0) {
        printf("Child 2 pid = %d\n", getpid());
        exit(102);
    }

    waitpid(pid2, &status, 0);
    if (WIFEXITED(status)) {
        printf("waitpid(): waited for child 2 (pid = %d) | status = %d\n", 
               pid2, WEXITSTATUS(status));
    }

    pid_t after_waitpid = wait(&status);
    if (WIFEXITED(status)) {
        printf("wait(): waited for child 1 (pid = %d) | status = %d\n", 
               after_waitpid, WEXITSTATUS(status));
    }

    printf("Parent pid = %d\n", getpid());

    return 0;
}