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

double countSearchTime(int (*function)(int*, int, int), int* arr, int size, int search, int iterations) {
    clock_t firstTick = clock();

    int output;
    for (int i = 0; i < iterations; i++)
        output = function(arr, size, search);

    clock_t lastTick = clock();

    double totalTime = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;
    double averageTime = totalTime * 1000000 / iterations;

    return averageTime;
}

int* populateArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;

    return arr;
}

int main() {
    srand(time(NULL));
    int* arr;
    FILE *output = fopen("benchmark.csv", "w+");

    int numElements[4] = {10, 100, 1000, 5000};
    unsigned int iterations = 100;

    fprintf(output, "tipo,tempo,qtdElementos\n");
    for (int i = 0; i < 4; i++) {
        arr = populateArray(numElements[i]);
        mergesort(arr, 0, numElements[i] - 1);
        int randomNumber = arr[rand() % numElements[i]];

        double avgTime;
        avgTime = countSearchTime(&sequentialSearch, arr, numElements[i], randomNumber, iterations);
        fprintf(output, "S,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&iterativeBinarySearch, arr, numElements[i], randomNumber, iterations);
        fprintf(output, "I,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&recursiveBinarySearch, arr, numElements[i], randomNumber, iterations);
        fprintf(output, "R,%.3lf,%d\n", avgTime, numElements[i]);
    }
    
    free(arr);
    fclose(output);
    return 0;
}