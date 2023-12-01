#include <stdio.h>

int main (){
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("O antecessor: %d\n", num - 1);
    printf("O sucessor: %d", num + 1);
    
    return 0;

}