#include <stdio.h>
#include <stdlib.h>

void imprimirAesterisco(int a){
    if (a==1) return;
    for (int j = a-1; j<10; j++) printf(" ");
    for (int i=0; i<a; i++){
        printf("*");
    }
    printf("\n");
    imprimirAesterisco(a-1);
}

int main()
{
    imprimirAesterisco(10);
    printf("          *");
    return 0;
}
