#include <stdio.h>
#include <stdlib.h>

int fatorial(int n, int fat){
    if(n == 0){
        fat = 1;
        printf("%d", fat);
        return n;

    }

    n--;
    if(n > 1){
        fat = fat * (n);
        fatorial(n, fat);
    }
    else{
        printf("%d", fat);
        return n;
    }
}

int main()
{
    int n;

    printf("Digite um numero:\n");
    scanf("%d", &n);

    int fat = n;

    fatorial(n, fat);

    return 0;
}
