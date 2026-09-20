#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func1() {
    printf("cleanup called\n");
}

void func2() {
    printf("shutting down... \n");
}

int main() {
    atexit(func2);
    atexit(func1);
    printf("main function is executing...\n");

    printf("calling exit(0) now...\n");
    exit(0);

    printf("This line will never be executed\n");
    return 0;
}