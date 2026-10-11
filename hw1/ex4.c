#include <stdio.h>

int main() {
    int a = 10;
    int *ptr = &a;
    int **pptr = &ptr;

    printf("a = %d \n", *ptr);
    
    printf("a = %d \n", **pptr);
    
    return 0;
    
}
