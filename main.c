#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

#define NUM_ELEMENTS 4
#define ITERATIONS 1000

// Variáveis globais
int *arr;
int numOfElements[NUM_ELEMENTS] = {50, 100, 1000, 5000};
FILE *output;

void benchmarkBest();
void benchmarkWorst();
void benchmarkRandom();
void benchmarkInverted();
void countOperations();

int main() {
    srand(time(NULL));

    benchmarkRandom();
    benchmarkBest();
    benchmarkWorst();
    benchmarkInverted();
    countOperations();

    free(arr);
    
    return 0;
}

//
// Benchmark
//

void benchmarkRandom() {
    output = fopen("./Results/RandomCase/BenchmarkRandom.csv", "w+");

    printf("Realizandos os testes com casos aleatórios...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");
    
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr = populateArray(numOfElements[i]);

        int randomNumber = arr[rand() % numOfElements[i]];

        fprintf(
            output, 
            "S,%.3lf,%d\n",
            countSearchTime(&sequentialSearch, arr, numOfElements[i], randomNumber, ITERATIONS), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], randomNumber, ITERATIONS),
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], randomNumber, ITERATIONS), 
            numOfElements[i]);
    }

    fclose(output);
}

void benchmarkBest() {
    output = fopen("./Results/BestCase/BenchmarkBestCase.csv", "w+");

    printf("Realizandos os testes com o melhor caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr = populateArray(numOfElements[i]);

        fprintf(
            output, 
            "S,%.3lf,%d\n", 
            countSearchTime(&sequentialSearch, arr, numOfElements[i], 1, ITERATIONS), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], numOfElements[i] / 2, ITERATIONS), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], numOfElements[i] / 2, ITERATIONS), 
            numOfElements[i]
        );
    }

    fclose(output);
}

void benchmarkWorst() {
    output = fopen("./Results/WorstCase/BenchmarkWorstCase.csv", "w+");

    printf("Realizandos os testes com o pior caso caso...\n");
    fprintf(output, "tipo,tempo,qtdElementos\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr = populateArray(numOfElements[i]);

        fprintf(
            output, 
            "S,%.3lf,%d\n", 
            countSearchTime(&sequentialSearch, arr, numOfElements[i], numOfElements[i], ITERATIONS), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "I,%.3lf,%d\n", 
            countSearchTime(&iterativeBinarySearch, arr, numOfElements[i], 1, ITERATIONS), 
            numOfElements[i]
        );

        fprintf(
            output, 
            "R,%.3lf,%d\n", 
            countSearchTime(&recursiveBinarySearch, arr, numOfElements[i], 1, ITERATIONS), 
            numOfElements[i]
        );
    }
    fclose(output);
}

void countOperations() {
    printf("Realizando a contagem de operações...\n");

    output = fopen("./Results/Operations/Operations.csv", "w+");
    if (output == NULL) {
        printf("Erro ao abrir arquivo de operacoes!\n");
    }

    fprintf(output, "elements,invert,sequential,iterative,recursive\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int size = numOfElements[i];

        arr = populateArray(size);

        fprintf(
            output, 
            "%d,%d,%d,%d,%d\n",
            size,
            invertedArray(arr, size, 0),
            sequentialSearch(arr, size, -1),
            iterativeBinarySearch(arr, size, -1),
            recursiveBinarySearch(arr, size, -1)
        );
    }


    fclose(output);
}

void benchmarkInverted() {
    printf("Realizando os testes para a inversão...\n");

    output = fopen("./Results/Inverted/Inverted.csv", "w+");

    if (!output) printf("Erro ao abrir o arquivo de inversão!\n");

    fprintf(output, "tempo,qtdElementos\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr = populateArray(numOfElements[i]);

        fprintf(
            output,
            "%.3lf,%d\n",
            countSearchTime(&invertedArray, arr, numOfElements[i], 1, ITERATIONS),
            numOfElements[i]
        );
    }
}