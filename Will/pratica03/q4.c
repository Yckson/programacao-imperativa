#include <stdio.h>

int obterInverso(int num){
    int unidade; int dezena; int centena; int copiaNum;
    if (num > 999 || num < 100){
        return 0;
        /*O "zero" serve como uma alternativa para o "false", para que quando o valor informado não as métricas exigidas, a função que verifica o tamanho entenda que isso é um erro e retorne o valor 'E'.*/
    }
    else{
        centena = num / 100;
        copiaNum = num - centena * 100;

        dezena = copiaNum / 10;
        copiaNum = copiaNum - dezena * 10;

        unidade = copiaNum;

        return unidade * 100 + dezena * 10 + centena;
    }
}

char verificarTamanho(int num1, int num2){
    /*Como, se tudo estiver inserido corretamente, o valor invertido será sempre maior que 0, a função será capaz de identificar o erro caso o valor do parâmetro do segundo numero seja igual à 0*/
    if (num2){
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
    else{
        return 'E';
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
            printf("Erro ao computar os numeros! Verifique o numero fornecido e tente novamente.");
    }
    


    return 0;
}