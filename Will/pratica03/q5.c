#include <stdio.h>

int verificarDivisibilidade(int num, int denominador){
    return !(num % denominador);
    /* Um detalhe da linguagem C é que, como tipos boleanos não existem de forma nativa, 0 é interpretado como FALSE e 1 ou qualquer outro número diferente de zero é interpretado como verdadeiro. Assim sendo, se a negação for usada antes de um valor inteiro, esse valor se torna 0 (falso) e antes do 0 se torna 1 (verdadeiro). Isso torna o processo de solução da questão muito mais simples e economiza um pouco de tempo (poderia ser reescrito como " num % denominador == 0 ").*/
}

int main (){

    int num; int divisor1; int divisor2;
    /* num --> N; divisor1 --> A; divisor2 --> B */

    printf("Insira os valores para o numerador N e para os divisores A e B, respectivamente:\n");
    printf("N: ");
    scanf("%d", &num);
    printf("A: ");
    scanf("%d", &divisor1);
    printf("B: ");
    scanf("%d", &divisor2);

    if (verificarDivisibilidade(num, divisor1) && verificarDivisibilidade(num, divisor2)){
        printf("Atende a condicao!");
    }
    else{
        printf("Nao atende a condicao!");
    }




    return 0;
}