#include <stdio.h>
#include <stdlib.h>
// Vou partir do pressuposto que o número inicial de passageiros é igual a 0.

int main()
{
    int n_passageiros_no_onibus = 0, n_passageiros_sairam, n_passageiros_entraram, x = 0;
    char desejo;

    while(x == 0){
        printf("O numero de passageiros no onibus e %d.\n", n_passageiros_no_onibus);
        printf("Numero de passageiros que entraram no onibus:\n");
        scanf(" %d",  &n_passageiros_entraram);
        if (n_passageiros_entraram < 0){
            printf("Valor invalido, o numero total de passageiros sera zerado.\n");
            n_passageiros_entraram = 0;
            n_passageiros_no_onibus  = 0;

        }
        n_passageiros_no_onibus = n_passageiros_no_onibus + n_passageiros_entraram;
        if   (n_passageiros_no_onibus == 0 && n_passageiros_entraram == 0){
            printf("Nao ha ninguem para sair.\n");
        }
        else{
            printf("Numero de passageiros que sairam:\n");
            scanf(" %d", &n_passageiros_sairam);
            if (n_passageiros_sairam < 0){
                printf("Valor invalido, o numero total de passageiros sera zerado.\n");
                n_passageiros_no_onibus = 0;
            }
            else{
                n_passageiros_no_onibus = n_passageiros_no_onibus - n_passageiros_sairam;
            }
        }
        printf("Deseja parar o programa? (Digite 'S' ou 's')\n");
        scanf(" %c", &desejo);
        switch (desejo){
        case 'S':
        printf("O programa será finalizado. Ha um total de %d passageiros no onibus.", n_passageiros_no_onibus);
        x = 1;
        break;
        case 's':
        printf("O programa será finalizado. Ha um total de %d passageiros no onibus.", n_passageiros_no_onibus);
        x = 1;
        break;
        }

    }
    return 0;
}
