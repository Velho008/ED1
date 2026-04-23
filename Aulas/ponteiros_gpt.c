#include <stdio.h>
/*
PONTEIROS E MEMÓRIA (COMPLEMENTO)

MEMÓRIA (visão simplificada):
- Stack (pilha): variáveis locais, chamadas de função (automático)
- Heap: memória alocada dinamicamente (malloc, calloc, free)
- Data/Texto: variáveis globais e código do programa

----------------------------------------
PONTEIRO NULL
- Ponteiro que não aponta pra lugar nenhum válido
- Boa prática inicializar com NULL

int *p = NULL;

----------------------------------------
FUNÇÕES COM PONTEIRO (PASSAGEM POR REFERÊNCIA)

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// sem ponteiro (não funciona como esperado)
void troca_errado(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

----------------------------------------
ARITMÉTICA DE PONTEIROS

int v[] = {10, 20, 30, 40};

int *p = v;

p++; // avança para o próximo elemento (não soma 1 byte, soma sizeof(tipo))

----------------------------------------
PONTEIROS E VETORES

- Nome do vetor já é um ponteiro pro primeiro elemento

int v[] = {1, 2, 3};

v == &v[0]

----------------------------------------
ALOCAÇÃO DINÂMICA (HEAP)

#include <stdlib.h>

malloc: aloca memória (lixo dentro)
calloc: aloca e zera memória
free: libera memória

int *p;
p = (int*) malloc(sizeof(int)); // aloca 1 inteiro

if (p == NULL) {
    printf("Erro de alocacao\n");
}

*p = 10;

free(p); // libera memória

----------------------------------------
ALOCAÇÃO DE VETORES

int *v;
int n = 5;

v = (int*) malloc(n * sizeof(int));

for (int i = 0; i < n; i++) {
    v[i] = i * 10;
}

free(v);

----------------------------------------
CUIDADOS IMPORTANTES

- Nunca usar ponteiro não inicializado
- Nunca acessar memória depois de dar free (dangling pointer)
- Sempre dar free no que foi malloc
- Evitar memory leak (esquecer de liberar memória)
- Não acessar posições fora do vetor

----------------------------------------
DANGLING POINTER

int *p = malloc(sizeof(int));
free(p);
*p = 10; // ERRO! memória já liberada

----------------------------------------
EXEMPLO COMPLETO NO MAIN
*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int numero = 12983;
    printf("%d\n", numero);
    printf("%p\n", &numero);

    int *ponteiro = &numero;

    *ponteiro = 333;
    printf("%d\n", *ponteiro);

    // TROCA COM PONTEIRO
    int x = 10, y = 20;
    troca(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    // VETORES
    int v[] = {10, 20, 30};
    int *p = v;

    printf("%d\n", *p);      // 10
    printf("%d\n", *(p+1));  // 20
    printf("%d\n", p[2]);    // 30

    // ALOCAÇÃO DINÂMICA
    int *vetor;
    int n = 3;

    vetor = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        vetor[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}