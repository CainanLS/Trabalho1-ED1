#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10

void contaTempoDeBusca(int (*function)(int*, int, int), char* nomeFuncao, int* vetor, int tam, int procurado);
void printVetor(int *vetor, int tam);
int buscaSequencial(int* vetor, int tam, int procurado);
int buscaBinariaIterativa(int *vetor, int tam, int procurado);

int main() {
    srand(time(NULL));

    int vetor[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11};
    
    printVetor(vetor, TAMANHO);

    contaTempoDeBusca(&buscaSequencial, "busca sequencial", vetor, TAMANHO, 1);
    contaTempoDeBusca(&buscaBinariaIterativa, "busca binaria iterativa", vetor, TAMANHO, 9);

    return 0;
}

//
// Utilidades
//

// uma função que recebe um ponteiro de função e conta quanto tempo ela demorou para ser executada
void contaTempoDeBusca(int (*function)(int*, int, int), char* nomeFuncao, int* vetor, int tam, int procurado) {
    clock_t firstTick = clock();

    int resultado = function(vetor, tam, procurado);

    clock_t lastTick = clock();

    double tempoTotal = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;

    printf("Funcao %s: %d micro segundos", nomeFuncao, (int) (tempoTotal * 1000000));
}

void printVetor(int *vetor, int tam) {
    printf("Vetor: {");
    for (int i = 0; i < tam - 1; i++)
        printf("%d, ", vetor[i]);
    printf("%d}\n", vetor[tam - 1]);
}

//
// Funções de busca
//

int buscaSequencial(int vetor[], int tam, int procurado) {
    for (int i = 0; i < tam; i++)
        if (vetor[i] == procurado)
            return i;

    return -1;
}

int buscaBinariaIterativa(int vetor[], int tam, int procurado) {
    int meio = tam / 2 - 1;
    int ultimoMeio = 0;

    while (ultimoMeio != meio) {
        ultimoMeio = meio;

        if (vetor[meio] == procurado)
            return meio;
        else if (vetor[meio] > procurado) {
            meio = meio / 2;
        }
        else {
            meio = (tam + meio) / 2;
        }
    }

    return -1;
}