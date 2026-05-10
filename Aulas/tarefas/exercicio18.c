#include <stdio.h>
/*  Exercício 2 — Ponteiros cruzados
    Dado:
        int A = 10, B = 20;
        int *p1, *p2;
    
    Faça:
        p1 aponta para A, p2 aponta para B
        Imprima os valores apontados
        Troque os ponteiros (sem trocar os valores das variáveis)
        Imprima novamente
        
    Verifique: O que mudou? O que permaneceu igual?    */

int main()
{
    int A = 10, B = 20;
    int *p1, *p2, *temp;
    p1 = &A;
    p2 = &B;

    printf("Antes:\n");
    printf("p1 aponta para: %d\n", *p1);
    printf("p2 aponta para: %d\n", *p2);

    temp = p1;
    p1 = p2;
    p2 = temp;

    printf("\nDepois:\n");
    printf("p1 aponta para: %d\n", *p1);
    printf("p2 aponta para: %d\n", *p2);

    return 0;
}