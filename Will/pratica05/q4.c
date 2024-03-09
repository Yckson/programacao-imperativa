#include <stdio.h>

const int NUM_DE_ALUNOS = 3;
const int NUM_DE_AVALIACOES = 12;
const float NOTA_MIN = 7;
const int NOTA_APROVADO = 5;

int main() {
    int aprovados = 0;

    for (int aluno = 1; aluno <= NUM_DE_ALUNOS; aluno++) {
        int qtdNotasAprovadas = 0;

        for (int cont = 1; cont <= NUM_DE_AVALIACOES; cont++) {
            float nota;
            printf("Digite a nota da avaliacao %d do aluno %d: ", cont, aluno);
            scanf("%f", &nota);

            if (nota >= NOTA_MIN) {
                qtdNotasAprovadas++;
            }
        }

        if (qtdNotasAprovadas >= NOTA_APROVADO) {
            printf("Aluno %d foi aprovado!\n", aluno);
            aprovados++;
        } else {
            printf("Aluno %d foi reprovado.\n", aluno);
        }
    }

    printf("\nTotal de alunos aprovados: %d\n", aprovados);

    return 0;
}
