#ifndef UTILS_H
#define UTILS_H

void printArray(int *arr, int size);
int* populateArray(int size);
double countSearchTime(int (*function)(int*, int, int), int* arr, int size, int search, int iterations);
void mergesort(int *vetor, int inicio, int fim);

#endif