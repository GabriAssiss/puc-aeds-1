#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Gato{
  char nome[64], tipo[64], nome_cientifico[64];
  int peso, t_cativeiro;
};

int main()
{
  FILE *f, *f2;
  char linha[256];

  f = fopen("arquivo-01.txt","r");
  f2 = fopen("arquivo-01.bin","wb");

  while(fgets(linha, 256, f) != NULL){
  struct Gato gatos;
    char *caracteristica;

    caracteristica = strtok(linha, ";");
    strcpy(gatos.nome, caracteristica);
    caracteristica = strtok('\0', ";");
    strcpy(gatos.nome_cientifico, caracteristica);
    caracteristica = strtok('\0', ";");
    strcpy(gatos.tipo, caracteristica);
    caracteristica = strtok('\0', ";");
    gatos.peso = atoi(caracteristica);
    caracteristica = strtok('\0', ";");
    gatos.t_cativeiro = atoi(caracteristica);

    fwrite(&gatos, sizeof(struct Gato), 1, f2);
  }

  fclose(f);
  fclose(f2);
  return 0;
}
