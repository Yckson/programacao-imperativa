#include <stdio.h>

int main(){
    int dose;
    int periodicidade;
    //const int qtdDoses = 4;
    
    printf("Digite o ano da primeira dose: ");
    scanf("%d", &dose);

    printf("\nDigite a periodicidade em anos: ");
    scanf("%d", &periodicidade);

    const int anoDose1 = dose;
    printf("\nOs proximos anos de vacinacao sao: \n");
    printf(" %d\n %d\n %d\n", dose + periodicidade, dose + 2*periodicidade, dose + 3*periodicidade);


    /*

        Metodo utilizando a estrutura for:

    
        for (int cont = 1; cont < qtdDoses; ++cont) {
            dose += periodicidade;
            printf(" %d\n", dose);
        }

    */

    
    return 0;
}