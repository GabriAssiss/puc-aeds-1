#include <stdio.h>
#include <stdlib.h>


void troca(int *x, int *y){
    // Atribui��o de par�metros, tal que &a = *x e &b = *y
    int aux;
    // Declara��o de vari�vel
    aux= *x;
    // aux recebe 5
    *x = *y;
    // Os endere�os de x e y s�o iguais, logo x e y recebem 2
    *y = aux;
    // Endere�o de y recebe 5
}
int main()
{
    int a=5, b;
    // Declara��o de vari�veis a e b, e atribui��o de valores para a
    b=2;
    // Atribui��o de valores para b
    troca(&a, &b);
    // Chamada de procedimento com argumentos
    printf("\n%i, %i", a, b);
    // Sa�da de valores, tal que a = 2 e y = 5
    return 0;
}
// a = 2 e b = 5
