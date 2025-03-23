#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Descrição: a função tem por objetivo receber um vetor de caracter por parâmetro que representa um endereço
de e-mail para validar se o e-mail é válido.
Entrada: conta[64] (char)
Saída: inteiro
*/
char Email(char conta[64]){
    int a;
    for(int i = 0; i < strlen(conta); i++){
        if(conta[i] == '@'){
            printf("A posicao do @ dentro do vetor e %d\n", i);
            a = i;
            break;
        }
        else{
            a = -1;
        }
    }
    return a;
}

/*
Descrição: a função tem por objetivo pedir ao usuário que insira um endereço de e-mail e depois chamar a
função passando esse e-mail por parâmetro.
Entrada: email[64] (char)
Saída: inteiro
*/
int main()
{
    char email[64];
    int retorno = 0;
    printf("Digite seu endereço de email:\n");
    scanf("%s", email);
    retorno = Email(email);
    if (retorno != -1){
        printf("Email valido!");
    }
    else{
        printf("Email invalido. Retorno: %d", retorno);
    }
    return 0;
}
