#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Descri��o: a fun��o tem por objetivo transformar uma string em sua vers�o mai�scula
Entrada: (const char[]) vetor, (int) tamanho
Sa�da: (char *) String mai�scula
*/
char* stringMaiuscula(char vetor[], int tamanho)
{
    char *cap = (char*)malloc((tamanho + 1) * sizeof(char));
    if (cap == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] >= 'a' && vetor[i] <= 'z')
        {
            cap[i] = vetor[i] - 32;
        }
        else
        {
            cap[i] = vetor[i];
        }
    }
    cap[tamanho] = '\0';

    return cap;
}

/*
Descri��o: declarar as vari�veis e chamar a fun��o.
Entrada: string (char)
Sa�da: string mai�scula
*/
int main(void)
{
    char *capitalizar, string[100];
    printf("Digite coisa: \n");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int tamanho = strlen(string);
    capitalizar = stringMaiuscula(string, tamanho);

    printf("%s\n", capitalizar);

    free(capitalizar);
    return 0;
}
