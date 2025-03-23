#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op, x, y, z;
    printf("Digite o valor X:\n");
    scanf("%d", &x);
    printf("Digite o valor Y:\n");
    scanf("%d", &y);
    printf("Escolha uma das opcões:\n");
    printf("1. soma\n2. subtracao\n3. multiplicacao\n4. divisao\n5. modulo\n");
    scanf("%d", &op);
    printf("Voce escolheu: ");
    switch(op){
    case 1:
        printf("somar\n");
        z = x + y;
        break;
    case 2:
        printf("subtrair\n");
        z = x - y;
        break;
    case 3:
        printf("multiplicar\n");
        z = x * y;
        break;
    case 4:
        printf("dividir\n");
        z = x / y;
        break;
    case 5:
        printf("modular\n");
        z = x % y;
        break;
    default:
        printf("Opçao invalida!");
    }
    printf("O resultado sera: %d", z);
    return 0;
}
