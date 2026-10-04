#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int max (int *arr, int n){
    int highest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > highest) highest = arr[i];
    }
    return highest;
}

int min (int *arr, int n){
    int lowest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < lowest) lowest = arr[i];
    }
    return lowest;
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter the grades: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int highest = max(arr, n);
    int lowest = min(arr, n);

    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);

    free(arr);
    arr = NULL;

    return 0;
}