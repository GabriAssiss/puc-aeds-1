#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char linha[200];
  int media, max = 0, min = 9999, somatorio = 0, count = 0;
  FILE *f;

  f = fopen("arquivo-01.txt", "r");

  while (fgets(linha, 200, f) != NULL) {
    int peso;
    char *peso_ch;
    strtok(linha, ";");
    strtok('\0', ";");
    strtok('\0', ";");
    peso_ch = strtok('\0', ";");
    peso = atoi(peso_ch);
    if (max < peso)
      max = peso;

    if (min > peso)
      min = peso;

    somatorio += peso;
    count++;
  }
  fclose(f);
  f = fopen("saida.txt", "r");
  media = somatorio / count;
  fprintf(f, "maximo: %d\n", max);
  fprintf(f, "minimo: %d\n", min);
  fprintf(f, "soma: %d\n", somatorio);
  fprintf(f, "quatidade de gatos: %d\n", count);
  fprintf(f, "media: %d\n", media);

  fclose(f);
  return 0;
}
