#include <stdio.h>
/*
Implementar uma função que troca os valores de duas variáveis usando ponteiros.
*/

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int numero = 9;
    int numero2 = 123;
    printf("%d, %d\n", numero, numero2);
    troca(&numero, &numero2); // passo os endereços das variáveis; embora o ponteiro seja passado por valor,
                              // ele aponta para as variáveis originais, permitindo modificá-las
    printf("%d, %d\n", numero, numero2);

    return 0;
}