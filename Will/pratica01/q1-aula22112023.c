#include <stdio.h>

int main (){
    int num;
    int espera;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("O antecessor: %d\n", num - 1);
    printf("O sucessor: %d", num + 1);
    scanf("%d", &espera);
    return 0;

}