#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *f, *f2, *f3;
  char linha[300];
  int max = 0, count = 0, min = 0;

  f2 = fopen("arquivo-02.txt", "r");

  fgets(linha, 200, f2);
  min = atoi(strtok(linha, ";"));
  max = atoi(strtok('\0', ";"));

  fclose(f2);

  f = fopen("arquivo-01.txt", "r");
  f3 = fopen("arquivo-03.txt", "w");

  while (fgets(linha, 300, f) != NULL) {
    int peso;
    char *peso_ch, *nome;
    nome = strtok(linha, ";");
    strtok('\0', ";");
    strtok('\0', ";");
    strtok('\0', ";");
    peso_ch = strtok('\0', ";");
    peso = atoi(peso_ch);
    if (peso >= min && peso <= max) {
      fprintf(f3, "%s\n", nome);
    }
  }

  fclose(f);
  fclose(f3);
  return 0;
}
