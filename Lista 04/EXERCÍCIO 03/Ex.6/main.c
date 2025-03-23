#include <stdio.h>
#include <stdlib.h>

void teste(int n2, int *b, int *k);
int main()
{
    int n, b2, k2;

    printf("Digite o valor de n:\n");
    scanf(" %d", &n);

    teste(n, &b2, &k2);
    printf("Menor:%d\nMaior:%d", b2, k2);
    return 0;
}

void teste(int n2, int *b, int *k){
    int divisor, cont = 0;
    divisor = 1;
    if(n2 > 0){
        while(divisor < n2){
            if (n2 % divisor == 0){
                    cont++;
                    if(cont == 2){
                        break;
                    }
            }
            divisor++;
        }
        *b = divisor;
        *k = n2 / *b;
    }
    else if(n2 < 0){
        divisor = n2;
        while(divisor < 0){
            if(n2 % divisor == 0){
                cont++;
                if(cont == 2)
                    break;
            }
            divisor++;
        }
    *b = divisor;
    *k = n2 / *b;
    }
}
