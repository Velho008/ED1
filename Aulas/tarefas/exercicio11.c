#include <stdio.h>
/*
Criar uma função que recebe um array e um ponteiro, e altera os valores no array.
*/


void alterador(int array[], int *ponteiro)
{
    array[*ponteiro] = *ponteiro + 4;
}

void printaVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("valor %d: %d\n", i, vetor[i]);
    }
}

int main()
{
    int vetor[5];
    int valor = 1;
    //*ponteiro = 8; NÃO FAZER ISSO, aqui ele não aponta pra nenhuma variavel
    int *ponteiro = &valor;
    for (int i = 0; i < 5; i++)
    {
        vetor[i] = i;
    }

    printaVetor(vetor, 5);
    alterador(vetor, ponteiro);
    printaVetor(vetor, 5);
    return 0;
}