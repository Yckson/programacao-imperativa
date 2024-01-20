#include <stdio.h>

int obterInverso(int num){
    int unidade; int dezena; int centena; int copiaNum;

    centena = num / 100;
    copiaNum = num - centena * 100;

    dezena = copiaNum / 10;
    copiaNum = copiaNum - dezena * 10;

    unidade = copiaNum;

    return unidade * 100 + dezena * 10 + centena;
}

char verificarTamanho(int num1, int num2){
    if (num1 < num2){
        return 'm';
    }
    else if (num1 > num2){
        return 'M';
    }
    else{
        return 'I';
    }

}

int main (){
    int numero; int numeroInvertido;

    printf("Digite um numero inteiro de tres digitos (exemplo: 123): ");
    scanf("%d", &numero);

    numeroInvertido = obterInverso(numero); 

    switch (verificarTamanho(numero, numeroInvertido)){
        case 'm':
            printf("\nNumero gerado maior que o numero lido (%d < %d).", numero, numeroInvertido);
            break;
        
        case 'M':
            printf("\nNumero gerado menor que o numero lido (%d > %d).", numero, numeroInvertido);
            break;
        
        case 'I':
            printf("\nNumero gerado igual ao numero lido (%d = %d).", numero, numeroInvertido);
            break;
        default:
            printf("Erro ao computar os numeros! Verifique o numero fornecido e tente novamente");
    }
    


    return 0;
}