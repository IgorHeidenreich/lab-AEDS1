#include <stdio.h>
#include <stdlib.h>

void imprimirAesterisco(int a){
    if (a==10) return;
    for (int i=0; i<=a; i++){
        printf("*");
    }
    printf("\n");
    imprimirAesterisco(a+1);
}

int main()
{
    printf("*\n");
    imprimirAesterisco(1);
    return 0;
}
