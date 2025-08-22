#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void countSearchTime(int (*function)(int*, int, int), char* funcName, int* arr, int size, int search);
void printArray(int *arr, int tam);
int sequentialSearch(int *arr, int tam, int search);
int iterativeBinarySearch(int *arr, int tam, int search);
int recursiveBinarySearch(int *arr, int size, int search);

int main() {
    srand(time(NULL));

    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11};
    
    printArray(arr, SIZE);

    countSearchTime(&sequentialSearch, "busca sequencial", arr, SIZE, 1);
    countSearchTime(&iterativeBinarySearch, "busca binaria iterativa", arr, SIZE, 9);
    countSearchTime(&recursiveBinarySearch, "Recursive Binary Search", arr, SIZE, 8);

    return 0;
}

//
// Utilidades
//

// uma função que recebe um ponteiro de função e conta quanto tempo ela demorou para ser executada
void countSearchTime(int (*function)(int*, int, int), char* funcName, int* arr, int size, int search) {
    clock_t firstTick = clock();

    int result = function(arr, size, search);

    clock_t lastTick = clock();

    double totalTime = (double) (lastTick - firstTick) / CLOCKS_PER_SEC;

    printf("Funcao %s: %d micro segundos --> index: %d\n", funcName, (int) (totalTime * 1000000), result);
}

void printArray(int *arr, int size) {
    printf("arr: {");
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[size - 1]);
}

//
// Funções de busca
//

int sequentialSearch(int *arr, int size, int search) {
    for (int i = 0; i < size; i++)
        if (arr[i] == search)
            return i;

    return -1;
}

int iterativeBinarySearch(int *arr, int size, int search) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == search)
            return mid;
        else if (arr[mid] > search) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return -1;
}

// busca binária recursiva; mantemos o padrão de 3 parâmetros por função
int recursiveBinarySearch(int *arr, int size, int search) {
    int end = size - 1; // o final sempre é o tamanho - 1
    int start = 0; // o começo ser sempre igual a 0 se torna um problema com apenas 3 paramêtros (inicialmente)

    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == search) return mid;

    if (arr[mid] > search) {
        // o "novo tamanho (size)" é metade do atual
        int idx = recursiveBinarySearch(arr, size / 2, search);
        return idx;
    } else if (arr[mid] < search) {
        // levando em consideração o começo sempre ser 0, atualizamos o array (que nesse caso é considerado o pointer do primeiro elemento), para que possua o endereço do "novo primeiro elemento",
        // o qual será 1 após o meio (mid + 1). portanto, o que era arr[mid + 1] agora será equivalente a arr[0].
        arr = arr + (mid + 1);
        int idx = recursiveBinarySearch(arr, size / 2, search); 
        int diff = (mid + 1); // adicionamos a diferença causada pela atualização anterior do array no index retornado
        return idx + diff;
    }
}
