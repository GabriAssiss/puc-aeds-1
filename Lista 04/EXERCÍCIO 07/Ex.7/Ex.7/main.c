#include <stdio.h>
#include <stdlib.h>


void mostrar(float x, float y, float z);
float resultado2( float n1, float n2, float n3);
void retornar_referencia(float *num1, float *num2, float *num3, float *seg2);
void tres_valores(float *num1, float *num2, float *num3, float *pri, float *seg, float *ter);
float segundo_maior(float escrever_resultado);

int main()
{
    float a, b, c, resultado, primeiro, segundo, terceiro;
    // Entrada de parâmetros
    printf("Digite o valor a:\n");
    scanf(" %f", &a);
    printf("Digite o valor b:\n");
    scanf(" %f", &b);
    printf("Digite o valor c:\n");
    scanf(" %f", &c);
    // Chamada de procedimento
    mostrar(a, b, c);
    // Retorno de função
    resultado = resultado2(a, b, c);
    printf("\n%f", resultado);
    // Saída de dados float
    retornar_referencia(&a, &b, &c, &segundo);
    printf("\n%f", segundo);
    // Saída de dados float
    tres_valores(&a, &b, &c, &primeiro, &segundo, &terceiro);
    // Saída de dados em ordem crescente
    printf("\n%f\n%f\n%f\n", primeiro, segundo, terceiro);
    segundo_maior(resultado);
    // Retorno do segundo maior valor
    return 0;
}
void mostrar(float x, float y, float z){
    // Procedimento que recebe parâmetros por valor e mostra o resultado
    float vetor[1];
    // Calculo do segundo maior valor
    if ((x > y && x < z) || (x < y && x > z)){
        vetor[0] = x;
    }
    else if ((x < y && y < z) || (x > y && z < y)){
        vetor[0] = y;
    }
    else{
        vetor[0] = z;
    }
    // Saída do segundo maior valor
    printf("%f", vetor[0]);
}
float resultado2( float n1, float n2, float n3){
    //  Função que recebe parâmetros por valor e retorna o resultado para o main
    float vetor[1];
    // Calculo do segundo maior valor
    if ((n1 > n2 && n1 < n3) || (n1 < n2 && n1 > n3)){
        vetor[0] = n1;
    }
    else if ((n1 < n2 && n2 < n3) || (n1 > n2 && n3 < n2)){
        vetor[0] = n2;
    }
    else{
        vetor[0] = n3;
    }
    // Retorno do segundo maior valor
    return vetor[0];
}
void retornar_referencia(float *num1, float *num2, float *num3, float *seg2){
    // Procedimento que recebe os valores por parâmetro e retorna por referência o segundo maior para o main;
    float vetor[1];
    // Calculo do segundo maior valor
    if ((*num1 > *num2 && *num1 < *num3) || (*num1 < *num2 && *num1 > *num3)){
        vetor[0] = *num1;
    }
    else if ((*num1 < *num2 && *num2 < *num3) || (*num1 > *num2 && *num3 < *num2)){
        vetor[0] = *num2;
    }
    else{
        vetor[0] = *num3;
    }
    // Retorno por referência
    *seg2= vetor[0];
}
void tres_valores(float *num1, float *num2, float *num3, float *pri, float *seg, float *ter){
    float vetor[3];
    // Procedimento para ordenar três valores reais (passagem de parâmetro por referência)
    // Calculo do segundo maior valor
    if ((*num1 > *num2 && *num1 < *num3) || (*num1 < *num2 && *num1 > *num3)){
        vetor[1] = *num1;
        if(*num2 > *num3){
            // Cálculo do maior  e menor valores
            vetor[2] = *num2;
            vetor[0] = *num3;
        }
        else{
            // Cálculo do maior valor
            vetor[2] = *num3;
            vetor[0] = *num2;
        }
    }
    else if ((*num1 < *num2 && *num2 < *num3) || (*num1 > *num2 && *num3 < *num2)){
        vetor[1] = *num2;
        if(*num1 > *num3){
            // Cálculo do maior  e menor valores
            vetor[2] = *num1;
            vetor[0] = *num3;
        }
        else{
        // Cálculo do maior  e menor valores
            vetor[2] = *num3;
            vetor[0] = *num1;
        }
    }
    else{
        vetor[1] = *num3;
        if(*num1 > *num2){
            // Cálculo do maior  e menor valores
            vetor[2] = *num1;
            vetor[0] = *num2;
        }
        else{
            //Cálculo do maior  e menor valores
            vetor[2] = *num2;
            vetor[0] = *num1;
            }
        }
    // Retorno por referência
    *pri = vetor[0];
    *seg = vetor[1];
    *ter = vetor[2];
}
float segundo_maior(float escrever_resultado){
    // Função para escrever o resultado (o segundo maior valor lido)
    printf("%f", escrever_resultado);
    return 0;
}
