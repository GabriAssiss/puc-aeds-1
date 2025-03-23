#include <stdio.h>
#include <stdlib.h>

int funcaoRecursiva(int a, int b, int c,int cont){
    printf("%d ", c);
    if(c < b && cont == 0){
        c++;
        funcaoRecursiva(a, b, c, cont);
    }
    else if(c == b){
        cont++;
        printf("%d ", c);
    }
    if(cont == 1 && c != a){
        c--;
        funcaoRecursiva(a, b, c, cont);
    }
    else{
        return c;
    }
}

int main()
{
    int a, b, cont = 0;

    printf("Digite o menor numero: ");
    scanf("%d", &a);
    printf("Digite o maior numero: ");
    scanf("%d", &b);
    int c = a;
    funcaoRecursiva(a, b, c, cont);

    return 0;
}
