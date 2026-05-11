#include <stdio.h>
/*  Exercício 10 — Intercalação de vetores
    Crie uma função:
        void intercala(int *v1, int *v2, int *v3, int n);

    Intercale os elementos de v1 e v2 em v3
    Resultado: v3 com tamanho 2n

    Exemplo:
    v1 = [1,3,5]
    v2 = [2,4,6]
    v3 = [1,2,3,4,5,6]
    
    Regra: usar apenas aritmética de ponteiros    */

void intercala(int *v1, int *v2, int *v3, int n)
{
    for (int i = 0; i < n; i++)
    {
        *v3 = *v1;
        v3++;
        *v3 = *v2;
        v3++;
        v1++;
        v2++;
    }
}

int main()
{
    int v1[3] = {1, 3, 5};
    int v2[3] = {2, 4, 6};
    int v3[6] = {0, 0, 0, 0, 0, 0};
    int *ptr;
    ptr = v3;

    intercala(v1, v2, v3, 3);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }

    return 0;
}