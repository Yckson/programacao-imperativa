#include <stdio.h>
#include <math.h>

double calcularArea(float lado){
    return lado * lado;
}

double calcularPerimetro(float lado){
    return lado * 4;
}

double calcularDiagonal(float lado){
    return sqrt(2 * (lado * lado));
}


void solicitarEntrada(float *valor){ /* Foi a alternativa encontrada evitar muita repeticao de codigo.*/
    printf("\nDigite a medida de um dos lados do quadrado (m): ");
    scanf("%f", valor);
}



int exibirMenu (){

    int opcao; float lado;

    printf("===================================MENU===================================\n");
    printf("  Escolha uma das seguintes opcoes para realizar com o quadrado:\n");
    printf("    1 -- Calcular area\n");
    printf("    2 -- Calcular perimetro\n");
    printf("    3 -- Calcular diagonal\n");
    printf("\n Insira a opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            solicitarEntrada(&lado);
            printf("\n A area do quadrado vale: %.2f m^2", (float) calcularArea(lado));
            break;
        case 2:
            solicitarEntrada(&lado);
            printf("\n O perimetro do quadrado vale: %.2f m", (float) calcularPerimetro(lado));
            break;

        case 3:
            solicitarEntrada(&lado);
            printf("\n A diagonal do quadrado vale: %.2f m", (float)  calcularDiagonal(lado));
            break;
        
        default:
            printf("\n Opcao invalida! Tente novamente.\n\n\n");
            return exibirMenu();
    }

    return 0;
}


int main (){
    
    return exibirMenu();
}