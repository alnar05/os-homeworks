#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        execl("/usr/bin/ls", "ls", NULL);
    } 
    
    else {
        int ppid = fork();

        if (ppid == 0) {
            execl("/usr/bin/date", "date", NULL);
        }
        else {
            wait(NULL);
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}