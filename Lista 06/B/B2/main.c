#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Notas{
  int nota;
  int nota2;
  int nota3;
};
struct Aluno{
  char nome[50];
  int matricula;
  struct Notas notas;
};
int main(void) {
  struct Aluno alunos[5];
  int maior, maior_indice;
  FILE *arq;
  for(int i = 0; i < 5; i++){
    int media = 0;
    printf("Digite o nome do aluno:\n",i);
    scanf("%s",alunos[i].nome);
    printf("Digite a matricula do aluno:\n",i);
    scanf("%d",&alunos[i].matricula);
    printf("Digite a nota 01 do aluno:\n",i);
    scanf("%d",&alunos[i].notas.nota);
    printf("Digite a nota 02 do aluno: \n",i);
    scanf("%d",&alunos[i].notas.nota2);
    printf("Digite a nota 03 do aluno: \n",i);
    scanf("%d",&alunos[i].notas.nota3);
    media = (alunos[i].notas.nota + alunos[i].notas.nota2 + alunos[i].notas.nota3) / 3;

   if(media > maior){
     maior = media;
     maior_indice = i;
   }
  }
  printf("O aluno com maior media foi: %s\n",alunos[maior_indice].nome);
  printf("As suas notas foram: %d, %d, %d\n",alunos[maior_indice].notas.nota,alunos[maior_indice].notas.nota2,alunos[maior_indice].notas.nota3);
  printf("A media foi: %d\n",maior);
  arq = fopen("arquivo.bin","wb");
  fwrite(&alunos[maior_indice],sizeof(struct Aluno),1,arq);
  fclose(arq);
  return 0;
}
