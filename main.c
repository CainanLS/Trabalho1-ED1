#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "mergesort.h"
#include "utils.h"

int main() {
    srand(time(NULL));
    int *arr;
    int numElements[4] = {10, 100, 1000, 5000};
    unsigned int iterations = 1000;

    FILE *output = fopen("BenchmarkRandom.csv", "w+");

    // Casos aleatórios
    printf("Realizandos os testes com casos aleatórios...\n");
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
    fclose(output);

    output = fopen("BenchmarkWorstCase.csv", "w+");

    // Pior caso
    printf("Realizandos os testes com o pior caso caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");
    for (int i = 0; i < 4; i++) {
        arr = populateArray(numElements[i]);
        mergesort(arr, 0, numElements[i] - 1);

        double avgTime;
        avgTime = countSearchTime(&sequentialSearch, arr, numElements[i], numElements[i], iterations);
        fprintf(output, "S,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&iterativeBinarySearch, arr, numElements[i], 1, iterations);
        fprintf(output, "I,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&recursiveBinarySearch, arr, numElements[i], 1, iterations);
        fprintf(output, "R,%.3lf,%d\n", avgTime, numElements[i]);
    }
    fclose(output);

    output = fopen("BenchmarkBestCase.csv", "w+");

    // Melhor caso
    printf("Realizandos os testes com o melhor caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");
    for (int i = 0; i < 4; i++) {
        arr = populateArray(numElements[i]);
        mergesort(arr, 0, numElements[i] - 1);

        double avgTime;
        avgTime = countSearchTime(&sequentialSearch, arr, numElements[i], 1, iterations);
        fprintf(output, "S,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&iterativeBinarySearch, arr, numElements[i], numElements[i] / 2, iterations);
        fprintf(output, "I,%.3lf,%d\n", avgTime, numElements[i]);
        avgTime = countSearchTime(&recursiveBinarySearch, arr, numElements[i], numElements[i] / 2, iterations);
        fprintf(output, "R,%.3lf,%d\n", avgTime, numElements[i]);
    }
    
    free(arr);
    fclose(output);
    return 0;
}