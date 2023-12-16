#include <stdio.h>

void celsiusParaFahr(float Cel, float *Fah){

    *Fah = (Cel * 9/5) + 32;
    return;

}

void celsiusParaKel(float Cel, float *Kel){

    *Kel = Cel + 273.5;
    return;

}






int main(){

    float temperaturaC, temperaturaKel, temperaturaFah;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperaturaC);

    celsiusParaFahr(temperaturaC, &temperaturaFah);
    celsiusParaKel(temperaturaC, &temperaturaKel);

    printf("\nTemperatura em Fahrenheit: %.2f\n", temperaturaFah);
    printf("Temperatura em Kelvin: %.2f\n", temperaturaKel);



    return 0;
}