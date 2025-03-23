#include <stdio.h>
#include <stdlib.h>

int main()
{
    float quant_litros, dist_percorrida_km, consumo_medio ;
    printf("Digite a quantidade de litros abastecidos:\n");
    scanf(" %f", &quant_litros);
    printf("Digite a distancia percorrida, em quilometros, desde o ultimo abastecimento:\n");
    scanf(" %f", &dist_percorrida_km);
    consumo_medio = dist_percorrida_km / quant_litros;
    printf("O consume medio de gasolina do carro sera %d.2f km/l", consumo_medio);
    return 0;
}
