#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  

int sum(int *arr, int n){
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int n;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &arr[i]);
    }
    
    int total = sum(arr, n);
    printf("Sum of the array: %d\n", total);
    
    free(arr);
    arr = NULL;

    return 0;
}