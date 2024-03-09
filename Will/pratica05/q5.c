#include <stdio.h>

int calcFat(int num) {
    if (num < 0) {
        return -1; // Retorna -1 se o número for negativo
    }

    // Caso especial: fatorial de 0 é 1
    if (num == 0) {
        return 1;
    }

    int fatorial = 1;
    for (int cont = 1; cont <= num; cont++) {
        fatorial *= cont;
    }
    return fatorial;
}

int main() {
    int qtdNumeros;

    printf("Digite a quantidade de numeros inteiros e positivos a serem lidos: ");
    scanf("%d", &qtdNumeros);

    for (int i = 0; i < qtdNumeros; i++) {
        int num;
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &num);

        int fatorial = calcFat(num);
        if (fatorial == -1) {
            printf("Numero invalido. Fatorial nao eh definido para numeros negativos.\n");
        } else {
            printf("O fatorial de %d eh: %d\n", num, fatorial);
        }
    }

    return 0;
}
