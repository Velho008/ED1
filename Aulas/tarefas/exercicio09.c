#include <stdio.h>
/*
Criar um programa que recebe o endereço de um número e imprime o valor desse número.
*/

void imprimeValor(int *ponteiro)
{
    printf("%d", *ponteiro);
}

int main()
{
    int numero = 8;
    imprimeValor(&numero);
    return 0;
}