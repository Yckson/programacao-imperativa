#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


const int NUM_ALUNOS = 5;

void slice (char strDestino[], char strInicial[], int inicio, int final){
    

    int i = 0;
    for (int c = inicio; c <= final; c++){
        strDestino[i] = strInicial[c];
        i++;
    }
}

int encontrar (int lista[], int valor){
    for (int c = 0; c < 5; c++){
        if(valor == lista[c]){
            return c;
        }
    }
    return -1;
}

int comparar(char str1[], char str2[]){
    for (int i = 0; i < strlen(str2); i++){
        if (str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}


int main (){

    //[2001, 2002, 2003...]
    //[3, 1, 7]
    //201299

    char matricula[7] = " ";
    int anos[6] = {0};
    int qtdPorCurso[6] = {0};
    int qtdAlunos = 0;
    char ano[5];
    char numCurso[3] = " ";
    int posAno = 0;

    for(int repetir = 1; repetir <= NUM_ALUNOS; repetir++){

        printf("Digite a matricula do aluno %d: ", repetir);
        fgets(matricula, 7, stdin);
        fflush(stdin);

        slice(ano, matricula, 0, 3);
        slice(numCurso, matricula, 4, 6);
        posAno = encontrar(anos, atoi(ano));
        if (posAno == -1){
            if (comparar(numCurso, "99") != 0){
                anos[qtdAlunos] = atoi(ano);
                qtdPorCurso[qtdAlunos] = 1;
                qtdAlunos += 1;
            }
        }
        else{
            qtdPorCurso[posAno] += 1;
        }




    }

    for (int contador = 0; contador <= qtdAlunos; contador++){
        if (anos[contador] != 0){
            printf("Quantidade de alunos de gerontologia em %d: %d\n", anos[contador], qtdPorCurso[contador]);
        }
    }





    return 0;
}