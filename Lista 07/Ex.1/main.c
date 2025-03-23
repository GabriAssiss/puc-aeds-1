#include <stdio.h>
#include <stdlib.h>

// https://replit.com/@dunkrells23

int recursiva(int x){
    x++;
    printf("%d ", x);
    if(x == 5)
        return x;
    else
        recursiva(x);
}

int main()
{
    int x = 0;

    recursiva(x);

    return 0;
}
