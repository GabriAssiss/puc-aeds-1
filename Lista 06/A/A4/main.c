#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char linha[200];

    f = fopen("arquivo-01.txt","r");

    while(fgets(linha, 200, f) != NULL){
        int i;
        char *idade_ch;

        strtok(linha, ";");
        strtok('\0', ";");
        strtok('\0', ";");
        strtok('\0', ";");

        idade_ch =  strtok('\0', ";");
        i = atoi(idade_ch);
        if(i >= 10 && i <= 16){
            printf("%d\n",i);
        }

    }
    fclose(f);
    return 0;
}
