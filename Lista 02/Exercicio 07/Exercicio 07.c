#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2;
    double del;

    printf("Digite o coeficiente A:\n");
    scanf("%f", &a);
    printf("Digite o coeficiente B:\n");
    scanf("%f", &b);
    printf("Digite o coeficiente C:\n");
    scanf("%f", &c);

    del = (b * b) - (4 * a * c);
    del = sqrt(del);

    x1 = (-b + del) / (2 * a);
    x2 = (-b - del) / (2 * a);

    printf("%lf\n", del);
    printf("%f, %f", x1, x2);
    return 0;
}
