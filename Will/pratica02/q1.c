#include <stdio.h>
#include <math.h>

/*
    Exemplo para entender o cálculo:

        X comprimidos = 10;
        N unidades em cada caixa = 10;
        Quantidade de caixas a serem adquiridas = 1;


    int calcularQtdComprimidos(int qComprimidos, int unidsNaCaixa){
    int qtdNecessaria = (int) ceil( (float) qComprimidos / unidsNaCaixa );
    return qtdNecessaria;
}

*/


int divisaoInteiraArr(int dividendo, int divisor){
    
    int quociente = (int) ceil( (float) dividendo / divisor );

    return quociente;
}



int main(){
    int qtdComprimidos, unidadesNaCaixa;

    printf("Digite a quantidade de comprimidos necessaria: ");
    scanf("%d", &qtdComprimidos);

    
    printf("\nDigite a quantidade de comprimidos por caixa: ");
    scanf("%d", &unidadesNaCaixa);


    int qtdNecessaria = divisaoInteiraArr(qtdComprimidos, unidadesNaCaixa);
    printf("\nSerao necessarias %d caixas.", qtdNecessaria);



    return 0;
}