#include <stdio.h>

float converterMoeda(float valor, float cambio){
    return valor * cambio;
}

void paraDolareEuro(float valor, float cambioEuro, float cambioDolar, float *valorDolar, float *valorEuro){
    
    *valorDolar = converterMoeda(valor, cambioDolar);
    *valorEuro = converterMoeda(valor, cambioEuro);
}

int main (){

    float valorEmReais, cambioParaDolar, cambioParaEuro, valorEmDolar, valorEmEuro;

    printf("Digite o valor (em R$): ");
    scanf("%f", &valorEmReais);

    printf("\nDigite o cambio de Reais para Dolar: ");
    scanf("%f", &cambioParaDolar);

    printf("\nDigite o cambio de Reais para Euro: ");
    scanf("%f", &cambioParaEuro);

    paraDolareEuro(valorEmReais, cambioParaEuro, cambioParaDolar, &valorEmDolar, &valorEmEuro);

    printf("\nValor em Dolar: %.2f\nValor em Euro: %.2f\n", valorEmDolar, valorEmEuro);


    return 0;
}