#include <stdio.h>
#include <stdlib.h>

/*
Descrição: o procedimento tem por objetivo preencher 2 vetores, com 10
elementos cada com valores aleatórios entre 10 e 20.
Entrada x1 e y1 (inteiros)
Saída: inteiro
*/
preencheValores(int x1[10], int y1[10]){
    int i, a;
    printf("Digite 10 valores para x:\n");
    for(i = 0; i < 10; i++){
        a = rand()%20;
        if(a < 10){
            a = a + 10;
        }
        x1[i] = a;
        printf("%d\n", x1[i]);
    }
    printf("Digite 10 valores para y:\n");
    for(i = 0; i < 10; i++){
        a = rand() % 20;
        if(a < 10){
            a = a + 10;
        }
        y1[i] = a;
        printf("%d\n", y1[i]);
    }
}
/*
Descrição: o procedimento tem por objetivo receberer
 dois vetores previamente preenchidos e gerar um novo vetor com os elementos desses 2
vetores intercalados de tal forma que nas posições ímpares do novo vetor estejam os elementos
do primeiro vetor e nas posições pares os elementos do segundo vetor recebido por parâmetro e
e exibir o conteúdo do vetor.
Entrada: x2 e y2 (inteiro)
Saída: inteiro
*/
procedimentoParaVetorUnico(int x2[10], int y2[10]){
    int z[20], j, m = 0;
    printf("----------\n");
    for(j = 0; j < 20; j++){
        if(j % 2 == 0 && j != 0){
            m++;
    }
        if(j % 2 == 0){
            z[j] = y2[m];
    }
        else{
            z[j] = x2[m];
    }
    printf("%d\n", z[j]);
    }
}

/*
Descrição: a função tem por objetivo chamar os procedimentos.
Entrada: x e y (inteiro)
Saída: inteiro
*/
int main()
{
    int x[10], y[10];
    preencheValores(&x, &y);
    procedimentoParaVetorUnico(&x, &y);
    return 0;
}
