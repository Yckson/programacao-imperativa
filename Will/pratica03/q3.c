#include <stdio.h>

float notaComPeso(float nota, float peso){
    return nota * peso;
}

float mediaPonderada(float somaNotas, float somaPesos){
    return somaNotas/somaPesos;
}




int main(){
    float nota1; float nota2; float nota3; float media;
    
    printf("Digite as notas 1, 2 e 3 do aluno (respectivamente): \n");
    scanf(" %f",&nota1);
    scanf(" %f",&nota2);
    scanf(" %f",&nota3);

    media = mediaPonderada(notaComPeso(nota1, 1) + notaComPeso(nota2, 2) + notaComPeso(nota3, 3), 6);
    if (media < 7){
        if (media < 5){
            
            printf("O aluno esta REPROVADO! (media: %.2f)", media);
        } 
        else {
            printf("O aluno esta EM RECUPERACAO! (media: %.2f)", media);
        }
    }
    else{
        printf("O aluno esta APROVADO! (media: %.2f)", media);
    }





 return 0;   
}