#include <stdio.h>


int main (){
    int qtdDias;
    const int diasNoMes = 30;
    int qtdMeses = 0;

    printf("Digite a quantidade de dias: ");
    scanf("%d", &qtdDias);


    while (qtdDias >= 30){
        qtdDias -= 30;
        qtdMeses += 1;
    }

    printf("A quantidade total de meses contidos em %d dias eh: %d!", qtdDias, qtdMeses);





    return 0;
}