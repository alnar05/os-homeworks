#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

float average(int *arr, int n){
    if (n == 0) return 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
    } 
    
    return (float)sum / n;
}

int main()
{
    int n; 
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array after calloc: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nEnter %d integers: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    float averaged_array = average(arr, n);
    printf("\nAverage of the array: %f\n", averaged_array);

    free(arr);
    arr = NULL;
    
    return 0;
}