#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b){
    if (a<b) return 0;
    else if (a>=b) return 1+divide(a-b,b);
    return 0;
}

int main()
{
    printf("%d",divide(15,3));
    return 0;
}
