#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    int n = 10; 
    int new_size = 5;
    int *arr;

    arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);    
    }

    int *temp = (int *)realloc(arr, new_size * sizeof(int));

    if (temp == NULL){
        printf("Memory reallocation failed!\n");
        free(arr);
        return 1;
    }
    
    arr = temp;
    temp = NULL;

    printf("Array after resizing: ");
    for (int i = 0; i < new_size; i++){
        printf("%d ", arr[i]);    
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}