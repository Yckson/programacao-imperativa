#include <stdio.h>

int main () {

    int qtdPessoasTotal; 
    int qtdViagensKombi; 
    int qtdPessoasColetivo;

    printf("Digite a quantidade total de pessoas: ");
    scanf("%d", &qtdPessoasTotal);

    qtdViagensKombi = qtdPessoasTotal / 11;
    qtdPessoasColetivo = qtdPessoasTotal % 11;

    if (qtdViagensKombi == 0){
        qtdViagensKombi = 1;
        qtdPessoasColetivo = 0;
    }

    printf("\nSerao necessarias %d viagens de Kombi e  %d passagens de coletivo.", qtdViagensKombi, qtdPessoasColetivo);





    return 0;
}