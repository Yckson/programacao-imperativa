#include <stdio.h>
#include <ctype.h>
#include <string.h>

void capitalizar (char strDestino[], char strInicial[]){
    for (int itemAtual = 0; itemAtual < strlen(strInicial); itemAtual++){
        if (itemAtual == 0){
            strDestino[itemAtual] = toupper(strInicial[itemAtual]);
        }
        else{
            strDestino[itemAtual] = tolower(strInicial[itemAtual]);
        }
    }
}

int main(){
    char nome [21];
    char nomeCapitalizado[21];

    printf("Digite um nome (max 20 letras): ");
    fgets(nome, 21, stdin);

    capitalizar(nomeCapitalizado, nome);

    printf("Nome capitalizado: ");
    puts(nomeCapitalizado);
    


    return 0;
}