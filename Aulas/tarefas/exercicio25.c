#include <stdio.h>
/*  Exercício 9 — Inversão de vetor (in-place)
    Crie uma função:
        void inverte(int *v, int tamanho);

    Inverta os elementos do vetor
    Não use vetor auxiliar
    Use dois ponteiros (início e fim)
    
    Exemplo: [1, 2, 3, 4] → [4, 3, 2, 1]    */
//MEU MELHOR CODIGO DE ED1 ATÉ ENTÃO, tive que pensar mto pra fazer

void inverte(int *v, int tamanho)
{
    //não trata de overflow nem vetor nulo pq o exercicio não pede

    int *inicio, *fim;
    inicio = &v[0];
    fim = &v[tamanho - 1];

    for (int i = 0; i < tamanho/2; i++)
    {
        *inicio+=*fim;
        *fim = *inicio - *fim;
        *inicio-=*fim;

        inicio++;
        fim--;
    }  
}

int main()
{
    int v[5] = {1, 2, 3, 4, 5};

    inverte(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}