#include <stdio.h>

const int QTD_VENDEDORES = 300;


double media (float vendasRealizadas[], int qtdVendedores){
    double somaTotal = 0;
    for (int posVendaAtual = 0; posVendaAtual < qtdVendedores; posVendaAtual++){
        somaTotal += vendasRealizadas[posVendaAtual];
    }

    return (double) somaTotal/qtdVendedores;
}

int vendedoresAbaixoMedia(float vendasRealizadas[], int qtdVendedores, float media){
    int qtdAbaixoMedia = 0;
    for (int posVendaAtual = 0; posVendaAtual < qtdVendedores; posVendaAtual++){
        if (vendasRealizadas[posVendaAtual] < media){
            qtdAbaixoMedia++;
        }
    }

    return qtdAbaixoMedia;
}

int main (){
    float vendas[QTD_VENDEDORES];
    for (int posVendaAtual = 1; posVendaAtual <= QTD_VENDEDORES; posVendaAtual++){
        printf("Digite o valor da venda do vendedor %d: ", posVendaAtual);
        scanf("%f", &vendas[posVendaAtual-1]);
    }

    printf("A media de vendas eh: %.2f\n", media(vendas, QTD_VENDEDORES));
    printf("A quantidade de vendedores que venderam abaixo da media eh: %d\n", vendedoresAbaixoMedia(vendas, QTD_VENDEDORES, media(vendas, QTD_VENDEDORES)));



    return 0;
}