#include <stdio.h>



int main (){
    int qtdCandidatos = 1, qtdAprovados = 0;
    int qtdQuestMat, qtdQuestPort;
    float notaRedacao;

    while (1){
        printf("Digite a quantidade de questoes de portugues acertadas para o candidato (\"-1 para sair\") %d: ", qtdCandidatos);
        scanf("%d", &qtdQuestPort);
        if (qtdQuestPort < 0) break;
        else{
            printf("Digite a quantidade de questoes de matematica acertadas para o candidato %d: ", qtdCandidatos);
            scanf("%d", &qtdQuestMat);

            printf("Digite a nota na prova de redacao do candidato %d: ", qtdCandidatos);
            scanf("%f", &notaRedacao);

            if ((float) qtdQuestMat / 35 >= 0.6 && (float) qtdQuestPort / 50 >= 0.8 && notaRedacao >= 7){
                qtdAprovados += 1;
            }
            qtdCandidatos+=1;


        }
    }
    printf("A quantidade de candidatos aprovados foi: %d", qtdAprovados);



    return 0;
}