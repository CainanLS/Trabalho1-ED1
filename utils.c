#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
    LARGE_INTEGER tcounter;
    LONGLONG freq, first_tick, last_tick;
#else
    #include <string.h>
    struct timespec begin, end;
    long seconds = 0, nanoseconds = 0;
#endif


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

    #ifdef _WIN32
        if (QueryPerformanceFrequency(&tcounter) != 0)
            freq = tcounter.QuadPart;
        
        if (QueryPerformanceCounter(&tcounter) != 0)
            first_tick = tcounter.QuadPart;
    #else
        clock_gettime(CLOCK_MONOTONIC, &begin);
    #endif

    for (int i = 0; i < iterations; i++)
        idx = function(arr, size, search);

    #ifdef _WIN32
        if (QueryPerformanceCounter(&tcounter) != 0)
            last_tick = tcounter.QuadPart;
        
        double totalTime = (last_tick - first_tick) / (freq / 1000000000.0);
        double averageTime = totalTime / iterations;

        return averageTime;    
    #else
        clock_gettime(CLOCK_MONOTONIC, &end);
        seconds = end.tv_sec - begin.tv_sec;
        nanoseconds = end.tv_nsec - begin.tv_nsec;

        if (nanoseconds < 0) {
            seconds -= 1;
            nanoseconds += 1000000000;
        }

        double totalTime = (double) nanoseconds / iterations;

        return totalTime;
    #endif
}