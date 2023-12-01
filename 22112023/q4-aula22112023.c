#include <stdio.h>

int main (){

    float valorEmReais;
    float cambio;

    printf("Digite o valor em reais: ");
    scanf("%f", &valorEmReais);

    printf("\nDigite o valor do cambio para dolar: ");
    scanf("%f", &cambio);

    printf("Valor convertido em dolar: $%.2f", valorEmReais/cambio);



    return 0;
}