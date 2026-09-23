#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int value = 5;
    int result = square(value);
    printf("The square of %d is: %d\n", value, result);
    
    return 0;
}