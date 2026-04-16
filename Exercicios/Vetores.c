#include <stdio.h>

void lerEImprimir(void)
{
    int tamanho = 5;
    int vetor[tamanho];
    printf("digite 5 numeros pra colocar em um vetor \n");
    for(int i = 0; i<tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i<(sizeof(vetor) / sizeof(vetor[0])); i++)
    {
        printf("posicao %d: numero %d",i+1 ,vetor[1]);
    }
}

int main()
{
    lerEImprimir();

    return 0;
}