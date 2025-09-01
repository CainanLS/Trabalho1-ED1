#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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

double countSearchTime(int (*function)(int*, int, int), int* arr, int size, int search, int iterations) {
    int idx = -1; 

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    for (int i = 0; i < iterations; i++)
        idx = function(arr, size, search);

    gettimeofday(&tv2, NULL);

    double totalTime = (tv2.tv_usec - tv1.tv_usec) + 1000000 * (tv2.tv_sec - tv1.tv_sec);
    printf("%lf", totalTime);
    double averageTime = totalTime / iterations;

    return averageTime;
}

//
// Merge Sort implementation
//

void merge(int *vet, int inicio, int meio, int fim) {
    int tamEsq = meio - inicio + 1; // inicio <= x < meio
    int tamDir = fim - meio; // meio <= x < fim
    int vetEsq[tamEsq], vetDir[tamDir];

    // Inicializa os subvetores com os valores do vetor que queremos mesclar
    for (int i = 0; i < tamEsq; i++)
        vetEsq[i] = vet[i + inicio];
    for (int i = 0; i < tamDir; i++)
        vetDir[i] = vet[i + meio + 1];

    
    // mantem dois indices, e vai passando por cada subvetor individualmente, comparando seus valores
    int index = inicio, indexEsq = 0, indexDir = 0;
    while (indexEsq < tamEsq && indexDir < tamDir) {
        if (vetEsq[indexEsq] <= vetDir[indexDir]) {
            vet[index] = vetEsq[indexEsq];
            indexEsq++;
        }
        else {
            vet[index] = vetDir[indexDir];
            indexDir++;
        }

        index++;
    }

    // se os dois vetores tiverem um valor diferente, um deles vai sobrar
    // essa parte garante que ele vai colocar o resto no vetor
    while (indexEsq < tamEsq)
        vet[index++] = vetEsq[indexEsq++];

    while (indexDir < tamDir)
        vet[index++] = vetDir[indexDir++];
}

void mergesort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}