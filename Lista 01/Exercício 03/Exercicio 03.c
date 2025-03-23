#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    printf("Digite um numero para A:\n");
    scanf("%f", &a);
    c = a;
    printf("Digite um numero para B:\n");
    scanf("%f", &b);
    a = b;
    b = c;
    printf("Agora o valor de A e %.2f e o valor de B e %.2f.\n", a, b);
    return 0;
}
