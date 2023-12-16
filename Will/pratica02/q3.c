#include <stdio.h>

float calcularQuad(float n){
    return n * n;
}

float calculcarCubo(float n){
    return n * calcularQuad(n);
}


int main(){

    float num, numAoCubo;

    printf("Digite um numero para elevar ao cubo: ");
    scanf("%f", &num);

    numAoCubo = calculcarCubo(num);

    printf("%f ao cubo: %f", num, numAoCubo);


    return 0;
}