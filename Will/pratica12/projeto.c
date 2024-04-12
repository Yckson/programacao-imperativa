#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//SOFTWARE DA OFICINA DA "ZONDA"
//preciso implementar uma maneira de conseguir registrar várias motos com a mesma placa

typedef struct Servico Servico;
typedef struct Registro Registro;
typedef struct Rendimento Rendimento;


FILE *REGISTRO_PRINCIPAL;
FILE *RENDIMENTO;
char nomeBancoDeDados[50];

const int QTD_MAX_SOLICITACOES = 50;
const int USAR_DATA_SISTEMA = 0;

int qtdServicos = -1;


struct Servico {
    char nomeCliente[31];
    char modeloMoto[21];
    char placaMoto[9]; // BRA-1234
    char descricaoDefeito[101];
    int status; // 0 - Pendente, 1 - Em andamento, 2 - Cancelado, 3 - Concluído;
    float preco;

};

struct Registro {
    int qtdServicosAbertos;
    Servico servicos[50];
};

struct Rendimento {
    char data[11];
    float totalRendimento;
};

void pegarData(char data[]){
    char dataAtual[11];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char dia[3], mes[3], ano[5];
    sprintf(dia, "%d", tm.tm_mday);
    sprintf(mes, "%d", tm.tm_mon + 1);
    sprintf(ano, "%d", tm.tm_year + 1900);
    if (tm.tm_mday < 10){
        dia[1] = dia[0];
        dia[0] = '0';
    }
    if (tm.tm_mon + 1 < 10){
        mes[1] = mes[0];
        mes[0] = '0';
    }
    strcpy(data, dia);
    strcat(data, "-");
    strcat(data, mes);
    strcat(data, "-");
    strcat(data, ano);
    
}

int configurarRegistro(Servico servicos[]){
    Registro registroAtual;
    Rendimento rendimentoAtual;
    int recebeu = 0;
    REGISTRO_PRINCIPAL = fopen("banco_de_dados/registro_principal.dat", "rb+");
    if (REGISTRO_PRINCIPAL == NULL){
        REGISTRO_PRINCIPAL = fopen("banco_de_dados/registro_principal.dat", "wb+");
        if (REGISTRO_PRINCIPAL == NULL){
            printf("Erro ao criar o registro principal!\n");
            system("pause");
            return 0;
        }
    }

    fseek(REGISTRO_PRINCIPAL, - ((long int) sizeof(Registro)), SEEK_END);

    recebeu = fread(&registroAtual, sizeof(Registro), 1, REGISTRO_PRINCIPAL);
    if(!recebeu){
        return 0;
    }
    else{
        qtdServicos += registroAtual.qtdServicosAbertos;
        printf("Quantidade de servicos: %d\n", qtdServicos);
        for (int i = 0; i <= qtdServicos; i++){
            strcpy(servicos[i].nomeCliente, registroAtual.servicos[i].nomeCliente);
            strcpy(servicos[i].modeloMoto, registroAtual.servicos[i].modeloMoto);
            strcpy(servicos[i].placaMoto, registroAtual.servicos[i].placaMoto);
            strcpy(servicos[i].descricaoDefeito, registroAtual.servicos[i].descricaoDefeito);
            servicos[i].status = registroAtual.servicos[i].status;
            servicos[i].preco = registroAtual.servicos[i].preco;

        }
        fclose(REGISTRO_PRINCIPAL);
        RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "rb+");
        if (RENDIMENTO == NULL){
            RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "wb+");
            if (RENDIMENTO == NULL){
                printf("Erro ao criar o registro de rendimento!\n");
                system("pause");
                return 0;
            }
        }
        fseek(RENDIMENTO, - ((long int) sizeof(Rendimento)), SEEK_END);
        fread(&rendimentoAtual, sizeof(Rendimento), 1, RENDIMENTO);
        fclose(RENDIMENTO);

    return 1;

        }
}

void solicitarServico(Servico servicos[]){
    char resposta = 'S';
    do{
        qtdServicos++;
        system("cls");
        printf("-------------------- SOLICITAR SERVICO --------------------\n");
        fflush(stdin);
        printf("Digite o nome do cliente: ");
        fgets(servicos[qtdServicos].nomeCliente, 31, stdin);
        fflush(stdin);
        printf("\nDigite o modelo da moto: ");
        fgets(servicos[qtdServicos].modeloMoto, 21, stdin);
        fflush(stdin);
        printf("\nDigite a placa da moto: ");
        fgets(servicos[qtdServicos].placaMoto, 9, stdin);
        fflush(stdin);
        printf("\nDigite a descricao do defeito: \n");
        fgets(servicos[qtdServicos].descricaoDefeito, 101, stdin);
        fflush(stdin);
        servicos[qtdServicos].status = 0;
        servicos[qtdServicos].preco = 0.0;

        printf("\nServico solicitado com sucesso!\n");
        printf("----------------------------------------------------------\n");

        while(1){
            printf("\nDeseja solicitar outro servico? (S/N): ");
            scanf(" %c", &resposta);
            if(resposta == 'S' || resposta == 's' || resposta == 'N' || resposta == 'n'){
                break;
                
            }else{
                printf("Opcao invalida! Tente novamente!\n");
            }

        }
        
    }while(resposta == 'S' || resposta == 's');

}

int encontrarMoto(Servico servicos[], char placa[], int posMotosEncontradas[], int status){
    int qtdMotosEncontradas = 0;
    for (int i = 0; i <= qtdServicos; i++){
        if(strcmp(placa, servicos[i].placaMoto) == 0){
            if(servicos[i].status == status){
                posMotosEncontradas[qtdMotosEncontradas] = i;
                qtdMotosEncontradas++;
                printf("\nInformacoes da moto encontrada (Solicitacao %d):\n", qtdMotosEncontradas);
                printf("Nome do cliente: %s", servicos[i].nomeCliente);
                printf("Modelo da moto: %s", servicos[i].modeloMoto);
                printf("Placa da moto: %s", servicos[i].placaMoto);
                printf("\nDescricao do defeito: %s", servicos[i].descricaoDefeito);
                if(servicos[i].preco != 0.0){
                        printf("Preco do servico (R$): %.2f\n", servicos[i].preco);
                    }
                else{
                    printf("Preco do servico (R$): Ainda nao definido!\n");
                }
            }
        }
    }
    return qtdMotosEncontradas;

}

void iniciarServico(Servico servicos[]){
    system("cls");
    char placa[9];
    int posMotosEncontradas[QTD_MAX_SOLICITACOES];
    int qtdMotosEncontradas = 0;
    int servicoEscolhido = -1;
    


    printf("-------------------- INICIAR SERVICO --------------------\n");
    printf("Digite a placa da moto que deseja iniciar o servico: ");
    
    fgets(placa, 9, stdin);
    fflush(stdin);

    qtdMotosEncontradas = encontrarMoto(servicos, placa, posMotosEncontradas, 0);
    if (!qtdMotosEncontradas){
        printf("Placa nao encontrada! Tente novamente!\n");
        system("pause");
        return;
    }
    else{
        printf("\n----------------------------------------------------------\n");
        printf("\nQual servico deseja iniciar? (Digite o numero da solicitacao): \n");
        scanf(" %d", &servicoEscolhido);
        servicoEscolhido--;
        servicos[posMotosEncontradas[servicoEscolhido]].status = 1;

    }

    printf("\nServico iniciado com sucesso!\n");
    printf("----------------------------------------------------------\n");
    system("pause");
}

void removerSolicitacao(Servico servicos[]){
    system("cls");
    char placa[9];
    int posMotosEncontradas[QTD_MAX_SOLICITACOES];
    int qtdMotosEncontradas = 0;
    int servicoEscolhido = -1;

    printf("-------------------- REMOVER SOLICITACAO --------------------\n");
    printf("Digite a placa da moto que deseja remover a solicitacao: ");
    fgets(placa, 9, stdin);
    fflush(stdin);

    qtdMotosEncontradas = encontrarMoto(servicos, placa, posMotosEncontradas, 0);
    if (!qtdMotosEncontradas){
        printf("Placa nao encontrada! Tente novamente!\n");
        system("pause");
        return;
    }
    else{
        printf("\n----------------------------------------------------------\n");
        printf("\nQual servico deseja remover? (Digite o numero da solicitacao): \n");
        scanf(" %d", &servicoEscolhido);
        servicoEscolhido--;
        servicos[posMotosEncontradas[servicoEscolhido]].status = 2;

    }
    printf("Solicitacao removida com sucesso!\n");
    printf("----------------------------------------------------------\n");
    system("pause");
}

void consultarSolicitacoes(Servico servicos[]){
    system("cls");
    printf("-------------------- CONSULTAR SOLICITACOES --------------------\n");
    for (int i = 0; i <= qtdServicos; i++){
        
        printf("Nome do cliente: %s", servicos[i].nomeCliente);
        printf("Modelo da moto: %s", servicos[i].modeloMoto);
        printf("Placa da moto: %s", servicos[i].placaMoto);
        printf("\nDescricao do defeito: %s", servicos[i].descricaoDefeito);
        switch(servicos[i].status){
            case 0:
                printf("Status: Pendente\n");
                break;
            case 1:
                printf("Status: Em andamento\n");
                break;
            case 2:
                printf("Status: Cancelado\n");
                break;
            case 3:
                printf("Status: Concluido\n");
                break;
        }
        if(servicos[i].preco != 0.0){
            printf("Preco do servico (R$): %.2f\n", servicos[i].preco);
        }
        else{
            printf("Preco do servico (R$): Ainda nao definido!\n");
        }
        printf("----------------------------------------------------------\n");
    }
    system("pause");
}

void concluirServico(Servico servicos[]){
    system("cls");
    char placa[9];
    int posMotosEncontradas[QTD_MAX_SOLICITACOES];
    int qtdMotosEncontradas = 0;
    int servicoEscolhido = -1;
    int pos = -1;

    printf("-------------------- CONCLUIR SERVICO --------------------\n");
    printf("Digite a placa da moto que deseja concluir o servico: ");
    fgets(placa, 9, stdin);
    fflush(stdin);
    qtdMotosEncontradas = encontrarMoto(servicos, placa, posMotosEncontradas, 1);
    if (!qtdMotosEncontradas){
        printf("Placa nao encontrada! Tente novamente!\n");
        system("pause");
        return;
    }
    else{
        printf("\n----------------------------------------------------------\n");
        printf("\nQual servico deseja concluir? (Digite o numero da solicitacao): \n");
        scanf(" %d", &servicoEscolhido);
        servicoEscolhido--;
    }
    pos = posMotosEncontradas[servicoEscolhido];
    printf("Digite o preco do servico (R$): ");
    scanf(" %f", &servicos[pos].preco);
    servicos[pos].status = 3;
    printf("Servico concluido com sucesso!\n");
    printf("----------------------------------------------------------\n");
    system("pause");
}

void encerrarExpediente(Servico servicos[]){
    int qtdServicosEmAberto = -1;
    char dataSistema[11];
    Registro novoRegistro;
    Rendimento rendimentoDoDia;
    REGISTRO_PRINCIPAL = fopen("banco_de_dados/registro_principal.dat", "rb+");
    if (REGISTRO_PRINCIPAL == NULL){
        REGISTRO_PRINCIPAL = fopen("banco_de_dados/registro_principal.dat", "wb+");
        if (REGISTRO_PRINCIPAL == NULL){
            printf("Erro ao criar o registro principal!\n");
            system("pause");
            return;
        }
    
    }


    system("cls");
    printf("-------------------- ENCERRAR EXPEDIENTE --------------------\n");
    printf("Encerrando expediente...\n");
    if (USAR_DATA_SISTEMA == 1){
        pegarData(dataSistema);
    }
    else{
        printf("\nDigite a data do sistema (DD-MM-AAAA): ");
        fgets(dataSistema, 11, stdin);
        fflush(stdin);
    }
    printf("Data do sistema: %s\n", dataSistema);
    float totalServicosConcluidos = 0.0;
    for (int i = 0; i <= qtdServicos; i++) {
        if (servicos[i].status == 3) {
            totalServicosConcluidos += servicos[i].preco;
        }
        if (servicos[i].status == 1 || servicos[i].status == 0) {
            qtdServicosEmAberto++;
            printf("Servico em aberto encontrado (%d)!\n", qtdServicosEmAberto + 1);
            novoRegistro.servicos[qtdServicosEmAberto].status = servicos[i].status;
            strcpy(novoRegistro.servicos[qtdServicosEmAberto].nomeCliente, servicos[i].nomeCliente);
            strcpy(novoRegistro.servicos[qtdServicosEmAberto].modeloMoto, servicos[i].modeloMoto);
            strcpy(novoRegistro.servicos[qtdServicosEmAberto].placaMoto, servicos[i].placaMoto);
            strcpy(novoRegistro.servicos[qtdServicosEmAberto].descricaoDefeito, servicos[i].descricaoDefeito);
            novoRegistro.servicos[qtdServicosEmAberto].preco = servicos[i].preco;


        }
    }
    novoRegistro.qtdServicosAbertos = qtdServicosEmAberto + 1;
    fseek(REGISTRO_PRINCIPAL, 0, SEEK_END);
    fwrite(&novoRegistro, sizeof(Registro), 1, REGISTRO_PRINCIPAL);

    fclose(REGISTRO_PRINCIPAL);
    RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "rb+");
    if (RENDIMENTO == NULL){
        RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "wb+");
        if (RENDIMENTO == NULL){
            printf("Erro ao criar o registro de rendimento!\n");
            system("pause");
            return;
        }
    }
    rendimentoDoDia.totalRendimento = totalServicosConcluidos;
    strcpy(rendimentoDoDia.data, dataSistema);
    
    fseek(RENDIMENTO, 0, SEEK_END);
    fwrite(&rendimentoDoDia, sizeof(Rendimento), 1, RENDIMENTO);

    printf("Total de servicos concluidos (R$): %.2f\n", totalServicosConcluidos);
    printf("----------------------------------------------------------\n");
    fclose(RENDIMENTO);
    
}

void historicoFinanceiro(){
    Rendimento rendimento;
    Rendimento maiorRendimento;
    system("cls");
    printf("-------------------- HISTORICO FINANCEIRO --------------------\n");
    printf("Historico de rendimentos:\n");
    RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "rb+");
    if (RENDIMENTO == NULL){
        RENDIMENTO = fopen("banco_de_dados/rendimento.dat", "wb+");
        if (RENDIMENTO == NULL){
            printf("Erro ao criar o registro de rendimento!\n");
            system("pause");
            return;
        }
    }
    maiorRendimento.totalRendimento = 0.0;
    int qtdRendimentos = -1;
    while(fread(&rendimento, sizeof(Rendimento), 1, RENDIMENTO)){
        qtdRendimentos++;
        printf("\nRendimento %d:\n", qtdRendimentos + 1);
        printf("Data: %s\n", rendimento.data);
        printf("Total de rendimento (R$): %.2f\n", rendimento.totalRendimento);
        if (rendimento.totalRendimento >= maiorRendimento.totalRendimento){
            maiorRendimento.totalRendimento = rendimento.totalRendimento;
            strcpy(maiorRendimento.data, rendimento.data);
        }
    }
    printf("\n\nMaior rendimento (R$): %.2f\n", maiorRendimento.totalRendimento);
    printf("Data: %s\n", maiorRendimento.data);
    printf("----------------------------------------------------------\n");
    fclose(RENDIMENTO);
    system("pause");
}


int main(){

    Servico servicos[QTD_MAX_SOLICITACOES];
    int op = 0;
    system("cls");
    configurarRegistro(servicos);


    do{
        system("cls");
        printf("-------------------- OFICINA DA ZONDA --------------------\n");
        printf("Bem-vindo ao software da oficina da Zonda!\n");
        printf("O que deseja fazer?\n");
        printf("1 - Solicitar servico\n");
        printf("2 - Iniciar servico\n");
        printf("3 - Remover solicitacao\n");
        printf("4 - Consultar solicitacoes\n");
        printf("5 - Concluir servico\n");
        printf("6 - Historico financeiro\n");
        printf("7 - Encerrar expediente\n");
        printf("8 - Sair\n");

        printf("Digite a opcao desejada: ");
        scanf(" %d", &op);
        fflush(stdin);
        switch(op){
            case 1:
                solicitarServico(servicos);
                break;
            case 2:
                iniciarServico(servicos);
                break;
            case 3:
                removerSolicitacao(servicos);
                break;
            case 4:
                consultarSolicitacoes(servicos);
                break;
            case 5:
                concluirServico(servicos);
                break;
            case 6:
                historicoFinanceiro();
                break;
            case 7:
                encerrarExpediente(servicos);
                op = 8;
            case 8:
                fclose(REGISTRO_PRINCIPAL);
                fclose(RENDIMENTO);
                printf("Ate a proxima!\n");
                printf("Saindo...\n");
                system("pause");
                break;
            default:
                printf("Opcao invalida! Tente Novamente!\n");
                system("pause");
                system("cls");
        }
    }while(op != 8);
    
    return 0;
}
