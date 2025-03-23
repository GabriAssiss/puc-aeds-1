#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Digite um valor A:\n");
    scanf("%d", &a);
    printf("Digite um valor B:\n");
    scanf("%d", &b);
    printf("Digite um valor C:\n");
    scanf("%d", &c);
    if (a <= 0 || b <= 0){
        printf("Valor invalido.");
    }
    else if (c % a == 0 && c % b == 0){
        printf("%d e divisivel por ambos.", c);
    }
    else if(c % a == 0 || c % b == 0){
        printf("%d e divisivel por um.", c);
    }
    else{
        printf("%d nao e divisivel.", c);
    }
    return 0;
}
