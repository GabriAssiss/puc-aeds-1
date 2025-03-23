#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1, x2, y1, y2;
    printf("Digite o x do primeiro par ordenado:\n");
    scanf("%f", &x1);
    printf("Digite o y do primeiro par ordenado:\n");
    scanf("%f", &y1);
    printf("Digite o x do segundo par ordenado:\n");
    scanf("%f", &x2);
    printf("Digite o y do segundo par ordenado:\n");
    scanf("%f", &y2);

    double d1, d2, r;
    d1 = ((x2 - x1) * (x2 - x1) + ( y2 - y1) * ( y2 - y1));
    d2 = ((x2 - x1) + ( y2 - y1)) * -1;
    r = d1 / d2;
    printf("O %.2f sera a distancia euclidiana entre os pontos %.2f, %.2f e %.2f, %.2f", r, x1, y1, x2, y2);
    return 0;
}
