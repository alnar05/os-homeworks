#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int status;

    pid_t pid1 = fork();

    if (pid1 == 0) {
        printf("Child pid: %d\n", getpid());
        exit(0);
    }
    else if (pid1 < 0) {
        perror("Process failed");
    } 


    pid_t pid2 = fork();

    if (pid2 == 0) {
        printf("Child pid: %d\n", getpid());
        exit(1);
    } 
    else if (pid2 < 0) {
        perror("Process failed");
    } 

    waitpid(pid1, &status, 0);
    if (WIFEXITED(status)) {
        int code = WEXITSTATUS(status);
        printf("parent waited for child 1 (pid = %d) | status = %d | %s\n", 
               pid1, WEXITSTATUS(status), (code == 0) ? "Exited normally" : "Exited with error");
    }
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status)) {
        int code = WEXITSTATUS(status);
        printf("parent waited for child 2 (pid = %d) | status = %d | %s\n", 
               pid2, WEXITSTATUS(status), (code == 0) ? "Exited normally" : "Exited with error");
    }

    printf("parent after two children are done, pid = %d\n", getpid());
    return 0;
}