#include <stdio.h>

double calcularImc(float massa, float altura){

    return massa / (altura * altura);
}

int main (){

    float massa; float altura; float imc;

    printf("Para calcular o IMC, insira os valores da massa corporal e da altura, respectivamente: \n");
    printf("Massa (kg): ");
    scanf("%f", &massa);
    printf("Altura (m): ");
    scanf("%f", &altura);

    imc = (float) calcularImc(massa, altura);

    printf("\nIMC: %.1f\nClassificacao: ", imc);

    if(imc < 18.5){
        printf("Magreza.");
    }
    else if (imc <= 24.9){
        printf("Saudavel.");
    }
    else if (imc <= 29.9){
        printf("Sobrepeso.");
    }
    else if (imc <= 34.9){
        printf("Obesidade Grau I.");
    }
    else if (imc <= 39.9){
        printf("Obesidade Grau II (SEVERA)");
    }
    else{
        printf("Obesidade Grau III (MORBIDA)");
    }





    return 0;
}