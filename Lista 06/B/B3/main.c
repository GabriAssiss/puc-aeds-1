#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Gato{
  char nome[64], tipo[64], nome_cientifico[64];
  int peso, cativeiro;
};
int main()
{
  FILE *f;
  char linha[256];
  int count = 0;

  f = fopen("arquivo01.txt","r");

  while(fgets(linha, 200, f) != NULL){
  struct Gato gato;
    count++;
    char *caract;
    caract = strtok(linha, ";");
    strcpy(gato.nome, caract);

    caract = strtok('\0', ";");
    strcpy(gato.nome_cientifico, caract);

    caract = strtok('\0', ";");
    strcpy(gato.tipo, caract);

    caract = strtok('\0', ";");
    gato.peso = atoi(caract);

    caract = strtok('\0', ";");
    gato.cativeiro = atoi(caract);

    printf("Gato: %d\n" , count);
    printf("Nome popular: %s\n", gato.nome);
    printf("Nome cient�fico: %s\n", gato.nome_cientifico);
    printf("Indica��o do animal: %s\n", gato.tipo);
    printf("Peso m�ximo: %d\n", gato.peso);
    printf("Idade m�xima em cativeiro: %d\n", gato.cativeiro);
  }

  fclose(f);
  return 0;
}
