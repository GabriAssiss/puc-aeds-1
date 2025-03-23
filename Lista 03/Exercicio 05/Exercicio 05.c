#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    printf("Digite um numero:\n");
    scanf(" %d", &x);

    z = x;
    y = 0;
    while (z > 0){
        y = (y * 10) + (z % 10);
        z = z / 10;
    }
    printf("Numero digitado: %d\n Numero invertido: %d\n", x, y);
    if (x == y){
        printf("Os numeros sao palindramos.");
    }
    else{
        printf("Os numeros nao sao palindramos.");
    }
    return 0;
}
