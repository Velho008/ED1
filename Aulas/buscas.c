#include <stdio.h>

/*
algoritmos de buscas são usados para encontrar um elemento em uma estrutura de dados
para otimizar a complexidade de um algoritmo de busca, siga a lista abaixo

dados ordenados -> busca binária
dados não ordenados -> busca linear

busca linear -> O(n)
busca binária -> O(log n)
*/

int buscaLinear(int vetor[], int tamanho, int chave) 
{
    int posicaoEncontrada = -1; // Valor padrão: chave não encontrada

    for (int indice = 0; indice < tamanho; indice++) // Percorre o vetor do início ao fim
    {
        if (vetor[indice] == chave) // Se a chave for encontrada, atualiza a posição encontrada
        {
            posicaoEncontrada = indice; // Atualiza a posição encontrada, mas continua procurando para encontrar a última ocorrência
            //caso fosse inserido um break aqui, o algoritmo retornaria a PRIMEIRA ocorrência da chave no vetor
        }
    }
    //esse algoritmo retorna a ULTIMA ocorrência da chave no vetor, caso haja mais de uma ocorrência
    return posicaoEncontrada;
}

int buscaBinaria(int vetor[], int tamanho, int chave) 
{
    int inicio = 0;
    int fim = tamanho - 1; // Índice do último elemento do vetor

    while (inicio <= fim) 
    {
        int meio = (inicio + fim) / 2; // Calcula o índice do elemento do meio

        if (vetor[meio] == chave) // Se a chave for encontrada
        {
            return meio; // Retorna a posição da chave encontrada
        }

        if (chave < vetor[meio]) // Se a chave for menor que o elemento do meio
        {
            fim = meio - 1;      // Busca na metade esquerda
        } else 
        {
            inicio = meio + 1;   // Busca na metade direita
        }
    }

    return -1; // Chave não encontrada
}