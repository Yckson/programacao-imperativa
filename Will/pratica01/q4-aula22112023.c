#include <stdio.h>

int main (){

    float valorEmReais;
    float cambio;

    printf("Digite o valor em reais: ");
    scanf("%f", &valorEmReais);

    /*Correspondente ao valor em reais de um dolar*/
    printf("\nDigite o valor do cambio para dolar: ");
    scanf("%f", &cambio);

    printf("Valor convertido em dolar: $%.2f", valorEmReais/cambio);



    return 0;
}