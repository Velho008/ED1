#include <stdio.h>
#include <stdlib.h>

/*
pode pensar em uma arvore como uma arvore de diretorios do pc

TERMOS IMPORTANTES:

- Nó raiz (root):
  Primeiro nó da árvore. É o nó que não possui pai e serve
  como ponto de partida para todos os outros nós.

- Nó pai:
  Nó que possui um ou mais nós filhos ligados a ele.

- Nó filho:
  Subnó de um nó pai. Todo nó filho possui exatamente um pai
  (exceto a raiz, que não possui pai).

- Nó irmão:
  Nós que possuem o mesmo nó pai.

- Nó folha ou nó terminal:
  Nó que não possui filhos. "fim da linha".
  Nó que tem grau 0.

- Subárvore:
  Parte da árvore formada por um nó e todos os seus descendentes.

- Floresta:
  Conjunto de arvores independentes.

- Grau:
  Número de filhos de um nó.
  Quantidade de subarvores que um nó possui.
  "Olha pra baixo"

- Nivel:
  Distância de um nó da raiz.
  "Olha pra cima"
  raiz = 0
  filhos da raiz = 1
  filhos dos filhos da raiz = 2

- Altura:
  Nível mais alto da arvore.
  Distancia da raiz até a folha mais distante.

exemplo:

            A
          /   \
         B     C
        / \     \
       D   E     F

A = nó raiz
B e C = filhos de A
D e E = filhos de B
B e C , D e E= irmãos
D, E e F = nós folha
*/

/*
Arvores Binarias:

- Cada nó deve ter grau menor ou igual a 2.
- Para o caso de arvores binarias, as subarvores são ou esquerda ou direita.
- Existe diferença entre subarvore esquerda e subarvore direita.
            A                               A
          /         diferente de             \
         B                                    B

- Em uma arvore binaria, cada nó contem a sua informação, um ponteiro para o filho esquerdo e um ponteiro para o filho direito. 
*/

typedef struct NoBin
{
    int info;
    struct NoBin *esq; // ponteiro para filho esquerdo
    struct NoBin *dir; // ponteiro para filho direito
} NoBin;

NoBin *criarNo(int valor)
{
    NoBin *novo = (NoBin *)malloc(sizeof(NoBin));
    if (novo == NULL)
    {
        printf("\nERRO: falha ao alocar memoria\n");
        return(NULL);
    }

    novo -> info = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;

    return novo;
}

void imprimirPreOrdem(NoBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    printf("\n%d\n", raiz->info);
    imprimirPreOrdem(raiz->esq); //imprime recursivamente no lado esquerdo
    imprimirPreOrdem(raiz->dir); //imprime recursivamente no lado direito
}

void imprimirArvore(NoBin *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }
    imprimirArvore(raiz->dir, nivel+1);
    for (int i = 0; i < nivel; i++)
    {
        printf("    ");
    }
    printf("%d\n", raiz->info);
    imprimirArvore(raiz->esq, nivel+1);
}

void destruirArvore(NoBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    destruirArvore(raiz->esq);
    destruirArvore(raiz->dir);

    printf("info %d liberada\n", raiz->info);
    free(raiz);

}


int main()
{
    NoBin *raiz = criarNo(10);
    raiz->esq = criarNo(5);
    raiz->dir = criarNo(20);

    raiz->esq->esq = criarNo(3);
    raiz->esq->dir = criarNo(7);

    printf("Estrutura da arvore:\n");
    imprimirArvore(raiz, 0);

    printf("\nPre-ordem");
    imprimirPreOrdem(raiz);
    printf("\n");

    destruirArvore(raiz);
    raiz = NULL;
    printf("arvore liberada da memoria");

    /*
    arvore criada:
        10
       /  \
      5    20
     / \
    3   7

    */
    return 0;
}