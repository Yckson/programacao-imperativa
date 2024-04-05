#include <stdio.h>

//Demonstração do HeapSort: https://www.cs.usfca.edu/~galles/visualization/HeapSort.html


// Função para trocar dois elementos de posição em um array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para transformar uma subárvore enraizada no nó 'index' em um heap máximo
void heapify(int arr[], int n, int index) {
    int largest = index; // Inicializa o maior como raiz
    int left = 2 * index + 1; // Índice do filho esquerdo
    int right = 2 * index + 2; // Índice do filho direito

    // Se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != index) {
        swap(&arr[index], &arr[largest]);

        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal que implementa o algoritmo Heap Sort
void heapSort(int arr[], int n) {
    // Constrói um heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        swap(&arr[0], &arr[i]);

        // Chama max heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {12, 900, 200, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);
    return 0;
}
