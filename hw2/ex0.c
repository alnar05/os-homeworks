#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
        fork();
 
        fork();
 
        fork();
 
	    printf("Process PID: %d | Parent PID: %d\n", getpid(), getppid());
		
        while (1);

        return 0; 
} 