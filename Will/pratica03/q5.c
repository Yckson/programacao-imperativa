#include <stdio.h>

int verificarDivisibilidade(int num, int denominador){
    return !(num % denominador);
}

int main (){

    int num; int divisor1; int divisor2;
    /* num --> N; divisor1 --> A; divisor2 --> B */

    printf("Insira os valores para o numerador N e para os divisores A e B, respectivamente:\n");
    printf("N: ");
    scanf("%d", &num);
    printf("A: ");
    scanf("%d", &divisor1);
    printf("B: ");
    scanf("%d", &divisor2);

    if (verificarDivisibilidade(num, divisor1) && verificarDivisibilidade(num, divisor2)){
        printf("Atende a condicao!");
    }
    else{
        printf("Nao atende a condicao!");
    }




    return 0;
}