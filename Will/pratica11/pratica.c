#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>






typedef struct TpFarma Farmaco;

struct TpFarma{
	char Nome[21];
	float Preco;
	int QEstoque;
};

char caminhoDoArquivo[100];

FILE *ArqFarma;

int trocaBanco(char caminhoDoArquivo[]){
    fclose(ArqFarma);
    ArqFarma = fopen(caminhoDoArquivo, "rb+");
    if(ArqFarma == NULL){
        ArqFarma = fopen(caminhoDoArquivo, "wb+");
        if(ArqFarma == NULL){
            return 0;
        }
    }
    return 1;
}

void alterarArquivo(){
    char caminhoDoArquivo[100];
    char opcao;
    int sucesso;
    system("cls");
    printf("\n\n> > > Mudar Banco de Dados < < < \n\n");
    printf("Digite o caminho do novo arquivo: ");
    fflush(stdin);
    fgets(caminhoDoArquivo, 100, stdin);
    fflush(stdin);
    caminhoDoArquivo[strlen(caminhoDoArquivo)-1] = '\0';
    sucesso = trocaBanco(caminhoDoArquivo);
    if(sucesso == 0){
        printf("Erro ao abrir o arquivo!\n");
    }
    else{
        printf("Arquivo aberto com sucesso!\n");
    }
    system("pause");
    return;
}

void stringUpper(char *string){
    int i;
    for(i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}



long int tamanhoArquivo(){
    long int tamanho;
    fseek(ArqFarma, 0, SEEK_END);
    tamanho = ftell(ArqFarma);
    rewind(ArqFarma);
    return tamanho;
}

Farmaco verificarExistencia(char nomeFarmaco[]){
    Farmaco Remedio;
    char nomeFarmacoM[21];
    char nomeNoArquivo[21];

    rewind(ArqFarma);
    strcpy(nomeFarmacoM, nomeFarmaco);
    stringUpper(nomeFarmacoM);
    while(fread(&Remedio, sizeof(Farmaco), 1, ArqFarma)){
        strcpy(nomeNoArquivo, Remedio.Nome);
        stringUpper(nomeNoArquivo);
        if(strcmp(nomeNoArquivo, nomeFarmacoM) == 0 && Remedio.QEstoque != -1){
            return Remedio;
        }
    }
    Remedio.Preco = -1;
    return Remedio;
}

void incluir(){
    char nomeFarmaco[21];
    float precoFarmaco;
    int qtdEstoqueFarmaco;
    char opcao;
    Farmaco Remedio;


    system("cls");
    printf("\n\n> > > Incluir Farmaco< < < \n\n");
    do{
        printf("Digite o nome do farmaco: ");
        fflush(stdin);
        fgets(nomeFarmaco, 21, stdin);
        fflush(stdin);
        nomeFarmaco[strlen(nomeFarmaco)-1] = '\0';
        printf("Digite o preco do farmaco: ");
        scanf("%f", &precoFarmaco);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &qtdEstoqueFarmaco);

        if (verificarExistencia(nomeFarmaco).Preco != -1){
            printf("Farmaco ja cadastrado!\n");
        }
        else{
            Remedio.Preco = precoFarmaco;
            Remedio.QEstoque = qtdEstoqueFarmaco;
            strcpy(Remedio.Nome, nomeFarmaco);
            fwrite(&Remedio, sizeof(Farmaco), 1, ArqFarma);
        }
        


        do{
            printf("\n\nDeseja incluir outro farmaco? (S/N): ");
            scanf(" %c", &opcao);
            opcao = toupper(opcao);
            if(opcao != 'S' && opcao != 'N'){
                printf("Opcao invalida! Digite S ou N!\n");
            }
        }while(opcao != 'S' && opcao != 'N');
        
        
    }while(opcao == 'S');

}

void excluir(){
    system("cls");
    char nomeFarmaco[21];
    unsigned long long int posFarmaco = 0;
    printf("\n\n> > > Excluir Farmaco< < < \n\n");

    if (tamanhoArquivo() != 0){

        printf("Digite o nome do farmaco para excluir: ");
        fflush(stdin);
        fgets(nomeFarmaco, 21, stdin);
        fflush(stdin);
        nomeFarmaco[strlen(nomeFarmaco)-1] = '\0';
        Farmaco Remedio = verificarExistencia(nomeFarmaco);
        if(Remedio.Preco == -1 || Remedio.QEstoque == -1){
            printf("Farmaco nao encontrado!\n");
        }
        else{
            Remedio.QEstoque = -1;
            posFarmaco = -1*sizeof(Farmaco);
            fseek(ArqFarma, posFarmaco, 1);
            fwrite(&Remedio, sizeof(Farmaco), 1, ArqFarma);
            printf("Farmaco excluido com sucesso!\n");
        }
    }

    else{
        printf("Nao ha farmacos cadastrados!\n");
    }

    system("pause");
    return;

}

void alterar(){
    char nomeFarmaco[21];
    float precoFarmaco;
    int qtdEstoqueFarmaco;
    Farmaco Remedio;
    int opcao;
    unsigned long long int posFarmaco = 0;
    system("cls");
    printf("\n\n> > > Alterar Farmaco< < < \n\n");

    if (tamanhoArquivo() != 0){
        printf("Digite o nome do farmaco para alterar: ");
        fflush(stdin);
        fgets(nomeFarmaco, 21, stdin);
        fflush(stdin);
        nomeFarmaco[strlen(nomeFarmaco)-1] = '\0';
        Remedio = verificarExistencia(nomeFarmaco);
        if(Remedio.Preco == -1 || Remedio.QEstoque == -1){
            printf("Farmaco nao encontrado!\n");
        }
        else{
            printf("\nQual dado deseja alterar?\n");
            printf("1 - Preco\n");
            printf("2 - Quantidade em estoque\n");
            printf("3 - Preco e Quantidade em estoque\n");
            scanf(" %d", &opcao);
            switch(opcao){
                case 1:
                    printf("Digite o novo preco: ");
                    scanf("%f", &precoFarmaco);
                    Remedio.Preco = precoFarmaco;
                    break;
                case 2:
                    printf("Digite a nova quantidade em estoque: ");
                    scanf("%d", &qtdEstoqueFarmaco);
                    Remedio.QEstoque = qtdEstoqueFarmaco;
                    break;
                case 3:
                    printf("Digite o novo preco: ");
                    scanf("%f", &precoFarmaco);
                    Remedio.Preco = precoFarmaco;
                    printf("Digite a nova quantidade em estoque: ");
                    scanf("%d", &qtdEstoqueFarmaco);
                    Remedio.QEstoque = qtdEstoqueFarmaco;
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            posFarmaco = -1*sizeof(Farmaco);
            fseek(ArqFarma, posFarmaco, 1);
            fwrite(&Remedio, sizeof(Farmaco), 1, ArqFarma);
            printf("Farmaco alterado com sucesso!\n");

        }
    }
    else{
        printf("Nao ha farmacos cadastrados!\n");
    }
    system("pause");
    return;
}

void consultar(){
    char nomeFarmaco[21];
    Farmaco Remedio;
    system("cls");
    printf("\n\n> > > Consultar Farmaco< < < \n\n");
    printf("Digite o nome do farmaco: ");
    fflush(stdin);
    fgets(nomeFarmaco, 21, stdin);
    fflush(stdin);
    nomeFarmaco[strlen(nomeFarmaco)-1] = '\0';
    Remedio = verificarExistencia(nomeFarmaco);
    if(Remedio.Preco == -1 || Remedio.QEstoque == -1){
        printf("Farmaco nao encontrado!\n");
    }
    else{
        printf("Nome: %s\n", Remedio.Nome);
        printf("Preco: %.2f\n", Remedio.Preco);
        printf("Quantidade em estoque: %d\n", Remedio.QEstoque);
    }
    system("pause");

}

void listarTodos(){
    Farmaco Remedio;
    system("cls");
    printf("\n\n> > > Listar Todos os Farmacos< < < \n\n");
    if (tamanhoArquivo() != 0){
        while(fread(&Remedio, sizeof(Farmaco), 1, ArqFarma)){
            if(Remedio.QEstoque != -1){
                printf("Nome: %s\n", Remedio.Nome);
                printf("Preco: %.2f\n", Remedio.Preco);
                printf("Quantidade em estoque: %d\n\n", Remedio.QEstoque);
            }
        }
    }
    else{
        printf("Nao ha farmacos cadastrados!\n");
    }
    rewind(ArqFarma);
    system("pause");
    return;
}

void recuperarFarmaco(){
    Farmaco Remedio;
    char nomeFarmacoM[21];
    char nomeNoArquivo[21];
    char opcao;

    char nomeFarmaco[21];
    system("cls");
    printf("\n\n> > > Recuperar Farmaco< < < \n\n");
    printf("Digite o nome do farmaco para recuperar: ");
    fflush(stdin);
    fgets(nomeFarmaco, 21, stdin);
    fflush(stdin);
    nomeFarmaco[strlen(nomeFarmaco)-1] = '\0';


    rewind(ArqFarma);
    strcpy(nomeFarmacoM, nomeFarmaco);
    stringUpper(nomeFarmacoM);
    while(fread(&Remedio, sizeof(Farmaco), 1, ArqFarma)){
        strcpy(nomeNoArquivo, Remedio.Nome);
        stringUpper(nomeNoArquivo);
        if(strcmp(nomeNoArquivo, nomeFarmacoM) == 0 && Remedio.QEstoque == -1){
            printf("Nome: %s\n", Remedio.Nome);
            printf("Preco: %.2f\n", Remedio.Preco);
            printf("Quantidade em estoque: %d\n", Remedio.QEstoque);

            printf("Deseja recuperar este farmaco? (S/N): ");
            scanf(" %c", &opcao);
            opcao = toupper(opcao);
            if(opcao == 'S'){
                Remedio.QEstoque = 0;
                fseek(ArqFarma, -1* ((long int) sizeof(Farmaco)), 1);
                fwrite(&Remedio, sizeof(Farmaco), 1, ArqFarma);
                printf("Farmaco recuperado com sucesso!\n");
                return;
            }
            else{
                printf("Farmaco nao recuperado!\n");
                return;
            }
            return;
        }
    }
    printf("Farmaco nao encontrado ou ainda no sistema!\n");
    return;
}




int main(){
  strcpy(caminhoDoArquivo, "Dados/farmacos.dat");
  ArqFarma=fopen(caminhoDoArquivo,"rb+");
  if(ArqFarma==NULL){
    ArqFarma=fopen(caminhoDoArquivo,"wb+");
  }

  char Opcao;
  do{
	    
        system("cls");
        printf("\n\n> > > Pague Pouco < < < \n\n");
        printf("Que deseja fazer? \n\n");
        printf("I - Incluir \n");  
        printf("E - Excluir \n");
        printf("A - Alterar \n");
        printf("C - Consultar \n");
        printf("M - Mudar Banco de Dados \n");
        printf("T - Listar Todos \n");
        printf("R - Recuperar Registro de Farmaco \n");
        printf("S - Sair \n\n");
        scanf(" %c", &Opcao);

        Opcao=toupper(Opcao);
        switch (Opcao){
          case 'I': incluir(); break; 
          case 'E': excluir(); break; 
          case 'A': alterar(); break; 
          case 'C': consultar(); break;
          case 'M': alterarArquivo(); break;
          case 'T': listarTodos(); break;
          case 'R': recuperarFarmaco(); system("pause"); break;
        }
    } 
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}