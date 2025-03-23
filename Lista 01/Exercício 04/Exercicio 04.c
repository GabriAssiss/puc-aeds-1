#include <stdio.h>
#include <stdlib.h>

int main()
{
    int brancos, nulos, validos;
    printf("Digite a quantidade de votos validos:\n");
    scanf("%d", &validos);
    printf("Digite a quantidade de votos brancos:\n");
    scanf("%d", &brancos);
    printf("Digite a quantidade de votos nulos:\n");
    scanf("%d", &nulos);

    float porc_v, porc_b, porc_n, total;
    total = validos + brancos + nulos;
    porc_v = (validos / total) * 100;
    porc_b = (brancos / total) * 100;
    porc_n = (nulos / total) * 100;
    printf("Porcentagem de votos validos:%.2f\n", porc_v);
    printf("Porcentagem de votos brancos:%.2f\n", porc_b);
    printf("Porcentagem de votos nulos:%.2f\n", porc_n);
    return 0;
}
