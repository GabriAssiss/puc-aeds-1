#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor_produto, total = 0, quant, quant_total = 0, x = 0;
    char continuar;
    while(x == 0){
    printf("Digite o preco do produto que voce deseja, em R$:\n");
    scanf(" %f", &valor_produto);
    printf("Digite a quantidade do produto:\n");
    scanf(" %f", &quant);
    quant_total = quant_total + quant;
    valor_produto = quant * valor_produto;
    total = total + valor_produto;
    printf("Digite 'N' se voce deseja parar o programa:\n");
    scanf(" %c", &continuar);
    switch(continuar){
    case 'N':
        x = 1;
        break;
    case 'n':
        x = 1;
        break;
    if (x = 1)
        break;
    }
    }
    printf("Voce comprou %.2f produtos os quais custaram no total R$%.2f", quant_total, total);
    return 0;
}
