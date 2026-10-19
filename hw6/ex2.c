#include <stdio.h>

int main(){
    struct {
        char a;
        int b;
        double c;
    } s1;

    printf("Size of s1: %d\n", sizeof(s1));
    printf("%p char\n", &s1.a);
    printf("%p int\n", &s1.b);
    printf("%p double\n\n", &s1.c);

    struct {
        char a;
        double c;
        int b;
    } s2;

    printf("Size of s2: %d\n", sizeof(s2));
    printf("%p char\n", &s2.a);
    printf("%p int\n", &s2.b);
    printf("%p double\n\n", &s2.c);

    struct {
        double c;
        int b;
        char a;
    } s3;

    printf("Size of s3: %d\n", sizeof(s3));
    printf("%p char\n", &s3.a);
    printf("%p int\n", &s3.b);
    printf("%p double\n\n", &s3.c);

    return 0;
}

// struct  order               size        padding
// s1      char, int, double   16 bytes    c***iiii dddddddd
// s2      char, double, int   24 bytes    c******* dddddddd iiii0000 
// s3      double, int, char   16 bytes    dddddddd iiiic***
