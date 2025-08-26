/*
Membros:
Cainan Loyola Schiavolin - 15444319
João Pedro Correia Caetano - 16987067
Luís Gustavo Vieira Antoniosi - 17067476
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    _,
    INVERT,
    LINEAR_SEARCH,
    BINARY_SEARCH,
    RECURSIVE_BINARY_SEARCH,
    EXIT
} Options;

void printArray(int *arr, int tam);
int* invertArray(int* arr, int size);
int sequentialSearch(int *arr, int tam, int search);
int iterativeBinarySearch(int *arr, int tam, int search);
int recursiveBinarySearch(int *arr, int size, int search);

int main() {
    unsigned int numElements;
    scanf("%u", &numElements);

    int* arr = (int*) malloc(numElements * sizeof(int));

    for (int i = 0; i < numElements; i++)
        scanf("%d", &arr[i]);
    
    int target = -1, found = -1;
    // Mantém um loop para realizar as ações do usuário
    // Digitar 5 limpa a memória e encerra o programa
    while (1) {
        int option;
        scanf("%d", &option);

        switch (option) {
            case INVERT:
                int* inverted = invertArray(arr, numElements);
                printArray(inverted, numElements);
                break;
            
            case LINEAR_SEARCH:
                scanf("%d", &target);

                found = sequentialSearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case BINARY_SEARCH:
                scanf("%d", &target);

                found = iterativeBinarySearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case RECURSIVE_BINARY_SEARCH:
                scanf("%d", &target);

                found = recursiveBinarySearch(arr, numElements, target);
                printf("%s\n", found != -1 ? "SIM" : "NAO");
                break;

            case EXIT:
                free(arr);
                exit(1);
        }
    }

    return 0;
}

//
// Utilidades
//

// Função que imprime o array
void printArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[size - 1]);
}

// Função que retorna um novo array, contendo os elementos em ordem invertida do array passado por parâmetro
int* invertArray(int* arr, int size) {
    int *inverted = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        inverted[i] = arr[size - i - 1];

    return inverted;
}

//
// Funções de busca
//

// Passa item por item do array em busca do target
int sequentialSearch(int *arr, int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

// Busca binaria iterativa
int iterativeBinarySearch(int *arr, int size, int target) {
    int start = 0;
    int end = size - 1;

    // verifica se o programa já dividiu o suficiente para achar o número
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
            return mid;
        // Se for maior, começa de novo da metade pra baixo
        else if (arr[mid] > target)
            end = mid - 1;
        // se não, da metade pra cima
        else
            start = mid + 1;
    }

    return -1;
}

// Busca binária recursiva; mantemos o padrão de 3 parâmetros por função
int recursiveBinarySearch(int *arr, int size, int target) {
    int end = size - 1; // o final sempre é o tamanho - 1
    int start = 0; // o começo ser sempre igual a 0 se torna um problema com apenas 3 paramêtros (inicialmente)

    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == target) return mid;

    if (arr[mid] > target) {
        // caso o proximo passo seja buscar a metade esquerda, o novo subarray irá de 0 a (mid - 1), portanto tendo tamanho de "mid"
        int idx = recursiveBinarySearch(arr, mid, target);
        return idx;
    }
    // levando em consideração o começo sempre ser 0, atualizamos o array (que nesse caso é considerado o pointer do primeiro elemento), para que possua o endereço do "novo primeiro elemento",
    // o qual será 1 após o meio (mid + 1). portanto, o que era arr[mid + 1] agora será equivalente a arr[0].
    arr = arr + (mid + 1);

    // caso o proximo passo seja buscar a metade direita, o novo subarray irá de mid + 1 ate o final do array, portanto tendo tamanho de "size - (mid + 1)"
    int idx = recursiveBinarySearch(arr, size - (mid + 1), target); 
    int diff = (mid + 1); // diferença causada pela atualização anterior do array no index retornado
    
    if (idx != -1) return idx + diff; // a diferença é adicionada ao index caso o elemento esteja dentro do subarray
    
    return -1;
}