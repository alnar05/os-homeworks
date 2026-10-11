#include <stdio.h>

int main() {
    int a = 10;
    int *ptr = &a; 
    
    printf("Address using &a:  %p\n", &a);
    printf("Address using ptr: %p\n", ptr);
    
    *ptr = 20;
    
    printf("New value of a: %d\n", a);
    
}
