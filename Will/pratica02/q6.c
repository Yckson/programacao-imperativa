#include <stdio.h>


double calcularQuadrado(float n){

    return n * n;

}

double calcularImc(float peso, float altura){

    double imc = peso / calcularQuadrado(altura);
    return imc;

}

int main(){

    float peso, altura;
    double imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);

    printf("\nDigite o altura (m): ");
    scanf("%f", &altura);

    imc = calcularImc(peso, altura);

    printf("\nImc da pessoa (kg / m^2): %.2f", (float) imc);


    return 0;
}