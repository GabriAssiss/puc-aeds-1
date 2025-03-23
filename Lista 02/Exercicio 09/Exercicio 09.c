#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int w, x, y, z;
    double r;
    printf("Insira o valor X:\n");
    scanf(" %d", &x);
    printf("Insira o valor Y:\n");
    scanf(" %d", &y);
    printf("Insira o valor Z:\n");
    scanf(" %d", &z);

    printf("Escolha o tipo de media que voce deseja:\n");
    scanf(" %d", &w);
    switch(w){
    case 1:
        printf("Media Geometrica");
        r = x + y + z;
        r = sqrt(r);
        break;
    case 2:
        printf("Media Ponderada");
        r = (x + 2 * y + 3 * z) / 6;
        break;
    case 3:
        printf("Media Harmonica");
        r = 3 / ((1 / x) + (1 / y) + (1 / z));
        break;
    case 4:
        printf("Media Aritmetica");
        r = (x + y + z) / 3;
        break;
    default:
        printf("Erro! Insira um valor valido.\n");
    }
    if(0 > r <= 4){
        printf("O resultado sera %lf.", r);
    }
    return 0;
}
