#include <stdio.h>
#include <stdlib.h>


int funcaoRecursiva(int n){
    printf("%d ", n);
    if(n != 0){
        n--;
        funcaoRecursiva(n);
    }
    else{
        return n;
    }
}
int main()
{
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);
    funcaoRecursiva(n);
    return 0;
}
