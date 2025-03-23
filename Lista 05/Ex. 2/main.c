#include <stdio.h>
#include <stdlib.h>

/*
Descri��o: o procedimento tem por objetivo receber e preencher um vetor com as notas
de uma turma de 10 alunos..
Entrada: notas_alunos[i] (float)
Sa�da: float
*/
void preencheNotas(float notas_alunos[10]){
    printf("Digite as notas de seus alunos:\n");
    for(int i = 0; i < 10; i++){
        scanf("%f", &notas_alunos[i]);
    }
}

/*
Descri��o: o procedimento tem por objetivo receber um vetor
preenchido com as notas, calcular a m�dia da turma e contar quantos alunos obtiveram nota acima
da m�dia
Entrada: notas_alunos2 (float)
Sa�da: float
*/
void calculaMedia(float *notas_alunos2){
    float media = 0, aux;
    int cont = 0;
    for(int f = 0; f < 10; f++){
        if(notas_alunos2[f] > 6){
            cont += 1;
        }
        aux = notas_alunos2[f];
        media = (media + aux);
    }
    media = media / 10;
    printf("%d alunos ficaram acima da media\n", cont);
    printf("A media dos alunos sera %f\n", media);
}

/*
Descri��o: a fun��o tem por objetivo declarar um vetor com valores digitados e acionar os
procedimentos.
Sa�da: vetor com as notas (float)
*/
int main()
{
    float notas[10];

    preencheNotas(&notas);

    calculaMedia(&notas);

    return 0;
}
