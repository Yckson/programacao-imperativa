#include <stdio.h>
#include <ctype.h>


void solicitarEntrada(int *valor){ /* Foi a alternativa encontrada para evitar muita repeticao de codigo.*/
    printf("\nDigite o numero de estudo: ");
    scanf("%d", valor);
}

int buscarNumeracao(int *num, int numeracao){
    int resto;

    resto = *num / numeracao;
    *num = *num % numeracao;

    return resto;
}

int buscarDM(int *num){
    return buscarNumeracao(&*num, 10000);
}

int buscarUM(int *num){
    buscarDM(&*num);
    return buscarNumeracao(&*num, 1000);
}

int buscarC(int *num){
    buscarUM(&*num);
    return buscarNumeracao(&*num, 100);
}

int buscarD(int *num){
    buscarC(&*num);
    return buscarNumeracao(&*num, 10);
}

int buscarU(int *num){
    buscarD(&*num);
    return *num;
}

int exibirMenu (){

    int opcao; int numero;

    printf("===================================MENU===================================\n");
    printf("  Escolha uma das seguintes opcoes para extrair do numero:\n");
    printf("    U -- Unidade\n");
    printf("    D -- Dezena\n");
    printf("    C -- Centena\n");
    printf("    M -- Unidade de Milhar\n");
    printf("    Z -- Dezena de Milhar\n");
    printf("\n Insira a opcao: ");
    scanf(" %c", &opcao);

    switch(toupper(opcao)){
        case 'U':
            solicitarEntrada(&numero);
            printf("O valor na casa das unidades e: %d", buscarU(&numero));
            
            break;
        case 'D':
            solicitarEntrada(&numero);
            printf("O valor na casa das dezenas e: %d", buscarD(&numero));
            break;

        case 'C':
            solicitarEntrada(&numero);
            printf("O valor na casa das centenas e: %d", buscarC(&numero));
            break;
        
        case 'M':
            solicitarEntrada(&numero);
            printf("O valor na casa das unidades de milhar e: %d", buscarUM(&numero));
            break;

        case 'Z':
            solicitarEntrada(&numero);
            printf("O valor na casa das dezenas de milhar e: %d", buscarDM(&numero));
            break;
        
        default:
            printf("\n Opcao invalida! Tente novamente.\n\n\n");
            return exibirMenu();
    }

    return 0;
}


int main (){
    
    return exibirMenu();
}