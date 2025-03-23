#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y = 10, z = 0;
    printf("Digite um numero:\n");
    scanf(" %d", &x);
    while(1){
        x = x / y;
        z++;
        if (x == 0){
            break;
        }
    }
    printf("%d", z);
    return 0;
}
