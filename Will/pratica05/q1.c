#include <stdio.h>

int main() {
    float pesoIni, pesoObj;
    int mes;

    printf("Digite o peso inicial (kg): ");
    scanf("%f", &pesoIni);

    printf("Digite o peso objetivado (kg): ");
    scanf("%f", &pesoObj);

    if (pesoObj >= pesoIni) {
        printf("Erro: O peso almejado deve ser menor que o peso inicial.\n");
        return 1;
    }

    printf("\nMes     Peso Alcancado\n");
    for (mes = 1; pesoIni > pesoObj; mes++) {
        pesoIni -= 5;
        
        if (pesoObj > pesoIni) {
            printf("%d          %.2f kg\n", mes, pesoObj);
        } else {
            printf("%d          %.2f kg\n", mes, pesoIni);
        }
    }

    return 0;
}
