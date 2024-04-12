#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma{
	char Nome[21];
	float Preco;
	int QEstoque;
  };
  
typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;
  
FILE *ArqFarma;

//Usado para calcular o tamanho do registro;
long long int Tamanho = sizeof(TpFARMA);

//Melhoria: caitaliza (Coloca a primeira letra em maiusculas e o resto em minusculas) as palavras digitadas.
void capitaliza(char palavra[21]){
  int i;
  for(i = 0; palavra[i] != '\0'; i++){
    if (i == 0)
      palavra[i] = toupper(palavra[i]);
    else
      palavra[i] = tolower(palavra[i]);
  }
}

// Melhoria: procura o remedio no arquivo.
void ProcuraRemedio(char Remedio[21], int *encontrou){
    capitaliza(Remedio);
    fseek(ArqFarma,0,0);
    while(fread(&RgFarma,Tamanho,1,ArqFarma)){
      if (strcmp(RgFarma.Nome,Remedio)==0){
	      *encontrou = 1;
        break;
	      /*printf("Nome: %s.\n",Registro.Nome);
        printf("Valor: R$%.2f\n",Registro.Preco);
        printf("Estoque: %d.\n",Registro.QEstoque);*/
      }
    }
  
}

//Exercicio 2 (PENDENTE): Verificar se o remedio colocado ja existe.
void Incluir() {
  char R;
  do{
    system("cls");
    printf("========== inclusao ==========\n\n");
    do{
      printf("Qual o nome do remedio? ");
      scanf("%s", RgFarma.Nome);
      capitaliza(RgFarma.Nome);

      if (strlen(RgFarma.Nome) > 20)
        printf("O nome digitado eh invalido. Tente novamente\n");
    }
    while(strlen(RgFarma.Nome) > 20);
    printf("Qual o preco do remedio? ");
    scanf("%f", &RgFarma.Preco);
    printf("Qual o estoque disponivel? ");
    scanf("%d", &RgFarma.QEstoque);
    fseek(ArqFarma, 0, 2);
    fwrite(&RgFarma, Tamanho, 1, ArqFarma);
    do{
        printf("\n\n ===== Nova inclusao? =====\nDigite S(caso queira) ou N(caso nao queira): ");
        scanf(" %c",&R);
        R=toupper(R);

        if (R != 'S' && R != 'N')
            printf("A letra digitada nao corresponde ao que foi solicitado. \nTente novamente.");
    }
    while(R != 'S' && R != 'N');
    }
  while (R!='N');
}

// Infica quantos registros tem no arquivo;
long int TArquivo(){
	fseek(ArqFarma, 0, 2); //Posicionamento do ponteiro no final do arquivo;
	long int R = ftell(ArqFarma)/Tamanho;
	return R;
}


// Alteracao: agora o usuario tem poder de escolha ao alterar o preco ou o estoque.
void Alterar(){
  if (TArquivo() != 0){
    system("cls");
    printf("========== alterar ==========\n\n");
    char Farmaco[21];
    do{
        printf("Qual o nome do remedio? ");
        scanf("%s", Farmaco);

        if (strlen(Farmaco) > 20)
            printf("O nome digitado excede o limite de caracteres.\nTente novamente.\n\n");
    }
    while(strlen(Farmaco) > 20);
    fseek(ArqFarma,0,0);
    
    //Aplicacao do novo modulo.
    int Achou = 0;
    ProcuraRemedio(Farmaco, &Achou);
    
    if (Achou==0)
      printf("Registro inexistente!"); 
    
    // Não podemos obrigar a pessoa a modificar os dados sem escolher o que ela quer alterar.
    // Além disso, eu preciso fazer uma verificação se os dados que foram colocados são realmente novos.

    else{
      char opcao; //verificao
      float NovoPreco;
      int NovoEstoque;

      printf("O que voceh deseja alterar?\n");
      printf("\"P\": Mudar o preco. \n\"Q\": Mudar a quantidade. \n\"A\": Mudar ambos.\n");
      printf("Opcao: ");
      
      do{
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

        if(opcao != 'A' && opcao != 'Q' && opcao != 'P')
            printf("A opcao selecionada nao consta no programa.\n Tente novamente.");
      }
      while(opcao != 'A' && opcao != 'Q' && opcao != 'P');
      switch(opcao){
        
        case 'A':
            do{
                printf("Qual o novo preco? \n"); 
                scanf("%f",&NovoPreco);
                printf("Qual a nova quantidade? \n");
                scanf("%d",&NovoEstoque);

                if(NovoPreco == RgFarma.Preco || NovoEstoque == RgFarma.QEstoque)
                    printf("Um dos valores digitados sao os mesmos dos antigos.\nTente novamente:\n");
            }
            while(NovoPreco == RgFarma.Preco || NovoEstoque == RgFarma.QEstoque);

            //printf("Salvar mudancas?\nDigite \"S\" (caso queira) ou digite N ");
            //scanf(" %c", &verificao);
            RgFarma.Preco = NovoPreco;
            RgFarma.QEstoque = NovoEstoque;

            fseek(ArqFarma,-Tamanho,1);
            fwrite(&RgFarma,Tamanho,1,ArqFarma);
            printf(">>> Alteracao efetuada com sucesso! <<<\n");
            system("pause");
        break;

        case 'Q':
            do{
                printf("Qual a nova quantidade? \n");
                scanf("%d",&NovoEstoque);

                if(NovoEstoque == RgFarma.QEstoque)
                    printf("O novo valor de estoque eh igual ao antigo.\nTente novamente:\n");
            }
            while(NovoEstoque == RgFarma.QEstoque);

            //printf("Salvar mudancas?\nDigite \"S\" (caso queira) ou digite N ");
            //scanf(" %c", &verificao);
            RgFarma.QEstoque = NovoEstoque;
            
            fseek(ArqFarma,-Tamanho,1);
            fwrite(&RgFarma,Tamanho,1,ArqFarma);
            printf(">>> Alteracao efetuada com sucesso! <<<\n");
            system("pause");
        break;

        case 'P':
            do{
                printf("Qual o novo preco? \n"); 
                scanf("%f",&NovoPreco);

                if(NovoPreco == RgFarma.Preco)
                    printf("O valor do novo preco eh igual ao preco antigo.\nTente novamente:\n");
            }
            while(NovoPreco == RgFarma.Preco);

            //printf("Salvar mudancas?\nDigite \"S\" (caso queira) ou digite N ");
            //scanf(" %c", &verificao);
            RgFarma.Preco = NovoPreco;
            
            fseek(ArqFarma,-Tamanho,1);
            fwrite(&RgFarma,Tamanho,1,ArqFarma);
            printf(">>> Alteracao efetuada com sucesso! <<<\n");
            system("pause");
        break;

      }    
    }
  }
  else{
    printf("Arquivo Vazio. Nao existem dados a alterar.\n");}
    //system("pause");
}

// Verifica se o remedio consta na farmacia.
void Consultar(){
  system("cls");
  printf("========== Consulta ==========\n\n");
  char Farmaco[21];
  do{
    printf("Qual o nome do remedio? ");
    scanf("%s", Farmaco);

    if (strlen(Farmaco) > 20)
      printf("O nome digitado excede o limite de caracteres.\nTente novamente.\n\n");
  }
  while(strlen(Farmaco) > 20); 

  fseek(ArqFarma, 0, 0);
  int Achou = 0;
  ProcuraRemedio(Farmaco, &Achou);

  if (Achou==0){
    printf("Registro inexistente!");  
    system("pause");
  }
  return;
}

void LTodos(){
  fseek(ArqFarma, 0, 0);
  do {
	  fread(&RgFarma,Tamanho,1,ArqFarma);
	  if (!feof(ArqFarma)){
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);
      printf("=================================\n\n");}
  }
  while (!feof(ArqFarma));
}

//N 'exclui' o farmaco, so o deixa 'invisivel' na hora de listar.
void Excluir(){
  char FarmacoExclui[21];
  int Achou = 0;
  printf("==========================================\n");
  printf("Qual desses remedios voceh deseja excluir?\n");
  printf("==========================================\n\n");
  LTodos();

  printf("OPCAO: ");
  scanf("%s", FarmacoExclui);
  ProcuraRemedio(FarmacoExclui, &Achou);
  if(Achou){
    fseek(ArqFarma, -Tamanho, 1); //Vai estabelecer o ponteiro naquela posicao onde ele encontrou o remedio.
    RgFarma.QEstoque = -1;
    fwrite(&RgFarma, Tamanho, 1, ArqFarma);
    printf("Exclusao bem sucedida!\n");
    system("pause");
  }

  else{
    printf("Remedio nao encontrado no sistema.\n");
    system("pause");
  }
}

int main(){
  ArqFarma=fopen("Farmacos.dat","rb+");
    if (ArqFarma==NULL){
        ArqFarma=fopen("Farmacos.dat","wb+");
        if (ArqFarma==NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
        }
    }
  char Opcao;
  do{
	//system("cls");
    printf("======= Pague Pouco =======\n");
    printf("O que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    printf("Opcao: ");
    
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    
    switch (Opcao){
      case 'I': Incluir(); 
                break; 
      case 'E': Excluir(); 
                break; 
      case 'A': Alterar(); 
                break; 
      case 'C': Consultar(); 
                break; 
      case 'T': printf("========== lista todos ==========\n\n"); 
                LTodos(); 
                break;}
    } 
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;
}