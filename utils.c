#include <stdio.h>
#include <time.h>
#include "utils.h"

void printArray(int *arr, int size) {
    printf("Array[%d] {", size);
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[size - 1]);
}

int* populateArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = i + 1;

    return arr;
}

// Função que retorna um novo array, contendo os elementos em ordem invertida do array passado por parâmetro
int* invertArray(int* arr, int size) {
    int *inverted = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        inverted[i] = arr[size - i - 1];

    return inverted;
}

double countSearchTime(int (*function)(int*, int, int), int* arr, int size, int search, int iterations) {
    int idx = -1; 

    struct timespec begin;
    timespec_get(&begin, TIME_UTC);

    for (int i = 0; i < iterations; i++)
        idx = function(arr, size, search);

    struct timespec end;

    timespec_get(&end, TIME_UTC);

    double totalTime = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000.0;
    double averageTime = totalTime / iterations;

    return averageTime;
}