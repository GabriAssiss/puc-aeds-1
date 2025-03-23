#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, n3, x, m, s;
    printf("Digite um valor para N1: \n");
    scanf("%f", &n1);
    printf("Digite um valor para N2: \n");
    scanf("%f", &n2);
    printf("Digite um valor para N3: \n");
    scanf("%f", &n3);

    s = n1 + n2 + n3;
    m = s / 3;
    x = n1 * n2 * n3;
    printf("%.2f eh a soma dos dados\n", s);
    printf("%.2f eh a media dos dados\n", m);
    printf("%.2f eh o produto dos dados\n", x);
    return 0;
}
