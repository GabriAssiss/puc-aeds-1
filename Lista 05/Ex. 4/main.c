#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Descrição: a função tem por objetivo validar uma senha que
atendaaos critérios de segurança, como ter pelo menos 8 caracteres, conter pelo menos uma
letra maiúscula, uma letra minúscula, um número e um caractere especial.
Entrada: senha (char)
Saída: mensagem validando/invalidando
*/
int main(){

    char senha[50], x;
    printf("Digite uma senha:\n");
    scanf("%s", &senha);
    x = strlen(senha);
    if(x < 8){
        printf("Senha invalida!\n");
        return -1;
    }
    for(int i = 0; i < strlen(senha); i++){
        printf("%c\n", senha[i]);
        if(senha[i] == 'A' || senha[i] == 'B' || senha[i] == 'C' || senha[i] == 'D' || senha[i] == 'E' || senha[i] == 'F' ||
           senha[i] == 'G' || senha[i] == 'H' || senha[i] == 'I' || senha[i] == 'J' || senha[i] == 'K' || senha[i] == 'L' ||
           senha[i] == 'M' || senha[i] == 'N' || senha[i] == 'O' || senha[i] == 'P' || senha[i] == 'Q' || senha[i] == 'R' ||
           senha[i] == 'S' || senha[i] == 'T' || senha[i] == 'U' || senha[i] == 'V' || senha[i] == 'W' || senha[i] == 'X' ||
           senha[i] == 'Y' || senha[i] == 'Z'){
            break;
           }
        else if(i == strlen(senha) - 1){
            printf("Senha invalida\n");
            return -1;
        }
    }
    for(int i = 0; i < strlen(senha); i++){
        printf("%c\n", senha[i]);
        if(senha[i] == '1' || senha[i] == '2' || senha[i] == '3' || senha[i] == '4' || senha[i] == '5' || senha[i] == '6' ||
           senha[i] == '7' || senha[i] == '8' || senha[i] == '9' || senha[i] == '0'){
            break;
           }
        else if(i == strlen(senha) - 1){
            printf("Senha invalida\n");
            return -1;
        }
    }
    for(int i = 0; i < strlen(senha); i++){
        printf("%c\n", senha[i]);
        if(senha[i] == '@' || senha[i] == '$' || senha[i] == '%' || senha[i] == '&' || senha[i] == '!' || senha[i] == '?' ||
        senha[i] == '_'){
            printf("Senha valida!");
            break;
           }
        else if(i == strlen(senha) - 1){
            printf("Senha invalida\n");
            return -1;
        }
    }

    return 0;

}
