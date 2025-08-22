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

void countSearchTime(int (*function)(int*, int, int), char* funcName, int* arr, int size, int search) {
    clock_t firstTick = clock();

    function(arr, size, search);

    clock_t lastTick = clock();

    double totalTime = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;

    printf("Funcao %s: %ds", funcName, totalTime);
}


int* invertArray(int* arr, int size);

int main() {
    srand(time(NULL));

    unsigned int numElements = 10;

    int* arr = (int*) malloc(numElements * sizeof(int));

    return 0;
}