#include <stdio.h>
#include <stdlib.h>

void apresentacao();
float somar(float x, float y);
void saida(float resultado_soma);
int main()
{
    apresentacao();
    return 0;
}
void apresentacao(){
    // função main que se encarregue de estabelecer o fluxo das chamadas das funções
    float n1, n2, soma;
    // Entrada de valores
    printf("Digite o valor 1:\n");
    scanf("%f", &n1);
    printf("Digite o valor 2:\n");
    scanf("%f", &n2);
    soma = somar(n1, n2);
    saida(soma);
}
float somar(float x, float y){
    float resultado;
    //  Função que recebe dois valores reais e retorna a soma dos dois parâmetros
    //  recebidos
    resultado = x + y;
    return resultado;
}
void saida(float resultado_soma){
    printf("O resultado da soma será: %f\n", resultado_soma);
    // Procedimento que receba um valor real relativo ao resultado da soma e o escreva na tela
}
