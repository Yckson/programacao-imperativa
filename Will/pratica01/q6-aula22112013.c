#include <stdio.h>

int main (){

    int num;

    printf("Digite o numero para a tabuada: ");
    scanf("%d", &num);

    for (int cont = 1; cont <= 10; cont++) {
        printf("\n    |     %d x %d = %d", num, cont, num * cont);
    }




    return 0;
}