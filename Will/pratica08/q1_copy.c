


#include <stdio.h>
#include <stdlib.h>

float M[4][6] = {
    {385, 534, 309, 546, 503, 477},
    {12, 121, 12, 3, 24, 12},
    {35.9, 72.1, 46.2, 74.3, 78, 90},
    {-28, -18, -18, -18, -22, -18}
};

char Freezers[6][10] = {"Deia", "Sul", "NSul", "Frio", "Fri", "Lux"};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6], int L, int C) {
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        for (int j = 0; j < C; j++)
            printf("%6.1f", Matriz[i][j]);
        printf("\n");
    }
}

void ExibeColuna(float Matriz[][6], int L, int C) {
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        printf("%6.1f\n", Matriz[i][C]);
    }
}

void ExibeLinha(float Matriz[][6], int L, int C) {
    printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < C; i++)
        printf("%.1f ", Matriz[L][i]);
    printf("\n");
}

void SelecionaFreezer(float Matriz[][6], int *F) {
    printf("Selecione o freezer desejado:\n");
    printf("1 - Deia\n");
    printf("2 - Sul\n");
    printf("3 - NSul\n");
    printf("4 - Frio\n");
    printf("5 - Fri\n");
    printf("6 - Lux\n\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *F = Op - 1;
}

void SelecionaCaracteristica(float Matriz[][6], int *C) {
    system("cls");
    printf("Caracteristica desejado\n");
    printf("1 - Capacidade (litros)\n");
    printf("2 - Garantia (meses)\n");
    printf("3 - Economia(kWh/mes)\n");
    printf("4 - Temperatura Minima (Celsius)\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *C = Op - 1;
}

void AlteraDado(float Matriz[][6], int F, int C) {
    printf("Digite o novo valor: ");
    float NovoValor = 0;
    scanf("%f", &NovoValor);
    Matriz[F][C] = NovoValor;
    printf("Dado alterado com sucesso!\n");
}

void AlteraFreezer() {

    
    int freezer = 0, caracteristica = 0;
    printf("Selecione o freezer desejado (1-6): ");

    ExibeLinha(M, 0, 0);
    scanf("%d", &freezer);
    if (freezer < 1 || freezer > 6) {
        printf("Erro: Valor invalido. Selecione um valor entre 1 e 6.\n");
        return;
    }


    printf("Selecione a caracteristica desejada (1-4): ");
    scanf("%d", &caracteristica);
    if (caracteristica < 1 || caracteristica > 4) {
        printf("Erro: Valor invalido. Selecione um valor entre 1 e 4.\n");
        return;
    }
    
    AlteraDado(M, freezer - 1, caracteristica - 1);

}

char* MelhorFreezerCapacidade(float Matriz[][6]) {
    float maiorCapacidade = Matriz[0][0];
    int freezer = 0;

    for (int i = 1; i < 6; i++) {
        if (Matriz[0][i] > maiorCapacidade) {
            maiorCapacidade = Matriz[0][i];
            freezer = i;
        }
    }

    return Freezers[freezer];
}

char* MelhorFreezerGarantia(float Matriz[][6]) {
    float maiorGarantia = Matriz[1][0];
    int freezer = 0;

    for (int i = 1; i < 6; i++) {
        if (Matriz[1][i] > maiorGarantia) {
            maiorGarantia = Matriz[1][i];
            freezer = i;
        }
    }

    return Freezers[freezer];
}

char* MelhorFreezerEconomia(float Matriz[][6]) {
    float maiorEconomia = Matriz[2][0];
    int freezer = 0;

    for (int i = 1; i < 6; i++) {
        if (Matriz[2][i] < maiorEconomia) {
            maiorEconomia = Matriz[2][i];
            freezer = i;
        }
    }

    return Freezers[freezer];
}

char* MelhorFreezerTemperatura(float Matriz[][6]) {
    float menorTemperatura = Matriz[3][0];
    int freezer = 0;

    for (int i = 1; i < 6; i++) {
        if (Matriz[3][i] < menorTemperatura) {
            menorTemperatura = Matriz[3][i];
            freezer = i;
        }
    }

    return Freezers[freezer];
}


int main() {
    do {
        system("cls");
        printf(">>> Pesquisa Freezer <<<\n\n");
        printf("Selecione a opcao desejada:\n");
        printf("1 - Exibir Levantamento\n");
        printf("2 - Dados de um Freezer\n");
        printf("3 - Dados de uma Caracteristica\n");
        printf("4 - Alterar Dado\n");
        printf("5 - Melhor Freezer em Capacidade\n");
        printf("6 - Melhor Freezer em Garantia\n");
        printf("7 - Melhor Freezer em Economia\n");
        printf("8 - Melhor Freezer em Temperatura\n");
        printf("9 - Sair\n");
        int Op;
        scanf("%d", &Op);
        switch (Op) {
            case 1:
                ExibeMatriz(M, 4, 6);
                system("pause");
                break;
            case 2:
                SelecionaFreezer(M, &Frz);
                ExibeColuna(M, 4, Frz);
                system("pause");
                break;
            case 3:
                SelecionaCaracteristica(M, &Crc);
                ExibeLinha(M, Crc, 6);
                system("pause");
                break;
            case 4:
                printf("\n_Altera Dado_\n");
                AlteraFreezer(M);
                system("pause");
                break;
            case 5:
                printf("\n_Melhor Freezer em Capacidade_\n");
                printf("O freezer com maior capacidade eh o %s\n", MelhorFreezerCapacidade(M));
                system("pause");
                break;
            case 6:
                printf("\n_Melhor Freezer em Garantia_\n");
                printf("O freezer com melhor garantia eh o %s\n", MelhorFreezerGarantia(M));
                system("pause");
                break;
            case 7:  
                printf("\n_Melhor Freezer em Economia_\n");
                printf("O freezer com melhor economia eh o %s\n", MelhorFreezerEconomia(M));
                system("pause");
                break;
            case 8: 
                printf("\n_Melhor Freezer em Temperatura_\n");
                printf("O freezer com melhor temperatura eh o %s\n", MelhorFreezerTemperatura(M));
                system("pause");
                break;
            case 9: 
                break;
      }

      if (Op==9) break;
    
    } while (1);

  return 0;
}

