#include <stdio.h>
#include <ctype.h>
#include <string.h>

void strLower(char strDestino[], char strOriginal[]){
    for (int itemAtual = 0; itemAtual < strlen(strOriginal); itemAtual++){
        strDestino[itemAtual] = tolower(strOriginal[itemAtual]);
    }
}

int contarVogais(char palavra[]){
    int numVogais = 0;
    char palavraMin[21] = " ";
    char vogais [] = "aeiou";

    strLower(palavraMin, palavra);
    printf("\n%s", palavraMin);
    for (int vogalAtual = 0; vogalAtual < strlen(vogais); vogalAtual++){
        for (int itemAtual = 0; itemAtual < strlen(palavraMin); itemAtual++){
            if(palavraMin[itemAtual] == vogais[vogalAtual]){
                numVogais++;
                printf("\n%d\n", numVogais);
            }
        }
    }
    return numVogais;
}

int main (){

    char palavra[21];
    char palavraMin[21];
    
    while(1){
        printf("Digite uma palavra (\"P\" para parar, max 20 letras): ");
        fgets(palavra, 21, stdin);
        fflush(stdin);

        palavra[strcspn(palavra, "\n")] = '\0'; //remover a quebra de linha
        if (toupper(palavra[0]) == 'P' && strlen(palavra) == 1){
            break;
        }
        else{
            printf("Numero de vogais da palavra: %d\n", contarVogais(palavra));
        }
    }



    return 0;
}