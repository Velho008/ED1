#include <stdio.h>
/*  Exercício 3 — Incremento indireto
    Declare uma variável inteira

    Use um ponteiro para:
        somar 5
        multiplicar por 2
        
    Imprima o resultado final
    Atenção: Não acessar diretamente a variável (somente via ponteiro).    */


int main()
{
    int valor = 8;
    int *ptr = &valor;

    *ptr+=5;
    *ptr*=2;

    printf("%d", *ptr);

    return 0;
}