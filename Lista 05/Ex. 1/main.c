#include <stdio.h>
#include <stdlib.h>
//https://replit.com/@dunkrells23
/*
Descri��o: a fun��o tem por objetivo ler da entrada padr�o 5 n�meros reais
e armazen�-los em um vetor.
Entrada: numeros[n] (float)
Sa�da: o dobro dos n�meros (float)
*/
int main()
{
    int numeros[5];
    int dobro_numeros[5];

    printf("Digite 5 numeros:\n");

    for(int n = 0; n < 5; n++){
        scanf("%d", &numeros[n]);
        dobro_numeros[n] = numeros[n] * 2;
    }
    for(int n = 0; n < 5; n++){
        printf("%d\n", dobro_numeros[n]);
    }
    return 0;
}
