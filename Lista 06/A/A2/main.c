#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f = fopen("arquivo-01.txt", "r");

    if (f == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    char linha[100];
    char *token;
    char limite[2] = ";";


    while (fgets(linha, sizeof(linha), f) != NULL) {

        token = strtok(linha, limite);
        token = strtok(NULL, limite);
        printf("%s\n", token);
    }


    fclose(f);

    return 0;
}
