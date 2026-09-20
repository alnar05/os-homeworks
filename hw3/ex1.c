#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child pid: %d\n", getpid());
    } 
    else if (pid > 0) {
        printf("Parent pid: %d\n", getpid());
    } 
    else {
        perror("Process failed");
    }

    return 0;
}