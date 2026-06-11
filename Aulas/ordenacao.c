#include <stdio.h>
//encontrar um elemento de um vetor é mais rapido se ele estiver ordenado.


int indiceMenorElemento(int vetor[], int tamanho, int indiceInicial)
{
    //procura o indice do menor elemento a partir de indiceInicial
    int indiceMenor = indiceInicial;

    for (int indiceAtual = indiceInicial + 1; indiceAtual < tamanho; indiceAtual++)
    {
        if (vetor[indiceMenor] > vetor[indiceAtual])
        {
            indiceMenor = indiceAtual;
        }
    }
    return indiceMenor;
}

void selectionSort(int vet[], int tam)
{ 
    //ordena um vetor usando o selection sort
    int i, min, aux;
    for(i=0; i<tam; i++)
    {
        //Acha posicao do menor elemento a partir de i:
        min = indiceMenorElemento(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
} //complexidade O(n^2) - melhor caso, pior caso e caso médio

// Recebe vetor v[p..r] com p <= r. Rearranja
// os elementos do vetor e devolve j em p..r
// tal que v[p..j-1] <= v[j] < v[j+1..r].
int separa(int v[], int indiceInicial, int indiceFinal)
{
    int pivo = v[indiceFinal];      // último elemento é o pivô
    int indiceMenores = indiceInicial;

    for (int i = indiceInicial; i < indiceFinal; i++)
    {
        if (v[i] <= pivo)
        {
            // troca v[i] com v[indiceMenores]
            int temp = v[indiceMenores];
            v[indiceMenores] = v[i];
            v[i] = temp;

            indiceMenores++;
        }
    }

    // coloca o pivô na posição correta
    int temp = v[indiceMenores];
    v[indiceMenores] = v[indiceFinal];
    v[indiceFinal] = temp;

    return indiceMenores;
    //muito eficiente para ordenar um vetor.
} //complexidade O(n) - pior caso

void quickSort(int v[], int indiceInicial, int indiceFinal)
{
    if (indiceInicial < indiceFinal)
    {
        int j = separa(v, indiceInicial, indiceFinal);
        quickSort(v, indiceInicial, j - 1);
        quickSort(v, j + 1, indiceFinal);
    }
} //complexidade O(n log n) - melhor caso e caso médio, O(n^2) - pior caso Quando vetor já estiver ordenado ou quase ordenado

void insertionSort(int list[], int n)
{
    int j;
    int next;

    for (int i = 1; i < n; i++)
    {
        next = list[i];

        for (j = i - 1; j >= 0 && next < list[j]; j--)
        {
            list[j + 1] = list[j];
        }

        list[j + 1] = next;
    }
} //complexidade O(n^2) - pior caso, O(n) - melhor caso quando vetor já estiver ordenado ou quase ordenado

void bubbleSort(int vet[], int tam)
{
    int i, j, temp;

    for (i = tam - 1; i > 0; i--)
    {
        // Faz uma passada até a posição i
        for (j = 0; j < i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}// complexidade O(n^2) - melhor caso, pior caso e caso médio, basicamente inutil para aplicações reais, bom pra aprender apenas

void intercala(int inicio, int meio, int fim, int vetor[])
{
    // Vetor auxiliar que armazenará o resultado da intercalação
    int *auxiliar = malloc((fim - inicio) * sizeof(int));

    // Índice da primeira metade
    int indiceEsquerda = inicio;

    // Índice da segunda metade
    int indiceDireita = meio;

    // Índice do vetor auxiliar
    int indiceAuxiliar = 0;

    // Enquanto houver elementos nas duas metades
    while (indiceEsquerda < meio && indiceDireita < fim)
    {
        if (vetor[indiceEsquerda] <= vetor[indiceDireita])
        {
            auxiliar[indiceAuxiliar++] = vetor[indiceEsquerda++];
        }
        else
        {
            auxiliar[indiceAuxiliar++] = vetor[indiceDireita++];
        }
    }

    // Copia os elementos restantes da metade esquerda
    while (indiceEsquerda < meio)
    {
        auxiliar[indiceAuxiliar++] = vetor[indiceEsquerda++];
    }

    // Copia os elementos restantes da metade direita
    while (indiceDireita < fim)
    {
        auxiliar[indiceAuxiliar++] = vetor[indiceDireita++];
    }

    // Copia o conteúdo do vetor auxiliar para o vetor original
    for (int i = inicio; i < fim; i++)
    {
        vetor[i] = auxiliar[i - inicio];
    }

    free(auxiliar);
    //não ordena um vetor com metades desordenadas, por presumir que elas estejam ordenadas.
    //quem garante o ordenamento é o mergeSort.
}
void mergeSort(int inicio, int fim, int vetor[])
{
    if (inicio < fim - 1)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(inicio, meio, vetor);
        mergeSort(meio, fim, vetor);

        intercala(inicio, meio, fim, vetor);
    }
} //complexidade O(n log n) - melhor caso, pior caso e caso médio, muito eficiente para ordenar um vetor, especialmente para grandes vetores

int main()
{
    /*COMPARAÇÃO DE ALGORITMOS DE ORDENAÇÃO:
    Algoritmo	        Melhor Caso	    Caso Médio	    Pior Caso	    Memória Extra
    Bubble Sort       O(n²)           O(n²)           O(n²)               O(1)
    Insertion Sort    O(n)            O(n²)           O(n²)               O(1)
    Quick Sort        O(n log n)      O(n log n)      O(n²)               O(log n)
    Merge Sort        O(n log n)      O(n log n)      O(n log n)          O(n)

    Algoritmo        Vantagens                                  Desvantagens                        Quando usar?
    Bubble Sort      Simples de implementar                     Ineficiente para grandes vetores    Útil para ensinar conceitos básicos de ordenação
    Insertion Sort   Eficiente para vetores pequenos            Ineficiente para grandes vetores    Vetores pequenos ou já quase ordenados
                     ou já quase ordenados    
    Quick Sort       Muito eficiente na prática, pouca memoria  Pode cair no pior caso
    Merge Sort       Previsivel, excelente para grandes vetores Requer espaço extra
    
    tabela do GPT
| Algoritmo          | Vantagens                                                                           | Desvantagens                                                         | Quando usar?                                           |
| ------------------ | ----------------------------------------------------------------------------------- | -------------------------------------------------------------------- | ------------------------------------------------------ |
| **Bubble Sort**    | Simples de entender e implementar                                                   | Muito ineficiente (`O(n²)` em todos os casos)                        | Ensino de conceitos básicos de ordenação               |
| **Insertion Sort** | Simples, eficiente para vetores pequenos ou quase ordenados, usa pouca memória      | Ineficiente para vetores grandes (`O(n²)` no caso médio e pior caso) | Vetores pequenos ou já quase ordenados                 |
| **Quick Sort**     | Muito rápido na prática, geralmente o mais usado, pouca memória extra               | Pode degradar para `O(n²)` se o pivô for mal escolhido               | Ordenação geral em memória principal                   |
| **Merge Sort**     | Desempenho garantido `O(n log n)`, estável, excelente para grandes volumes de dados | Requer memória auxiliar `O(n)`                                       | Quando é importante garantir desempenho e estabilidade |

*/
    return 0;
}
