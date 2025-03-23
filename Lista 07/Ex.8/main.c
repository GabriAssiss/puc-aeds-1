#include <stdio.h>
#include <stdlib.h>

int iterativo(int n){
  if(n < 2){
    return n;
  }
  else{
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
}
int recursivo(int n){
  if(n < 2){
    return n;
  }
  else{
    return recursivo(n-1) + recursivo(n-2);
  }
}


int main(){

  int n;

  printf("digite o k-esimo termo:\n");
  scanf("%d", &n);
  printf("%d\n",iterativo(n));
  printf("%d\n",recursivo(n));
  recursivo(n);
  return 0;
}
