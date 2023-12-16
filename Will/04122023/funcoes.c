#include <stdio.h>

int quadrado (int num){
    return (num * num);
}

int main(){

    int numero;


    printf("Digite um valor: ");
    scanf("%d", &numero);
    printf("O quadrado do numero e: %d", quadrado(numero));


    return 0;
}