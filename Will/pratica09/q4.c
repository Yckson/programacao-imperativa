#include <stdio.h>
#include <string.h>

// Função para trocar dois elementos de posição em um array
void trocar(char* a, char* b) {
    char temp[25];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Função para transformar uma subárvore enraizada no nó 'index' em um heap máximo
void heapify(char arr[][25], int n, int index) {
    int maior = index; // Inicializa o maior como raiz
    int esquerda = 2 * index + 1; // Índice do filho esquerdo
    int direita = 2 * index + 2; // Índice do filho direito

    // Se o filho esquerdo é maior que a raiz
    if (esquerda < n && strcmp(arr[esquerda], arr[maior]) > 0)
        maior = esquerda;

    // Se o filho direito é maior que o maior até agora
    if (direita < n && strcmp(arr[direita], arr[maior]) > 0)
        maior = direita;

    // Se o maior não é a raiz
    if (maior != index) {
        trocar(arr[index], arr[maior]);

        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal que implementa o algoritmo Heap Sort
void heapSort(char arr[][25], int n) {
    // Constrói um heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        trocar(arr[0], arr[i]);

        // Chama max heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void imprimirArray(char arr[][25], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    char arr[][25] = {"banana", "abacaxi", "laranja", "uva", "manga", "abacate"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado:\n");
    imprimirArray(arr, n);
    return 0;
}


