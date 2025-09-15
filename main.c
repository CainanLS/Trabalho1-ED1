#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"
#define NUM_ELEMENTS 4

// Variáveis globais
int *arr;
int numOfElements[NUM_ELEMENTS] = {50, 100, 1000, 5000};
unsigned int iterations = 1000;
FILE *output;

void benchmarkBest();
void benchmarkWorst();
void benchmarkRandom();

int main() {
    srand(time(NULL));

    benchmarkRandom();
    benchmarkBest();
    benchmarkWorst();

    free(arr);
    
    return 0;
}

//
// Benchmark
//

void benchmarkRandom() {
    output = fopen("./Results/BenchmarkRandom.csv", "w+");

    printf("Realizandos os testes com casos aleatórios...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");
    
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        populateArray(arr, numOfElements[i]);

        int randomNumber = arr[rand() % numOfElements[i]];

        fprintf(
            output, 
            "S,%.3lf,%d\n",
            countSearchTime(&sequentialSearch, arr, numOfElements[i], randomNumber, iterations), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], randomNumber, iterations),
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], randomNumber, iterations), 
            numOfElements[i]);
    }

    fclose(output);
}

void benchmarkBest() {
    output = fopen("./Results/BenchmarkBestCase.csv", "w+");

    printf("Realizandos os testes com o melhor caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        populateArray(arr, numOfElements[i]);

        fprintf(
            output, 
            "S,%.3lf,%d\n", 
            countSearchTime(&sequentialSearch, arr, numOfElements[i], 1, iterations), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], numOfElements[i] / 2, iterations), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], numOfElements[i] / 2, iterations), 
            numOfElements[i]
        );
    }

    fclose(output);
}

void benchmarkWorst() {
    output = fopen("./Results/BenchmarkWorstCase.csv", "w+");

    printf("Realizandos os testes com o pior caso caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        populateArray(arr, numOfElements[i]);

        fprintf(
            output, 
            "S,%.3lf,%d\n", 
            countSearchTime(&sequentialSearch, arr, numOfElements[i], numOfElements[i], iterations), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], 1, iterations), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], 1, iterations), 
            numOfElements[i]
        );
    }
    fclose(output);
}