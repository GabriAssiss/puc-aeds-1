#include <stdio.h>
#include <stdlib.h>

double potencia(int n, int pot, double result){
    if(pot == 1){
        printf("%f", result);
        return result;
    }
    else if(pot > 1){
    result = result * n;
    pot--;
    potencia(n, pot, result);
    }
}

int main()
{
    int n, pot;

    printf("Digite um numero:\n");
    scanf("%d", &n);
    printf("Digite seu expoente:\n");
    scanf("%d", &pot);

    double result = n;
    potencia(n, pot, result);

    return 0;
}
