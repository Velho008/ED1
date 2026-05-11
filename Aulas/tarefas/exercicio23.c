#include <stdio.h>
/*  Exercício 7 — Maior elemento do vetor
    Implemente:
        int maior(int *v, int tamanho);

    Use apenas ponteiros (sem v[i])
    Retorne o maior valor    */

int maior(int *v, int tamanho)
{
    int maior = *v; //nao usei 0 pq e se o vetor for somente negativo?
    for (int i = 0; i < tamanho; i++)
    {
        if (*v > maior)
        {
            maior = *v;
        }
        v = (v+1);
    }
    return maior;
}

int main()
{
    int v[5] = {10, 20, 30, 40, 50};
    printf("Maior: %d", maior(v, 5));

    return 0;
}