#include <stdio.h>

int main(){
    char c; 
    double d;
    short s;

    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(s));

    printf("%p\n", &c);
    printf("%p\n", &d);
    printf("%p\n", &s);
    
    return 0;
}

// I got this output
// 
// 1 
// 8
// 2
// 0x7fff6ad134fd  |   char
// 0x7fff6ad13500  |   double
// 0x7fff6ad134fe  |   short
// 
// 
// 4fd     4fe 4ff     500 501 502 503 504 505 506 507     508 ...
// char    short       double                              everything else 