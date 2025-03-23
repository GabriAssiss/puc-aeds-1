#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x, fatorial, y;

    printf("Digite um numero inteiro positivo:\n");
    scanf(" %lld", &fatorial);
    x = fatorial;
    y = fatorial;
    if (fatorial < 0){
        printf("Numero invalido.\n");
    }
    else if (fatorial == 0 || fatorial == 1){
        printf("O fatorial de %lld e 1", x);
    }
    else{
        while(1){
            fatorial = fatorial * (x - 1);
            x = --x;
            if (x == 1){
                printf("O fatorial de %lld e %lld.", y, fatorial);
                break;
            }
        }
    }


    return 0;
}
