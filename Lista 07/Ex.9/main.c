#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iterativo(char string[]){
  int soma = 0;
  for(int i = 0; i < strlen(string); i++){
    soma++;
  }
  return soma;
}

int recursivo(char string[], int i){
  if(strlen(string) < i){
    return 0;
  }
  else if(strlen(string) > i){
    i++;
    recursivo(string, i);
  }
  else
   return i;
}

int main(){

  char string[200];

  printf("Digite algo:\n");
  scanf("%s", &string);

  printf("%d\n",iterativo(string));
  printf("%d\n",recursivo(string, 0));
  return 0;
}
