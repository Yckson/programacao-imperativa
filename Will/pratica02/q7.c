#include <stdio.h>

void calcularInvestimento(float vInicial, float vMensal, float tempo, float *montante, float *rendimento){

    float vTotal = (float) (vInicial + vMensal * tempo);
    *montante = vTotal;
    *rendimento = vTotal - vInicial;

    return;

}



int main(){

    float investimentoInicial, investimentoMensal, tempoDeInvestimento, valorFinal, rendimento;

    printf("Digite o investimento inicial em (R$): ");
    scanf("%f", &investimentoInicial);

    printf("\nDigite o investmentimento mensal em (R$): ");
    scanf("%f", &investimentoMensal);

    printf("\nDigite o tempo de investimento (em meses): ");
    scanf("%f", &tempoDeInvestimento);

    calcularInvestimento(investimentoInicial, investimentoMensal, tempoDeInvestimento, &valorFinal, &rendimento);

    printf("\n   Valor Final (R$): %.2f \n   Rendimento (R$): %.2f\n", valorFinal, rendimento);



    return 0;
}