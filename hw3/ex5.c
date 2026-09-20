#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child pid: %d\n", getpid());
        exit(0);
    } 
    else if (pid > 0) {
        printf("Parent pid: %d\n", getpid());

        sleep(10);

        wait(NULL);
        printf("Parent cleaned up the child. Zombie process eliminated.\n");
    } 
    else {
        perror("fork failed");
    }

    return 0;
}