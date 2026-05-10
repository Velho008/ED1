#include <stdio.h>
/*  Exercício 4 — Swap manual (sem função)
    Declare duas variáveis inteiras
    Use ponteiros para trocar os valores dentro da main
    Não use variável auxiliar tradicional (use manipulação via ponteiros)    */

int main()
{
    int valor1 = 8;
    int valor2 = 42;

    int *ptr1, *ptr2;

    ptr1 = &valor1;
    ptr2 = &valor2;

    //isso aqui faz a troca sem usar variavel temporaria
    *ptr1+=*ptr2;
    *ptr2= *ptr1 - *ptr2;
    *ptr1-=*ptr2;
    
    /*
    Troca sem variável auxiliar:
    1) soma os valores em ptr1
    2) recupera o valor original de ptr1 em ptr2
    3) recupera o valor original de ptr2 em ptr1
    */

    printf("valor 1: %d, valor 2: %d", *ptr1, *ptr2);

    return 0;

}