#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14];
float Valor;
char Responsavel[21];
int Iniciou = 0;
const int QTD_HRS_FUNCIONAMENTO = 15;
int qtdCarrosPorHora[15];
float lucroTotal = 0;


void AbrirCaixa() {
    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n ABRINDO CAIXA \n");
    for (int i = 0; i < 30; i++) {
        strcpy(Estaciona[i], "LIVRE");
    }
    printf("\nQual o valor do estacionamento? ");
    scanf("%f", &Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    gets(Responsavel);
    Iniciou = 1;
}

void mostrarVagasDisp(){
    printf("\nTabela de Vagas\n");
    printf("Vaga\tStatus\n");
    printf("----------------\n");
        for (int i = 0; i < 30; i++) {
            printf("%d\t%s\n", i + 1, Estaciona[i]);
    }
    printf("\n");
}  

void ClienteChega() {
    
    int Vaga;
    char Placa[8] = "", Hora[5] = "", Entrada[14] = "";
    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n CHEGADA DE CLIENTE \n");
    if (Iniciou) {
        printf("\n CAIXA ABERTO Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        mostrarVagasDisp();
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin);

        if (strcmp(Estaciona[Vaga - 1], "LIVRE") != 0) {
            printf("\nERRO: Vaga ocupada!\n");
            system("pause");
            return;
        }

        printf("Qual a placa do veiculo [7 digitos]? ");
        gets(Placa);
        strcpy(Entrada, Placa);
        fflush(stdin);
        printf("Qual a hora de entrada [formato nn:nn]? ");
        gets(Hora);
        strcat(Entrada, "+");
        strcat(Entrada, Hora);
        strcpy(Estaciona[Vaga - 1], Entrada);
        printf("Chegada registrada com sucesso!\n");
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    // Atualizar o array qtdCarrosPorHora
    int horaChegada = atoi(Hora);
    if (horaChegada >= 6 && horaChegada <= 20) {
        qtdCarrosPorHora[horaChegada - 6]++;
    }
    system("pause");
}

void ClienteSai() {
    int Vaga;
    char Placa[8]= "", Entrada[14]="", Hora[3]="", Min[3]="";
    int H, M; //hora, minuto e segundo
    float ValorPagar, ValorPago, Troco;

    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n SAIDA DE CLIENTE \n");

    if (Iniciou) {
        printf("\n CAIXA ABERTO Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        mostrarVagasDisp();
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        
        if (strcmp(Estaciona[Vaga - 1], "LIVRE") == 0) {
            printf("\nERRO: Vaga vazia!\n");
            system("pause");
            return;
        }

        strcpy(Entrada, Estaciona[Vaga - 1]);
        printf("\n>>>>>>>%s", Entrada);
        for (int i = 0; i < 7; i++) {
            Placa[i] = toupper(Entrada[i]);
        }

        printf("\n>>>>>>>Placa: %s\n", Placa);
        Hora[0] = Entrada[8];
        Hora[1] = Entrada[9];
        Hora[2] = '\0';
        H = atoi(Hora); // convete string em inteiro
        Min[0] = Entrada[11];
        Min[1] = Entrada[12];
        Min[2] = '\0';
        M = atoi(Min); // convete string em inteiro


        // Cálculo do tempo estacionado
        int horaSaida, minSaida;
        printf("Qual a hora de saida [formato HH:MM]? ");
        scanf("%d:%d", &horaSaida, &minSaida);

        int tempoEstacionado = ((horaSaida - H) * 60) + (minSaida - M);

        printf("\n>>>>>>>Hora: %d", horaSaida - H);
        printf("\n>>>>>>>Minutos: %d\n", minSaida - M);

        // Cálculo do valor a pagar
        ValorPagar = (tempoEstacionado / 60.0) * Valor;

        printf("\nValor a pagar: R$%.2f", ValorPagar);

        // Leitura do valor pago
        printf("\nQual o valor pago? ");
        scanf("%f", &ValorPago);

        // Cálculo do troco
        Troco = ValorPago - ValorPagar;
        lucroTotal += ValorPagar;

        printf("Troco: R$%.2f\n", Troco);

        // Remover o carro do estacionamento e registrar a vaga como livre
        strcpy(Estaciona[Vaga - 1], "LIVRE");
        printf("Saida registrada com sucesso!\n");
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause");
}

int FecharCaixa() {
    if(!Iniciou){
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
        return 1;
    }
    int carrosEstacionados = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(Estaciona[i], "LIVRE") != 0) {
            carrosEstacionados++;
        }
    }

    if (carrosEstacionados > 0) {
        printf("\nAVISO: Existem carros estacionados no momento!\n");
        return 1;
    }

    
    printf("\nQuantitativo de carros por hora:\n");
    printf("Hora   |   Quantidade de Carros\n");
    printf("-----------------------------\n");
    for (int i = 0; i < QTD_HRS_FUNCIONAMENTO - 1; i++) {
        printf("%2d:00   |   %d\n", i + 6, qtdCarrosPorHora[i]);
    }
    
    int maxEntradas = 0;
    int horaMaxEntradas = 0;
    float somaValores = 0;

    for (int i = 0; i < QTD_HRS_FUNCIONAMENTO - 1; i++) {
        if (qtdCarrosPorHora[i] > maxEntradas) {
            maxEntradas = qtdCarrosPorHora[i];
            horaMaxEntradas = i + 6;
        }
    }

    printf("\nHorario com maior numero de entradas: %02d:00", horaMaxEntradas);
    printf("\nSoma dos valores recebidos ao longo do dia: R$%.2f\n", lucroTotal);
    return 0;
}

int main() {
    int Op;
    do {
        system("cls");
        system("color 80"); // 8 - cinza 0 - preto
        printf("\n >>> Estacionamento <<< \n");
        printf(" >>> Largas Vagas <<< \n");
        printf("\n 1 - Abrir Caixa");
        printf("\n 2 - Chegada de Cliente");
        printf("\n 3 - Saida de Cliente");
        printf("\n 4 - Fechar Caixa");
        printf("\n\n Qual a opcao desejada? ");
        do {
            scanf("%d", &Op);
            if ((Op < 1) || (Op > 4)) {
                printf("\n ERRO: Opcao invalida!");
                printf("\n Qual a opcao desejada? ");
            } else {
                break;
            }
        } while (1);

        switch (Op) {
            case 1:
                AbrirCaixa();
                break;
            case 2:
                ClienteChega();
                break;
            case 3:
                ClienteSai();
                break;
            case 4:
                if(FecharCaixa()){
                    Op = 5;
                }
                system("pause");
                break;
        }
    } while (Op != 4);
    return 0;
}

