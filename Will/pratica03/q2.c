#include <stdio.h>

int main(){
    
    int qtdGatos;
    int qtdParaVeterExperiente;
    int qtdParaNovato;

    printf("Digite a quantidade de gatos capturados: ");
    scanf("%d", &qtdGatos);

    qtdParaVeterExperiente = qtdGatos / 4;
    qtdParaNovato = qtdGatos % 4;

    if (qtdGatos <= 4){
        printf("\nToda a equipe trabalhara em conjunto com os %d gatos", qtdGatos);
    }
    
    else{
        printf("\nQuantidade p/cada verinario experiente: %d\nQuantidade p/ veterinario recem formado: %d", qtdParaVeterExperiente, qtdParaNovato);
    }





    return 0;
}