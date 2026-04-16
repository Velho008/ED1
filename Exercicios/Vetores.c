#include <stdio.h>

void lerEImprimir(void)
{
    int tamanho = 5;
    int vetor[tamanho];
    printf("digite 5 numeros pra colocar em um vetor, um de cada vez \n");
    for(int i = 0; i<tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i<(sizeof(vetor) / sizeof(vetor[0])); i++)
    {
        printf("posicao %d: numero %d\n",i+1 ,vetor[i]);
    }
}

int somaVetor(int vetor[], int tamanho)
{
    int soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    return soma;
}

typedef struct
{
    int min;
    int max;
} Res;
Res maiorEMenor(int vetor[], int tamanho)
{
    int min = vetor[0];
    int max = vetor[0];

    for(int i = 1; i<tamanho; i++)
    {
        if(min > vetor[i]) min = vetor[i];
        if(max < vetor[i]) max = vetor[i];
    }
    Res r;
    r.min = min;
    r.max = max; 
    return r;
}

int pares(int vetor[], int tamanho)
{
    int soma = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(vetor[i]%2==0) soma++;
    }
    return soma;
}

void mostrarInverso(int vetor[], int tamanho)
{
    for(int i = tamanho-1; i >= 0; i--)
    {
        printf("%d ", vetor[i]);
    }
}

int encontrarX(int vetor[], int tamanho, int alvo)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(vetor[i] == alvo)
        {
            printf("alvo no indice %d\n", i);
            return 1;
        } 
    }
    printf("alvo não localizado");
    return 0;
}
int removedor(int vetor[], int tamanho, int alvo)
{
    //aqui ainda n sei fazer
}

int main()
{
    lerEImprimir();

    return 0;
}
/*


## 🔥 Desafio extra (um pouco mais difícil)

### **7. Remover elemento**

Leia um vetor de 10 posições e um número `x`.
Remova a **primeira ocorrência** de `x` deslocando os elementos.

Exemplo:

```
Vetor: 1 2 3 4 5  
Remover: 3  
Resultado: 1 2 4 5 _
```

👉 Aqui você pratica:

* deslocamento (`vetor[i] = vetor[i+1]`)

---

## 💡 Dica geral importante

Vetores em C:

* começam no índice `0`
* vão até `tamanho - 1`

---

Se quiser, você pode:

* mandar seu código que eu corrijo (igual antes)
* ou pedir os de **strings** depois (já envolve `char[]`, começa a ficar mais “C raiz” 😄)
*/