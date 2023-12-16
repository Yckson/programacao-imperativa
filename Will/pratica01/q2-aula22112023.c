#include <stdio.h>
#include <math.h>

int main () {

    float pesoIdeal, pesoAtual, perdaMensal;
    printf("Digite o peso que deseja alcancar: ");
    scanf("%f", &pesoIdeal);
    printf("\nDigite o peso atual: ");
    scanf("%f", &pesoAtual);
    printf("Digite o quanto quer perder/ganhar por mes (kg): ");
    scanf("%f", &perdaMensal);

    float deltaPeso = pesoIdeal - pesoAtual;
    float qtdDias = deltaPeso < 0 ? -1 * (deltaPeso / (perdaMensal  / 30)) : (deltaPeso / (perdaMensal  / 30));
    qtdDias = ceilf(qtdDias);
    printf("Voce chegara em seu objetivo em %.2f dias", qtdDias);


    return 0;
}