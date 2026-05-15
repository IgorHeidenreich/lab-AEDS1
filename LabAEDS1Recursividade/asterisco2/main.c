#include <stdio.h>
#include <stdlib.h>

void imprimirAesterisco(int a){
    if (a==0) return;
    for (int i=0; i<=a; i++){
        printf("*");
    }
    printf("\n");
    imprimirAesterisco(a-1);
}

int main()
{
    imprimirAesterisco(3);
    printf("*");
    return 0;
}
