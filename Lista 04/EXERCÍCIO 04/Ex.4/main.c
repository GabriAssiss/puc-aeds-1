#include <stdio.h>
#include <stdlib.h>

int tempo_vida();

int main()
{
    int dia, mes, ano, dias_vividos;

    printf("Digite a data do seu ultimo aniversario:\n");
    // Entrada da data de �ltimo anivers�rio
    scanf("%d %d %d", &dia, &mes, &ano);

    tempo_vida(&dias_vividos);
    // Sa�da de dados - dias vividos relativo ao �ltimo anivers�rio
    printf("Voce viveu cerca de %d dias desde seu ultimo aniversario!\n", dias_vividos);
    return 0;
}

int tempo_vida(int *dias_vivo){

    int idade;
    //Fun��o que armazenada vari�vel parametrizada por refer�ncia.
    printf("Quantos anos voce tem?\n");
    // Entrada de valor 'idade'
    scanf(" %d", &idade);
    *dias_vivo = 365*idade;
    return 0;
}
