#include <stdio.h>
/*  Exercício 6 — Modificação por função
    Implemente uma função:
        void dobra(int *x);
    A função deve dobrar o valor de x
    Teste na main
    Verifique: o que acontece se passar sem ponteiro?    */

void dobra(int *x)
{
    *x *= 2;
}

int main()
{
    int valor = 42;

    int *ptr = &valor;

    dobra(ptr);

    printf("%d", *ptr);

/*  se a funcao dobrar fosse assim: 
    void dobra(int x)
    {
        x *= 2;
    }   
    o x seria = 2x somente dentro da funcao, não ia alterar o valor da variavel que foi passada    */

    return 0;
}