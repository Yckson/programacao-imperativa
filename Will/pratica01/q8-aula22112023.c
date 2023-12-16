#include <stdio.h>

int main (){
    /*
        A área de um triângula é dada por: (base * altura) / 2

    */

    float base;
    float altura;

    printf("Digite o comprimento do triangulo: ");
    scanf("%f", &altura);

    printf("\nDigite a largura do triangulo: ");
    scanf("%f", &base);

    printf("\nArea do triangulo: %.2f", (base*altura) / 2);


    return 0;
}