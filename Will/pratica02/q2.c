#include <stdio.h>
#include <math.h>

/*

    A função calcularQtdComprimidos pode ser reutilizada, mas o ideal seria que ela tivesse um nome diferente, com parâmetros mais genéricos, para uma uma melhor read-ability do código. Nesse caso, resolvi trocar o nome da função para "divisãoInteiraArr" para divisão inteira arredondada.

    int calcularQtdComprimidos(int qComprimidos, int unidsNaCaixa){
    int qtdNecessaria = (int) ceil( (float) qComprimidos / unidsNaCaixa );
    return qtdNecessaria;
}
*/

int divisaoInteiraArr(int dividendo, int divisor){
    
    int quociente = (int) ceil( (float) dividendo / divisor );

    return quociente;
}


int main(){
    int totalAlunos, alunosPTurma;

    printf("Digite o numero total de alunos matriculados: ");
    scanf("%d", &totalAlunos);

    printf("\nDigite o numero maximo de alunos p/ turma: ");
    scanf("%d", &alunosPTurma);

    int nTurmas = divisaoInteira(totalAlunos, alunosPTurma);

    printf("\nTotal de turmas formadas: %d", nTurmas);



    return 0;
}