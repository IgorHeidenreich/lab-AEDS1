#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArquivo(FILE *arq, int quest, int alunos){

    fprintf(arq,"%d %d\n",quest,alunos);

    fclose(arq);

}

int main() {

    srand((unsigned)time(NULL));

    int totalQuest = 3+ (rand() % 8),
        totalAlunos = 1+ (rand() % 6),
        totalPontos = 1+ (rand() % 3);
    FILE *entrada fopen("entrada.txt","r");

    gerarArquivo(entrada,totalQuest,totalAlunos);
    entrada = fopen("entrada.txt","w");

    // Alocação dinâmica de memória
    char *gab = (char*)malloc(totalQuest * sizeof(char));
    // Aloca uma matriz 2D (alunos x questoes) linearizada
    char *sala = (char*)malloc(totalQuest * totalAlunos * sizeof(char));

    // 1. Preenche gabarito
    printf("\n--- Cadastro do Gabarito ---\n");
    for (int i = 0; i < totalQuest; i++) {
        printf("Letra da questao %d: ", (i + 1));
        // O espaço antes de %c ignora o \n (Enter) anterior
        scanf(" %c", (gab + i));
    }

    // 2. Preenche as respostas dos alunos
    printf("\n--- Respostas dos Alunos ---\n");
    for (int al = 0; al < totalAlunos; al++) {
        printf("Respostas do aluno %d: ", (al + 1));
        for (int q = 0; q < totalQuest; q++) {
            // O espaço antes de %c ignora o \n (Enter) anterior
            scanf(" %c", (sala + al * totalQuest + q));
        }
    }

    // 3. Calcula e exibe os pontos
    printf("\n--- Resultado Final ---\n");
    for (int al = 0; al < totalAlunos; al++) {
        totalPontos = 0;
        for (int q = 0; q < totalQuest; q++) {
            // Compara gabarito com a resposta do aluno
            if (*(gab + q) == *(sala + al * totalQuest + q)) {
                totalPontos += 2; // +2 pontos por resposta correta
            }
        }
        printf("Total de pontos do aluno %d: %d\n", (al + 1), totalPontos);
    }

    // Liberação da memória alocada
    free(gab);
    free(sala);

    return 0;
}
