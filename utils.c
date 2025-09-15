#include <stdio.h>
#include <stdlib.h>
#include <linux/time.h>
#include "utils.h"


void printArray(int *arr, int size) {
    printf("Array[%d] {", size);
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[size - 1]);
}

void populateArray(int* arr, int size) {
    arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
}

double countSearchTime(int (*function)(int*, int, int), int* arr, int size, int search, int iterations) {
    int idx = -1; 

    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

    for (int i = 0; i < iterations; i++)
        idx = function(arr, size, search);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    double totalTime = (end.tv_nsec - begin.tv_nsec) / 1000.0 + (end.tv_sec  - begin.tv_sec) * 1000000.0;
    printf("%lf ", totalTime);
    double averageTime = totalTime / iterations;

    return averageTime;
}