#include <stdio.h>
#include "mergesort.h"

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