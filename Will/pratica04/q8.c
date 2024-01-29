#include <stdio.h>



int main(){

    int nIteracoes;
    int iteracaoAtual = 1;
    int contadorDaLinha = 1;

    printf("Digite o numero de iteracoes (min 1, max 40): ");
    scanf("%d", &nIteracoes);

    if (nIteracoes <= 40 && nIteracoes >= 1){
        while (iteracaoAtual <= nIteracoes){
            while (contadorDaLinha <= iteracaoAtual){
                printf("%d ", contadorDaLinha);
                contadorDaLinha += 1;
            }
            contadorDaLinha = 1;
            iteracaoAtual += 1;
            printf("\n");
        }
    }
    else{
        printf("Limite nao respeitado!");
    }



    return 0;
}