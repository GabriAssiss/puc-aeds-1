#include <stdio.h>
#include <stdlib.h>

void teste(int n2, int *b, int *k);
int main()
{
    int n, b2, k2;
    // Fun��o main que solicita ao usu�rio o valor de n
    printf("Digite o valor de n:\n");
    scanf(" %d", &n);
    // Chamada de procedimento criado e depois imprime o resultado
    teste(n, &b2, &k2);
    printf("Menor:%d\nMaior:%d", b2, k2);
    return 0;
}

void teste(int n2, int *b, int *k){
    //  Procedimento que recebe um valor n passado �por valor� e dois inteiros b e k passados �por refer�ncia".
    int divisor, cont = 0;
    divisor = 1;
    // Condicional e la�o repetidor para c�lculo do menor divisor,
    // Em caso de n�mero n positivo
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
        // C�lculo para maior divisor
        *k = n2 / *b;
    }
    // Condicional e la�o repetidor para c�lculo do menor divisor,
    // Em caso de n�mero n negativo
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
    // C�lculo para maior divisor
    *k = n2 / *b;
    }
}
