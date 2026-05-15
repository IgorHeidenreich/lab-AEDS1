#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, atual, prox, menor, posMenor, aux;

    printf("Digite o total de numeros: ");
    scanf("%d", &N);

    int numeros[N];

    // leitura dos valores
    for (int i = 0; i < N; i++) {
        printf("Valor: ");
        scanf("%d", &numeros[i]);
    }

    // mostra vetor original
    printf("\nVetor original:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", numeros[i]);
    }

    // selection sort
    for (atual = 0; atual < N - 1; atual++) {

        // assume que o menor é o atual
        menor = numeros[atual];
        posMenor = atual;

        // procura menor elemento no restante do vetor
        for (prox = atual + 1; prox < N; prox++) {

            if (numeros[prox] < menor) {
                menor = numeros[prox];
                posMenor = prox;
            }
        }

        // troca os valores
        aux = numeros[atual];
        numeros[atual] = numeros[posMenor];
        numeros[posMenor] = aux;
    }

    // mostra vetor ordenado
    printf("\n\nNumeros ordenados:\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}
