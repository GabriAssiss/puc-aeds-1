#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Na linha abaixo, as vari�veis a,b,c e d foram atribu�das como inteiras, com a letra d recebendo o valor 1.
    int a,b,c,d=1;
    // Aqui a letra "a" recebe o valor -2.
    a = -2;
    // E a letra "b", o valor de (-2)*(-2) = 4.
    b = a*a;
    // Como os sinais ++ est�o ap�s a vari�vel, o valor de "d" ser� usado e depois incrementado.
    // Ou seja c = 1.
    c = d++;
    // d = 1 + 5 = 6.
    // Ap�s "c" ser usado, seu valor passar� a ser 2. Ou seja, c = 2.
    d = c++ + 5;
    // Como os sinais "++" est�o antes da vari�vel, c ser� incrementado antes de ser usado.
    // Portanto, "c" que recebia 2, passar� a ser c = 3.
    d = ++c + 5;
    // Fazendo a opera��o: d = 3 + 5 = 8
    printf ("%d %d %d %d", a, b, c, d);
    // A partir daqui, as vari�veis ser�o mostradas com os seguintes valores: -2, 4, 3, 8
    return 0;
}
