#include <stdio.h>

int main(){
    float temperaturaC;

    /* Para converter Celsius para Fahrenheit:

        1. Multiplicar o valor fonecido por 1.8;
        2. Somar 32 ao valor obtido.

    */

   printf("Digite o valor da temperatura em Celsius: ");
   scanf("%f", &temperaturaC);

   printf("\n Temperatura convertida para Fahrenheit: %.2f", temperaturaC * 1.8 + 32);




    return 0;
}