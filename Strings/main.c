#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *frase = (char*)malloc(40*sizeof(char));
    char *nomeArq = (char*)malloc(15*sizeof(char));
    char *palavra = (char*)malloc(30*sizeof(char));
    char *fragmentos;
    FILE *arq;
    int total;

    printf("Digite o nome do arquivo: \n");
    scanf(" %s",nomeArq);
    arq = fopen(nomeArq,"r");

    printf("Qual palavra vai procurar?: \n");
    scanf(" %s",palavra);

    //escrever na tela o conteudo do arquivo
    while(fscanf(arq," %[^\n]",frase) != EOF){
        printf("Fase: %s\n",frase);

        //contar vogais na frase
        total=0;
        for (int pos=0; pos < strlen(frase); pos++){
            if (frase[pos] == 'a' ||
                frase[pos] == 'e' ||
                frase[pos] == 'i' ||
                frase[pos] == 'o' ||
                frase[pos] == 'u')
                {
                    total++;
                }
        }
        printf("Vogais na frase: %d\n\n",total);

        fragmentos = strtok(frase," ,;_!?.:");

        while (fragmentos != NULL){
            printf("Palavra: %s\n",fragmentos);
            if (strcmp(fragmentos,palavra) == 0){
                printf("Resposta: Achou a palavra\n");
            }

            fragmentos = strtok(NULL,",;_!?.:");
        }
    }

    free(palavra);
    free(frase);
    free(nomeArq);
    return 0;
}
