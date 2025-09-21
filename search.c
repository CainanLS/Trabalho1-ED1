#include <stdio.h>
#include "search.h"

int operations;

/*
Fizemos algumas alterações para que a busca retorne o numero de operações feitas,
já que não precisamos da resposta caso ele tenha encontrado ou não
*/

// Passa item por item do array em busca do target
int sequentialSearch(int *arr, int size, int target) {
    operations = 0;

    for (int i = 0; i < size; i++) {
        operations++;
        if (arr[i] == target) break;
    }

    return operations;
}

// Busca binaria iterativa
int iterativeBinarySearch(int *arr, int size, int target) {
    operations = 2;

    int start = 0;
    int end = size - 1;

    // verifica se o programa já dividiu o suficiente para achar o número
    while (start <= end) {
        operations += 2;
        int mid = (start + end) / 2;

        if (arr[mid] == target)
            break;
        // Se for maior, começa de novo da metade pra baixo
        else if (arr[mid] > target) {
            operations++;
            end = mid - 1;
        }
        // se não, da metade pra cima
        else {
            operations++;
            start = mid + 1;
        }
    }

    return operations;
}

// Busca binária recursiva; mantemos o padrão de 3 parâmetros por função
int recursiveBinarySearch(int *arr, int size, int target) {
    operations = 2;
    int end = size - 1; // o final sempre é o tamanho - 1
    int start = 0; // o começo ser sempre igual a 0 se torna um problema com apenas 3 paramêtros (inicialmente)

    operations++;
    if (start > end) return -1;

    operations++;
    int mid = (start + end) / 2;

    operations++;
    if (arr[mid] == target) return mid;

    if (arr[mid] > target) {
        // caso o proximo passo seja buscar a metade esquerda, o novo subarray irá de 0 a (mid - 1), portanto tendo tamanho de "mid"
        operations += recursiveBinarySearch(arr, mid, target);
        return operations;
    }
    // levando em consideração o começo sempre ser 0, atualizamos o array (que nesse caso é considerado o pointer do primeiro elemento), para que possua o endereço do "novo primeiro elemento",
    // o qual será 1 após o meio (mid + 1). portanto, o que era arr[mid + 1] agora será equivalente a arr[0].
    operations++;
    arr = arr + (mid + 1);

    // caso o proximo passo seja buscar a metade direita, o novo subarray irá de mid + 1 ate o final do array, portanto tendo tamanho de "size - (mid + 1)"
    operations += recursiveBinarySearch(arr, size - (mid + 1), target); 
    operations++;
    int diff = (mid + 1); // diferença causada pela atualização anterior do array no index retornado
    
    return operations;
}