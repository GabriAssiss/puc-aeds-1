#include <stdio.h>
#include <stdlib.h>

int main()
{
    char planetas;
    float v, a, t;

    while (1){
    printf("Digite o tempo, em milissegundos:\n");
    scanf(" %f", &t);
    if (t > 0){
        break;
    }
    }
    printf("Digite a inicial do planeta, em letra maiúscula:\n");
    scanf(" %c", &planetas);
    printf("O planeta selecionado foi ");
    switch(planetas){
    case 'T':
        a = 9.807;
        printf("Terra.\n");
        printf("A velocidade de queda será %f m/s", v = a * t/1000);
        break;
    case 'V':
        a = 8.87;
        break;
        printf("Venus.\n");
        printf("A velocidade de queda será %f m/s", v = a * t/1000);
    case 'M':
        a = 3.7;
        printf("Mercurio.\n");
        printf("A velocidade de queda será %f m/s", v = a * t/1000);
        //  A divisão por mil ocorre, pois na física o tempo tem que estar em segundos.
        break;
    default:
        printf("Erro! Digite a inicial de um dos planetas!\n");
    }
    return 0;
}
