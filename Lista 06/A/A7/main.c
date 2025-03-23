#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *f, *f2;
  char linha[256];

  f = fopen("arquivo-01.txt", "r");
  f2 = fopen("arquivo-01_copia.txt", "w");

  while (fgets(linha, 256, f) != NULL) {
    fprintf(f2, "%s", linha);
  }

  fclose(f);
  fclose(f2);
  return 0;
}
