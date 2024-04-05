#include <stdio.h>
#include <string.h>
#include <ctype.h>


void toUpperCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}


int bbinaria(char chave[30], int inicio, int fim, char vetor[][30]) {
        if (fim < inicio)
            return -1;
        else {
            
            int meio = (inicio + fim) / 2;
            if (strcmp(vetor[meio], chave) == 0)
                return meio;
            else {
                if (strcmp(vetor[meio], chave) < 0)
                    return bbinaria(chave, meio + 1, fim, vetor);
                else
                    return bbinaria(chave, inicio, meio - 1, vetor);
            }
        }
}

int main() {
    char nomes[30][30];
    char nome[30] = "";
    strcpy(nomes[0], "ANA");
    strcpy(nomes[1], "BIA");
    strcpy(nomes[2], "CARLA");
    strcpy(nomes[3], "DUDA");
    strcpy(nomes[4], "EVA");
    strcpy(nomes[5], "FABI");
    strcpy(nomes[6], "GABI");
    strcpy(nomes[7], "HELO");
    strcpy(nomes[8], "IARA");
    strcpy(nomes[9], "JANA");
    strcpy(nomes[10], "KAKA");
    strcpy(nomes[11], "LALA");
    
    printf("Digite o nome que deseja buscar: ");
    scanf("%s", nome);

    toUpperCase(nome);
    if (bbinaria(nome, 0, 11, nomes) == -1)
        printf("O nome %s nao foi encontrado", nome);
    else{
        printf("O nome %s esta na posicao %d", nome, bbinaria(nome, 0, 10, nomes));
    }


    return 0;
}