#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Descri��o: a fun��o tem por objetivo receber um vetor de caracter por par�metro que representa um endere�o
de e-mail para validar se o e-mail � v�lido.
Entrada: conta[64] (char)
Sa�da: inteiro
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
Descri��o: a fun��o tem por objetivo pedir ao usu�rio que insira um endere�o de e-mail e depois chamar a
fun��o passando esse e-mail por par�metro.
Entrada: email[64] (char)
Sa�da: inteiro
*/
int main()
{
    char email[64];
    int retorno = 0;
    printf("Digite seu endere�o de email:\n");
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
