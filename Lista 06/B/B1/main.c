#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
  int dia;
  int mes;
  int ano;
};
struct Pessoa{
  char nome[32];
  struct Data data;
};
int main(void) {
  char velho[32], novo[32];
  int idade_velho, idade_novo;
  struct Pessoa pessoas[6];
  FILE *f;
  f = fopen("pessoas.txt", "w");

  for(int i = 0; i < 6; i++){
    int dias = 0;
    printf("Escreva o nome: \n");
    scanf("%s", &pessoas[i].nome);
    printf("Escreva a data de nascimento:\n");
    scanf("%d %d %d", &pessoas[i].data.dia, &pessoas[i].data.mes, &pessoas[i].data.ano);
    dias = ((pessoas[i].data.mes * 30) + pessoas[i].data.dia + pessoas[i].data.ano * 365);
    if(idade_novo < dias){
      idade_novo = dias;
      strcpy(novo, pessoas[i].nome);
    }
    if(idade_velho > dias){
      idade_velho = dias;
      strcpy(velho, pessoas[i].nome);
    }
  }
  fprintf(f, "Pessoa mais nova: %s\n", novo);
  fprintf(f, "Pessoa mais velha: %s\n", velho);
  fclose(f);
  return 0;
}
