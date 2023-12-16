#include <stdio.h>
#include <math.h>


const float PI = 3.1415926535;

float calcularQuadrado(float n){

    return n * n;

}

float areaCirculo(float raio){

    float area = PI * calcularQuadrado(raio);
    return area;

}

int main(){

    float raio, area;

    printf("Digite o raio da circunferencia (m): ");
    scanf("%f", &raio);

    area = areaCirculo(raio);

    printf("A area da circunferencia e: %.2f m^2", area);



    return 0;
}