#include <stdio.h>

const float PORCENT_JUROS = 0.1;


float calcularJuros(float valCompra, int meses){
    float juros = 0;
    for (int cont = 1; cont <= meses; cont++){
        juros += valCompra * PORCENT_JUROS;
    }
    return juros;
}

int main() {
    float valorCompra;
    int numMeses;

    printf("Digite o valor da compra: R$");
    scanf("%f", &valorCompra);

    if (valorCompra <= 300) {
        printf("Valor da compra nao permite parcelamento.\n");
        return 1;
    }

    printf("Digite o numero de meses de parcelamento (maximo 10): ");
    scanf("%d", &numMeses);

    if (numMeses <= 0 || numMeses > 10) {
        printf("Numero de meses invalido.\n");
        return 1;
    }

    float jurosAcumulado = calcularJuros(valorCompra, numMeses);
    float valorTotal = valorCompra + jurosAcumulado;
    float parcela = valorTotal / numMeses;

    printf("Compra R$: %.2f\n", valorCompra);
    printf("Pagamento em %d meses -- Juros: %.2f -- Total: %.2f -- Parcela %dx R$ %.2f", numMeses, valorCompra*PORCENT_JUROS, valorTotal, numMeses, parcela);



    return 0;

}