#include <stdio.h>
#include <ctype.h>



int main (){
    int qtdCandidatos = 1, qtdAprovados = 0;
    int qtdQuestMat, qtdQuestPort;
    float notaRedacao;
    char continuar;

    do{
        printf("Digite a quantidade de questoes de portugues acertadas para o candidato %d: ", qtdCandidatos);
        scanf("%d", &qtdQuestPort);
        printf("Digite a quantidade de questoes de matematica acertadas para o candidato %d: ", qtdCandidatos);
        scanf("%d", &qtdQuestMat);
        printf("Digite a nota na prova de redacao do candidato %d: ", qtdCandidatos);
        scanf("%f", &notaRedacao);

        if ((float) qtdQuestMat / 35 >= 0.6 && (float) qtdQuestPort / 50 >= 0.8 && notaRedacao >= 7){
            qtdAprovados += 1;
        }
        qtdCandidatos+=1;

        printf("\n\nDeseja incluir as notas de outro candidato? (S/N): ");
        scanf(" %c", &continuar);
    }
    while (toupper(continuar) == 'S');
    printf("A quantidade de candidatos aprovados foi: %d", qtdAprovados);



    return 0;
}