#include <stdio.h>

int main() {
    char str[] = "Hello";
    char *ptr = str;

    for (int i = 0; i < 5; i++){
        printf("%c", *(ptr + i));
    }

    int count = 0;

    while (*(ptr + count) != '\0') {
        count++;
    }

    printf("\n%d\n", count);
    
    return 0;
    
}
