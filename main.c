#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearch.h"
#include "mergesort.h"

typedef enum {
    _,
    INVERT,
    LINEAR_SEARCH,
    BINARY_SEARCH,
    RECURSIVE_BINARY_SEARCH,
    EXIT
} Options;

void printArray(int *arr, int size) {
    printf("Array[%d] {", size);
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[size - 1]);
}

// Função que retorna um novo array, contendo os elementos em ordem invertida do array passado por parâmetro
int* invertArray(int* arr, int size) {
    int *inverted = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        inverted[i] = arr[size - i - 1];

    return inverted;
}

void countSearchTime(int (*function)(int*, int, int), char* funcName, int* arr, int size, int search, int iterations) {
    clock_t firstTick = clock();

    int output;
    for (int i = 0; i < iterations; i++)
        output = function(arr, size, search);

    clock_t lastTick = clock();

    double totalTime = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;

    printf("Funcao: %s | Tempo: %lfs (%d iteracoes) | Resultado: %s (target -> %d)\n", funcName, totalTime, iterations, output != -1 ? "SIM" : "NAO", output);
}

int* populateArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;

    return arr;
}

int main() {
    srand(time(NULL));

    unsigned int numElements = 10000;

    int* arr = populateArray(numElements);
    mergesort(arr, 0, numElements - 1);

    countSearchTime(&sequentialSearch, "Busca sequencial", arr, numElements, arr[rand() % numElements], 100);
    countSearchTime(&iterativeBinarySearch, "Busca binaria iterativa", arr, numElements, arr[rand() % numElements], 100);
    countSearchTime(&recursiveBinarySearch, "Busca binaria recursiva", arr, numElements, arr[rand() % numElements], 100);

    return 0;
}