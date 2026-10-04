#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    char **arr;
    arr = (char **)malloc(3 * sizeof(char *));

    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char));
        
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < 3; i++){
        scanf("%s", arr[i]);
    }
    

    char **temp = (char **)realloc(arr, 5 * sizeof(char *));
    if (temp == NULL){
        printf("Memory reallocation failed!\n");
        for(int i = 0; i < 3; i++){
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    arr = temp;
    temp = NULL;

    for (int i = 3; i < 5; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char));
        
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (int i = 0; i < 2; i++){
        scanf("%s", arr[i+3]);
    }

    printf("All strings: ");
    for (int i = 0; i < 5; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}