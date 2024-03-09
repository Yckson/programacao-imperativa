#include <stdio.h>
#include <ctype.h>


int main (){
    int media = 7;
    char continuar;
    float nota;
    

    do{
        printf("\nDigite a nota do aluno: ");
        scanf("%f", &nota);

        if (nota >= media){
            printf("\nAluno aprovado!");
        }
        else{
            if (nota > 3 && media != 5){
                media = 5;
                printf("\nAluno em recuperacao!");
                continue;
            }
            else{
                printf("\nAluno reprovado!");
            }
        }
        media = 7;
        printf("\nDeseja continuar (S/N): ");
        scanf(" %c", &continuar);
        if(toupper(continuar) != 'S'){
            break;
        }



    }
    while (1);



    return 0;
}