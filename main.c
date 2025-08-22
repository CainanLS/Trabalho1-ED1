#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearch.h"

typedef enum {
    _,
    INVERT,
    LINEAR_SEARCH,
    BINARY_SEARCH,
    RECURSIVE_BINARY_SEARCH,
    EXIT
} Options;

void printArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[size - 1]);
}

// Função que retorna um novo array, contendo os elementos em ordem invertida do array passado por parâmetro
int* invertArray(int* arr, int size) {
    int *inverted = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        inverted[i] = arr[size - i - 1];

    return inverted;
}


int* invertArray(int* arr, int size);

int main() {
    srand(time(NULL));

    unsigned int numElements;
    scanf("%u", &numElements);

    int* arr = (int*) malloc(numElements * sizeof(int));

    for (int i = 0; i < numElements; i++)
        scanf("%d", &arr[i]);
    
    int target, found;
    while (1) {
        int option;
        scanf("%d", &option);

        switch (option) {
            case INVERT:
                int* inverted = invertArray(arr, numElements);
                printArray(inverted, numElements);
                break;
            
            case LINEAR_SEARCH:
                scanf("%d", &target);

                found = sequentialSearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case BINARY_SEARCH:
                scanf("%d", &target);

                found = iterativeBinarySearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case RECURSIVE_BINARY_SEARCH:
                scanf("%d", &target);

                found = recursiveBinarySearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case EXIT:
                free(arr);
                exit(1);
        }
    }

    return 0;
}