#include <stdio.h>
#include <stdlib.h>

int somar(int n,int m, int soma){
    if(n <= m){
        soma = soma + n;
        n++;
        somar(n,m, soma);
    }
    else{
        printf("%d", soma);
        return soma;
    }
}

int main()
{
    int n, m, soma = 0;

    printf("Digite o menor numero:\n");
    scanf("%d", &n);
    printf("Digite o maior numero:\n");
    scanf("%d", &m);
    somar(n,m, soma);

    return 0;
}
