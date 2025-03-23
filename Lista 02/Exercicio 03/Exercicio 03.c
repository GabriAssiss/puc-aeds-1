#include <stdio.h>
#include <stdlib.h>

int main()
{
    float preco, x;
    char inicial;
    printf("Digite a inicial do estado desejado:\n");
    scanf("%c", &inicial);


    printf("Digite o preco do produto:R$");
    scanf("%f", &preco);
    while (preco < 0){
    printf("Digite o preco do produto:R$");
    scanf("%f", &preco);
    }
    switch(inicial){
        case 'M':
        printf("O estado selecionado foi Minas Gerais.\n");
        x = preco * 1.07;
        break;
        case 'S':
        printf("O estado selecionado foi Sao Paulo.\n");
        x = preco * 1.12;
        break;
        case 'R':
        printf("O estado selecionado foi Rio de Janeiro.\n");
        x = preco * 1.15 ;
        break;
        case 'E':
        printf("O estado selecionado foi Espirito Santo.\n");
        x = preco * 1.08;
        break;
        default:
        printf("Erro! Estado não encontrado!");
    }
    printf("O preco final sera R$%.2f", x);
     return 0;
}
