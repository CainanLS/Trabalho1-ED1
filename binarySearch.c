#include<stdio.h>
#include"binarySearch.h"

int sequentialSearch(int *arr, int size, int search) {
    for (int i = 0; i < size; i++)
        if (arr[i] == search)
            return i;

    return -1;
}

int iterativeBinarySearch(int *arr, int size, int search) {
    int start = 0;
    int end = size - 1;

    // verifica se o programa já dividiu o suficiente para achar o número
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == search)
            return mid;
        else if (arr[mid] > search)
            end = mid - 1;
        else
            start = mid + 1;
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