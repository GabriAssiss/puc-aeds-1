#include <stdio.h>
#include <stdlib.h>

void primo(int m, int *p1, int *p2);
int main()
{
    // Função main que solicita ao usuário o valor de m, chama o procedimento primo e depois imprime o resultado
    int m2, pr1, pr2;

    printf("Digite um valor:\n");
    scanf(" %d", &m2);

    primo(m2, &pr1, &pr2);
    printf("%d e o maior numero primo menor que %d.\n", pr1, m2);
    printf("%d e o menor numero primo maior que %d.\n", pr2, m2);
    return 0;
}

void primo(int m, int *p1, int *p2){
    // procedimento que recebe como parâmetro um inteiro m,passado por valor, e dois outros inteiros, p1 e p2, passados por referência.
    // Declaração de varíaveis
    int aux = m - 1, divisor = aux - 1;
    // Laço de repetição ´para cálculo de p1
    while( divisor != 1){
        if(aux % divisor == 0){
            aux--;
            }
        divisor--;
        }
    *p1 = aux;
    aux = m + 1;
    divisor = m;
    // Laço de repetição para cálculo de p2
    while( divisor != 1){
        if(aux % divisor == 0){
            aux++;
            divisor = aux - 1;
            }
        divisor--;
        }
    *p2 = aux;
}

