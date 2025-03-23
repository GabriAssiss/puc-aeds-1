#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c, i, t;
    printf("Valor do capital investido, em reais:\n");
    scanf("%f", &c);
    printf("Valor da taxa de juros:\n");
    scanf("%f", &i);
    printf("Tempo de aplicação, em meses:\n");
    scanf("%f", &t);
    float j, m;
    j = (c * i * t) / 100;
    m = j + c;
    printf("Valor total acumulado: %.2f\n", m);
    printf("Juros rendidos: %.2f\n", j);

    return 0;
}
