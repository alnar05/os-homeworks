#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int * my_realloc(int *arr, int old_size, int new_size){
    int *new_arr = (int *)malloc(new_size);

    if (new_arr == NULL) return NULL;

    if (arr != NULL){
        int size = (old_size < new_size) ? old_size : new_size;
        
        memcpy(new_arr, arr, size);

        free(arr);
    }

    return new_arr;
}

int main()
{
    int old_size = 5;
    int new_size = 3;

    int *arr = (int *)malloc(old_size * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < old_size; i++) {
        arr[i] = i + 1;
    }

    int *temp = my_realloc(arr, old_size * sizeof(int), new_size * sizeof(int));
    if (temp == NULL){
        printf("Memory reallocation failed!\n");
        free(arr);
        return 1;
    }

    arr = temp;
    temp = NULL;

    for (int i = 0; i < new_size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    arr = NULL;

    return 0;
}