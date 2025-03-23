#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior, menor, x, y, ampl;

    for (x = 0; x < 5; x++){
        printf("Digite o numero:\n");
        scanf("%d", &y);
        if (y > maior){
            maior = y;
        }
        if (y < menor){
            menor = y;
        }
    }
    ampl = maior - menor;
    printf("O menor numero sera %d, o maior sera %d, a amplitude sera %d.", menor, maior, ampl);
    return 0;
}
