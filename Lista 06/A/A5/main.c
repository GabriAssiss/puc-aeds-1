#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *f, *f2;
  char linha[200];
  int max = 0, min = 0;

  f2 = fopen("arquivo-02.txt", "r");

  fgets(linha, 200, f2);
  min = atoi(strtok(linha, ";"));

  max = atoi(strtok('\0', ";"));

  fclose(f2);

  f = fopen("arquivo-01.txt", "r");
  f2 = fopen("arquivo-02.txt", "a");

  fprintf(f2, "\n");
  while (fgets(linha, 200, f) != NULL) {
    char *peso_ch, *nome;
    int peso;

    nome = strtok(linha, ";");
    strtok('\0', ";");
    strtok('\0', ";");
    strtok('\0', ";");
    peso_ch = strtok('\0', ";");
    peso = atoi(peso_ch);
    if (peso >= min && peso <= max) {
      fprintf(f2, "%s\n", nome);
    }
  }

  fclose(f);
  fclose(f2);
  return 0;
}
