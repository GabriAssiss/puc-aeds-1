#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Palavra
{
    int contar;
    char palavra[60];
};
/* O procedimento tem como objetivo contar o
número de palavras que são repetidas no texto e imprima a contagem de cada palavra repetida
juntamente com sua frequência
Entrada: Array string(char)
Saída: char e int
*/
void contarRepetidas(char string[])
{
    char *tex;
    struct Palavra palavras[200];
    int contWords = 0;
    tex = strtok(string, " ");

    while (tex != NULL && contWords < 200)
    {
        int found = 0;
        for (int i = 0; i < contWords; i++)
        {
            if (strcmp(tex, palavras[i].palavra) == 0)
            {
                palavras[i].contar++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(palavras[contWords].palavra, tex);
            palavras[contWords].contar = 1;
            contWords++;
        }

        tex = strtok(NULL, " ");
    }
    for (int i = 0; i < contWords; i++)
    {
        printf("A palavra '%s' apareceu %d vez(es)\n", palavras[i].palavra, palavras[i].contar);
    }
}

int main()
{
    char texto[256];
    printf("Digite o texto:\n");
    scanf("%[^\n]s", texto);
    contarRepetidas(texto);
    return 0;
}
