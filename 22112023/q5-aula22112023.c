#include <stdio.h>

int main(){
    float distancia;
    float velocidadeMedia;
    
    printf("Digite a distancia a percorrer (km): ");
    scanf("%f", &distancia);

    printf("\nDigite a velocidade media esperada (km/h): ");
    scanf("%f", &velocidadeMedia);

    printf("\nTempo estimado de exercicio (corrida): %.1f h.", distancia / velocidadeMedia);



    return 0;
}