#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Na linha abaixo, as variáveis a,b,c e d foram atribuídas como inteiras, com a letra d recebendo o valor 1.
    int a,b,c,d=1;
    // Aqui a letra a recebe o valor -2
    a = -2;
    // E a letra b, o valor de (-2)*(-2) = 4
    b = a*a;
    // Como
    c = d++;
    d = c++ + 5;
    d = ++c + 5;
    printf ("%d %d %d %d", a, b, c, d);
    return 0;
}
