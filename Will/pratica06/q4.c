#include <stdio.h>
#include <ctype.h>
#include <string.h>

void strUpper(char strDestino[], char strOriginal[]){
    for (int itemAtual = 0; itemAtual < strlen(strOriginal); itemAtual++){
        strDestino[itemAtual] = toupper(strOriginal[itemAtual]);
    }
}

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

void strLower(char strDestino[], char strOriginal[]){
    for (int itemAtual = 0; itemAtual < strlen(strOriginal); itemAtual++){
        strDestino[itemAtual] = tolower(strOriginal[itemAtual]);
    }
}

void pegarNome(char palavra[], char nome[], int posInicio){
    int cont = posInicio;
    int contNome = 0;
    while (palavra[cont] != ' ' && cont <= strlen(palavra)){
        nome[contNome] = palavra[cont];
        cont+=1;
        contNome+=1;
    }

}

int main(){
    char nomeCompleto[41] = " ";
    char nomeCompletoMin[41] = " ";
    char nome[21] = " ";
    char sobrenome[21] = " ";
    char nomeCapitalizado[21] = " ";
    char sobrenomeMaisculo[21] = " ";

    while(1){
        printf("Digite um nome e sobrenome (\"P\" para parar, max 41 letras. Exemplo: \"Kenia Cox\"): ");
        fgets(nomeCompleto, 41, stdin);
        fflush(stdin);


        strLower(nomeCompletoMin, nomeCompleto);
        nomeCompletoMin[strcspn(nomeCompleto, "\n")] = '\0';
        if (toupper(nomeCompletoMin[0]) == 'P' && strlen(nomeCompletoMin) == 1){
            break;
        }
        else{

            pegarNome(nomeCompletoMin, nome, 0);
            pegarNome(nomeCompletoMin, sobrenome, strlen(nome)+1);
            capitalizar(nomeCapitalizado, nome);
            strUpper(sobrenomeMaisculo, sobrenome);

        
            printf("Formatado: %s, %s\n", sobrenomeMaisculo, nomeCapitalizado);

    
        }
    }



    return 0;
}