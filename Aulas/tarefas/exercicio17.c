#include <stdio.h>
/*  Exercício 1 — Inspeção de memória
    Escreva um programa que:

        Declare:
            uma variável inteira
            uma variável float
            um ponteiro para cada tipo

        Atribua corretamente os endereços

        Imprima:
            valor da variável   */

int main()
{
    int valor = 80;
    float valorfloat = 5.8965854;
    int *ponteiroint;
    float *ponteirofloat;

    ponteiroint = &valor;
    ponteirofloat = &valorfloat;

    // valores
    printf("%d\n", *ponteiroint);
    printf("%.2f\n", *ponteirofloat);

    // endereços
    printf("%p\n", &valor);
    printf("%p\n", &valorfloat);

    return 0;
}