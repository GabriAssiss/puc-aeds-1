#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Na linha abaixo, as variáveis a,b,c e d foram atribuídas como inteiras, com a letra d recebendo o valor 1.
    int a,b,c,d=1;
    // Aqui a letra "a" recebe o valor -2.
    a = -2;
    // E a letra "b", o valor de (-2)*(-2) = 4.
    b = a*a;
    // Como os sinais ++ estão após a variável, o valor de "d" será usado e depois incrementado.
    // Ou seja c = 1.
    c = d++;
    // d = 1 + 5 = 6.
    // Após "c" ser usado, seu valor passará a ser 2. Ou seja, c = 2.
    d = c++ + 5;
    // Como os sinais "++" estão antes da variável, c será incrementado antes de ser usado.
    // Portanto, "c" que recebia 2, passará a ser c = 3.
    d = ++c + 5;
    // Fazendo a operação: d = 3 + 5 = 8
    printf ("%d %d %d %d", a, b, c, d);
    // A partir daqui, as variáveis serão mostradas com os seguintes valores: -2, 4, 3, 8
    return 0;
}
