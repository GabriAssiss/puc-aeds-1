#include <stdio.h>
#include <stdlib.h>


void troca(int *x, int *y){
    // Atribuição de parâmetros, tal que &a = *x e &b = *y
    int aux;
    // Declaração de variável
    aux= *x;
    // aux recebe 5
    *x = *y;
    // Os endereços de x e y são iguais, logo x e y recebem 2
    *y = aux;
    // Endereço de y recebe 5
}
int main()
{
    int a=5, b;
    // Declaração de variáveis a e b, e atribuição de valores para a
    b=2;
    // Atribuição de valores para b
    troca(&a, &b);
    // Chamada de procedimento com argumentos
    printf("\n%i, %i", a, b);
    // Saída de valores, tal que a = 2 e y = 5
    return 0;
}
// a = 2 e b = 5
