#include <stdio.h>
#include <stdlib.h>
// vou colocar como número mínimo o 0.
int main()
{
    int x;
    printf("Digite um numero inteiro:\n");
    scanf("%d", &x);
    printf("Os numeros menores que %d sao:\n", x);
    while (x != -10000){
        printf(" %d", --x);
    }

    return 0;
}
