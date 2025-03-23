#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linha_escolhida, x = 0, determinacao;
    int dias_semana = 0, sab = 0, dom = 0, i;
    printf("Digite o numero da linha de onibus que voce deseja:\n");
    scanf(" %d", &linha_escolhida);
    if (0 < linha_escolhida && linha_escolhida < 251){
        printf("Voce escolheu a linha %d.\n", linha_escolhida);
        determinacao = 1;
    }
    else if (250 < linha_escolhida && linha_escolhida < 501){
        printf("Voce escolheu a linha %d.\n",linha_escolhida);
        determinacao = 2;
    }
    else if (500 < linha_escolhida && linha_escolhida < 751){
        printf("Voce escolheu a linha %d.\n", linha_escolhida);
        determinacao = 3;
    }
    else if (750 < linha_escolhida && linha_escolhida < 1001){
        printf("Voce escolheu a linha %d.\n", linha_escolhida);
        determinacao = 4;
    }
    else{
        printf("Essa linha nao existe.\n");
        x = 1;
    }
    if(x == 0){
        printf("Digite '1' para os horarios dos dias de samana, '2' para os horarios de sabado ou '3' para os domingos:\n");
        scanf(" %d", &i);
        if (i == 1){
            dias_semana = 1;
        }
        else if(i == 2){
            sab = 2;
        }
        else if(i == 3){
            dom = 3;
        }
        else{
            printf("Voce digitou um numero invalido!");
        }
        switch(determinacao){
        case 1:
            if(dias_semana == 1){
                printf("O onibus ira partir as 5h30min.");
                break;
            }
            else if(sab == 2){
                printf("O onibus ira partir as 6h.");
                break;
            }
            else if (dom == 3){
                printf("O onibus ira partir as 8h");
                break;
                }
        case 2:
            if(dias_semana == 1){
                printf("O onibus ira partir as 5h40min.");
                break;
            }
            else if(sab == 2){
                printf("O onibus ira partir as 6h10min.");
                break;
            }
            else if (dom == 3){
                printf("O onibus ira partir as 7h50min");
                break;
            }
        case 3:
            if(dias_semana == 1){
                printf("O onibus ira partir as 5h20min.");
                break;
            }
            else if(sab == 2){
                printf("O onibus ira partir as 6h30min.");
                break;
            }
            else if (dom == 3){
                printf("O onibus ira partir as 8h15min");
                break;
            }
        case 4:
            if(dias_semana == 1){
                printf("O onibus ira partir as 4h30min.");
                break;
            }
            else if(sab == 2){
                printf("O onibus ira partir as 7h30min.");
                break;
            }
            else if (dom == 3){
                printf("O onibus ira partir as 9h.");
                break;
            }
        }
    }
    return 0;
}

