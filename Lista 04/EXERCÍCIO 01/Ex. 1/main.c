#include <stdio.h>
#include <stdlib.h>

int tempo_vida();

int main()
{
    int dia, mes, ano, dias_vividos;

    printf("Digite a data do seu ultimo aniversario:\n");
    scanf("%d %d %d", &dia, &mes, &ano);

    dias_vividos = tempo_vida();
    printf("Voce viveu cerca de %d dias desde seu ultimo aniversario!\n", dias_vividos);
    return 0;
}

int tempo_vida()
{
    int dias_vivo, idade;
    // A fun��o que tem por  objetivo receber a idade de uma pessoa e calcular e retornar o n�mero de dias por
    // ela vividos at� o seu �ltimo anivers�rio
    printf("Quantos anos voce tem?\n");
    scanf(" %d", &idade);
    // Entrada: idade da pessoa
    dias_vivo = 365*idade;
    // Sa�da: n�mero de dias vividos
    return dias_vivo;
}

// https://replit.com/@gabrielsouza215/Lista-04#Ex.7/main.c
