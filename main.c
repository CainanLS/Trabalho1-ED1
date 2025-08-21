#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// uma função que recebe um ponteiro de função e conta quanto tempo ela demorou para ser executada
void contaTempoDeBusca(int (*function)(int*, int, int), int* vetor, int tam, int procurado) {
    clock_t firstTick = clock();

    int resultado = function(vetor, tam, procurado);

    clock_t lastTick = clock();

    double tempoTotal = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %d micro segundos", (int) (tempoTotal * 1000000));
}

void printVetor(int *vetor, int tam) {
    printf("Vetor: {");
    for (int i = 0; i < tam - 1; i++)
        printf("%d, ", vetor[i]);
    printf("%d}\n", vetor[tam - 1]);
}

int buscaSequencial(int* vetor, int tam, int procurado) {
    for (int i = 0; i < tam; i++)
        if (vetor[i] == procurado)
            return i;

    return -1;
}

int main() {
    srand(time(NULL));

    int vetor[1000];

    for (int i = 0; i < 1000; i++)
        vetor[i] = rand() % 1000;

    printVetor(vetor, 1000);

    contaTempoDeBusca(&buscaSequencial, vetor, 1000, 1);

    return 0;
}