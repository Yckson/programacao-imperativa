#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Aluno Aluno;


const int NUM_ALUNOS = 3;


struct Aluno {
    char nome[31];
    float notas[3];
    float frequencia;
};




float calcularMediaAlunos(float nota1, float nota2, float nota3){
    return (nota1 + nota2 + nota3) / 3;
}

char* verificarSituacaoAluno(float media, float mediaTurma, float frequencia){
    if (media > mediaTurma && frequencia > 65){
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main(){
    Aluno alunos[NUM_ALUNOS];
    char nomeAluno[31] = "";
    int nota1 = 0;
    int nota2 = 0;
    int nota3 = 0;
    float mediaTurma = 0;
    float frequencia = 0;
    char situacao[11] = "REPROVADO";
    float mediaAluno = 0;

    for (int contAluno = 0; contAluno < NUM_ALUNOS; contAluno++){
        printf("Digite o nome do aluno %d: ", (contAluno + 1));
        fgets(nomeAluno, 31, stdin);
        nomeAluno[strcspn(nomeAluno, "\n")] = '\0';
        fflush(stdin);

        printf("Digite a primeira nota do aluno %d: ", (contAluno + 1));
        scanf(" %d", &nota1);

        printf("Digite a segunda nota do aluno %d: ", (contAluno + 1));
        scanf(" %d", &nota2);

        printf("Digite a terceira nota do aluno %d: ", (contAluno + 1));
        scanf(" %d", &nota3);

        printf("Digite a frequencia do aluno %d (em %%): ", (contAluno + 1));
        scanf(" %f", &frequencia);
        fflush(stdin);

        strcpy(alunos[contAluno].nome, nomeAluno);
        alunos[contAluno].notas[0] = nota1;
        alunos[contAluno].notas[1] = nota2;
        alunos[contAluno].notas[2] = nota3;
        mediaTurma += (nota1 + nota2 + nota3);
        alunos[contAluno].frequencia = frequencia;
        system("cls");
    }

    mediaTurma = mediaTurma / (NUM_ALUNOS * 3);

    printf("Media da turma: %.2f\n", mediaTurma);
    printf("--------------------------------------\n");
    printf("\nNumero do Aluno\tNome\tNota 1\tNota 2\tNota 3\tMedia\tSituacao\n");

    for (int posAlunoAtual = 0; posAlunoAtual < NUM_ALUNOS; posAlunoAtual++){

        mediaAluno = calcularMediaAlunos(alunos[posAlunoAtual].notas[0], alunos[posAlunoAtual].notas[1], alunos[posAlunoAtual].notas[2]);

        printf("%d", (posAlunoAtual + 1));
        printf("\t\t%s", alunos[posAlunoAtual].nome);
        printf("\t%.2f", alunos[posAlunoAtual].notas[0]);
        printf("\t%.2f", alunos[posAlunoAtual].notas[1]);
        printf("\t%.2f", alunos[posAlunoAtual].notas[2]);
        printf("\t%.2f", mediaAluno);
        printf("\t%s\n", verificarSituacaoAluno(mediaAluno, mediaTurma, alunos[posAlunoAtual].frequencia));
        

    }




    return 0;
}