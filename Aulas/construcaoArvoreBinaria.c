#include <stdio.h>
#include <stdlib.h>

/*
em uma arvore binarias, para criar um subnó, se ele for menor deve ficar a esquerda, se for maior, a direita
essa regra deve percorrer a arvore inteira
*/

typedef struct NoBin
{
    int info;
    struct NoBin *esq; // ponteiro para filho esquerdo
    struct NoBin *dir; // ponteiro para filho direito
} NoBin;

char LerProximo()
{
    char c;
    scanf(" %c", &c); // lê um caractere ignorando espaços
    return c;
}

NoBin *AloqueNo()
{
    NoBin *novo = (NoBin *)malloc(sizeof(NoBin));

    if (novo == NULL)
    {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void Constroi(NoBin **raiz)
{
    char Dado = LerProximo();
    if (Dado == ".")
    {
        *raiz = NULL;
        return;
    }

    *raiz = AloqueNo();
    (*raiz)->info = Dado;
    Constroi(&((*raiz)->esq));
    Constroi(&((*raiz)->dir));
}
/*
imagine um input ABG..C.DE.F
sua arvore seria:
                A
               /
              B
             / \
            G   C
                 \
                  D
                 /
                E
                 \
                  F
*/

/*
EXERCICIO DO SLIDE:
                 15
                /   \
               8     22
               / \   / \
              4   11 18 27
             / \  / \
            2   6 10 13
1. Escreva a expressão linear dessa árvore.
2.Identifiquem:
    1.raiz
    2.filhos à esquerda e à direita
    3.folhas
    4.nós internos
3.Percorram a árvore em:
    1.pré-ordem
    2.em-ordem
    3.pós-ordem
4.Escrevam o código em C para criar os nós manualmente.
5.Analisem como a estrutura muda se a inserção for feita em outra ordem.
6.Responda as questões abaixo:
    •Qual é a raiz?
    •Quais são as folhas?
    •Qual é o filho esquerdo de 8?
    •Qual é o filho direito de 11?
    •Qual é a subárvore enraizada em 8?
    •Qual é o percurso em ordem?

RESPOSTAS:
1:  15(8(4(2,6),11(10,13))),(22(18,27)) -> raiz(esquerda,direita)

2:
    1: 15
    2: 8, 4, 2 
    3: 2, 6, 10, 13, 18, 27
    4: 8, 22, 4, 11

3: 
    1: 15, 8, 4, 2, 6, 11, 10, 13, 22, 18, 27 (raiz -> esquerda -> direita)
    2: 2, 4, 6, 8, 10, 11, 13, 15, 18, 22, 27 (esquerda -> raiz -> direita)
    3: 2, 6, 4, 10, 13, 11, 8, 18, 27, 22, 15 (esquerda -> direita -> raiz)

4:  respondido abaixo

5:  ao inserir os numeros em ordem diferente, podemos gerar outras arvores perfeitamente validas
    isso pode gerar arvores com diferentes eficiencias de busca.

6:  
    raiz: 15
    folhas: 2, 6, 10, 13, 18, 27
    filho esquerdo de 8: 4
    filho direito de 11: 13
    subarvore enraizada em 8: 4   11
                             / \  / \
                            2   6 10 13
    percurso em ordem: já respondido anteriormente
*/

int main()
{

    return 0;
}