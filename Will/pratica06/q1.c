#include <stdio.h>
#include <ctype.h>
#include <string.h>

//A fim de evitar problemas com memória, passarei a adotar fgets()


void strUpper(char palavra[], char palavraMaiuscula[]){
    for (int itemAtual = 0; itemAtual < strlen(palavra); itemAtual++){
        palavraMaiuscula[itemAtual] = toupper(palavra[itemAtual]);
    }
}

int main (){

    char palavra [21];
    char palavraMaiusculo [21];

    printf("Digite uma palavra para conversao em maiusculo (max 20 caracteres): ");
    gets(palavra);
    strUpper(palavra, palavraMaiusculo);

    printf("Palavra em maiusculo: ");
    puts(palavraMaiusculo);
    

    return 0;
}