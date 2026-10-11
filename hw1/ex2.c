#include <stdio.h>

int main() {
    int arr[] = {10,20,30,40,50};
    int *ptr = &arr[0]; 

    for (int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }

    for (int i = 0; i < 5; i++){
        *(ptr + i) = *(ptr + i) * 2;
    }

    printf("\nModified array\n");
    printf("\nWith pointer arithmetic\n");
    for (int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }

    printf("\nWith array name\n");
    for (int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
    
}
