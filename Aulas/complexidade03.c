#include <stdio.h>

int procurarIndice(int *vetor, int tamanho, int valor)
{
    int low = 0; //menor indice
    int mid;
    int high = tamanho - 1; //maior indice

    int numeroDeBuscas = 1; 

    while (low <= high)
    {
        printf("\nbusca atual: %d", numeroDeBuscas);
        mid = (low + high)/2; // encontra o meio do vetor ordenado
        printf("\nlow atual: %d\nmid atual: %d\nhigh atual: %d", low, mid, high);
        
        if (valor < vetor[mid]) //se o valor estiver na metade menor
        {
            printf("\nprocurando na metade menor\n");
            high = mid-1; //vai dividir pra ver a metade menor
        }
        else if (valor > vetor[mid]) //se estiver na metade maior
        {
            printf("\nprocurando na metade maior\n");
            low = mid+1; //vai dividir pra ver a metade maior
        }
        else
        {
            printf("\nencontrado\n");
            return mid; //caso seja o valor que quer achar, retorna o indice
        }

        numeroDeBuscas++;
/*      esse algoritmo, caso não encontre, roda M vezes, onde 2^M = n, portanto M = log2 n 
        complexidade O(n)-> O(log2 n)  EXTREMAMENTE EFICIENTE
        para n = 8, executa aprox. 3x
        para n = 1000, executa aprox. 10x
        para n = 1b, executa aprox. 30x */
    }

    return -1;
}
int main()
{

    int tamanhoVetor;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int vetor[tamanhoVetor];

    int numeroInicial;
    printf("\ndigite o primeiro numero do vetor: ");
    scanf("%d", &numeroInicial);

    for (int i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = numeroInicial;
        numeroInicial++;
    }

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\nindice %d: %d\n", i, vetor[i]);
    }

    printf("\ndigite o numero que deseja descobrir o indice: ");
    int procurado;
    scanf("%d", &procurado);

    int indiceProcurado = procurarIndice(vetor, tamanhoVetor, procurado);

    if (indiceProcurado == -1)
    {
        printf("\no valor não foi encontrado");
    }
    else
    {
        printf("indice do valor: %d", indiceProcurado);
    }


    return 0;
}