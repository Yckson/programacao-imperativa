#include <stdio.h>

const float PRECO_PASSAGEM = 22.00;

float calcMedia(float total, int qtd){
    return total / qtd;
}

float montanteRecebido(float passagensVendidas, float precoPassagem){
    return passagensVendidas * precoPassagem;
}


int main(){
    int Horas, NumPassageiros, MaisPassageiros, MelhorHorario, menosPassageiros, piorHorario, totalPassageiros;
    MaisPassageiros = 0;
    totalPassageiros = 0;

    for (Horas=8; Horas<=18; Horas++){
        printf("Numero de passageiras das %d horas: ", Horas);
        scanf("%d",&NumPassageiros);

        totalPassageiros += NumPassageiros;

        if (Horas == 8){
            menosPassageiros = NumPassageiros;
            piorHorario = Horas;
        }

        if (NumPassageiros > MaisPassageiros){
            MelhorHorario = Horas;
            MaisPassageiros = NumPassageiros;
        }
        
        if (NumPassageiros < menosPassageiros){
            piorHorario = Horas;
            menosPassageiros = NumPassageiros;
        }
    }

    printf("Horario de maior procura: %dhrs.\n", MelhorHorario);
    printf("Horario de menos procura: %dhrs.\n", piorHorario);
    printf("Media de passageiros no dia: %.2f.\n", calcMedia(totalPassageiros, 11));
    printf("Total de passageiros no dia: %d. \n", totalPassageiros);
    printf("Montante gerado: R$%.2f.", montanteRecebido(totalPassageiros, PRECO_PASSAGEM));


    return 0;
}