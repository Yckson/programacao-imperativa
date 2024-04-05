#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//SOFTWARE DA OFICINA DA "ZONDA"
//preciso implementar uma maneira de conseguir registrar várias motos com a mesma placa

typedef struct Servico Servico;


const int QTD_MAX_SOLICITACOES = 50;
int qtdServicos = -1;


struct Servico {
    char nomeCliente[31];
    char modeloMoto[21];
    char placaMoto[9]; // BRA-1234
    char descricaoDefeito[101];
    int status; // 0 - Pendente, 1 - Em andamento, 2 - Cancelado, 3 - Concluído;
    float preco;

};


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
    system("cls");
    printf("-------------------- ENCERRAR EXPEDIENTE --------------------\n");
    printf("Encerrando expediente...\n");
    float totalServicosConcluidos = 0.0;
    for (int i = 0; i <= qtdServicos; i++) {
        if (servicos[i].status == 3) {
            totalServicosConcluidos += servicos[i].preco;
        }
    }
    printf("Total de servicos concluidos (R$): %.2f\n", totalServicosConcluidos);
    printf("----------------------------------------------------------\n");
}


int main(){

    Servico servicos[QTD_MAX_SOLICITACOES];
    int op = 0;

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
        printf("6 - Encerrar expediente\n");
        printf("7- Sair\n");

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
                encerrarExpediente(servicos);
                op = 7;
            case 7:
                printf("Ate a proxima!\n");
                printf("Saindo...\n");
                system("pause");
                break;
            default:
                printf("Opcao invalida! Tente Novamente!\n");
                system("pause");
                system("cls");
        }
    }while(op != 7);
    
    return 0;
}
