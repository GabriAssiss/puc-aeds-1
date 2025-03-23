#include <stdio.h>
#include <stdlib.h>

int recursiva(int x, int cont){
    printf("%d ", x);
    if(cont == 0 && x != 5){
        x++;
        recursiva(x, cont);
    }
    else if(cont == 0 && x == 5){
        printf("%d ", x);
        cont++;
    }
    if(cont == 1 && x != 1){
        x--;
        recursiva(x, cont);
    }
    else
        return x;

}


int main()
{
    int x = 1;
    int cont = 0;

    recursiva(x, cont);

    return 0;
}

