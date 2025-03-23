#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Descrição: a função tem por objetivo transformar uma string em sua versão maiúscula
Entrada: (const char[]) vetor, (int) tamanho
Saída: (char *) String maiúscula
*/
char* stringMaiuscula(char vetor[], int tamanho)
{
    char *cap = (char*)malloc((tamanho + 1) * sizeof(char));
    if (cap == NULL) {
        printf("Erro na alocação de memória!\n");
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
Descrição: declarar as variáveis e chamar a função.
Entrada: string (char)
Saída: string maiúscula
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
