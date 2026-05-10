#include <stdio.h>
/*  Exercício 5 — Vetor com ponteiros
    Dado um vetor:
    int v[5] = {10, 20, 30, 40, 50};
    Faça:
        Percorra usando ponteiro (não use índice)
        Imprima os valores
        Some todos os elementos usando apenas aritmética de ponteiros
    Dica: use *(p + i) ou incremento de ponteiro    */

int main()
{
    int v[5] = {10, 20, 30, 40, 50};
    int soma = 0;
    int *ptr, *ptr2;
    ptr2 = &soma;
    ptr = v;

    for(int i=0; i < ((sizeof(v))/sizeof(v[0])); i++)
    {
        printf("%d\n", *ptr);
        *ptr2 += *ptr; //vai fazendo a soma
        ptr=ptr+1; //passa o ponteiro pro proximo indice com aritmetica de ponteiro
    }

    printf("soma: %d", *ptr2);

    return 0;
}