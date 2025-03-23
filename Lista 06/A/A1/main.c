#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("arquivo-01.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir arquivo");
        return 1;
    }
    int linhas = 0;
    char caracteres;
    while(caracteres != EOF){
        caracteres = fgetc(f);
        if(caracteres == '\n'){
            linhas++;
        }
    }
    printf("Quantidade de linhas: %d", linhas);
    fclose(f);

    return 0;
}
