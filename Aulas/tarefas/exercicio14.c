#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    float preco;
} Produto;


int main() 
{
    Produto um;
    Produto *p;
    p = &um;

    /*
    poderia ser assim no lugar:
    Produto *p = malloc(sizeof(Produto));
    isso iria ser uma alocacao dinamica
    */

    strcpy(p->nome, "arroz");
    p->preco = 2.99;
    printf("Nome: %s\n", p->nome);
    printf("Preco: %.2f\n", p->preco);
    return 0;
}

/*
versao com malloc:
    Produto *p;

    // Aloca memória para um Produto
    p = malloc(sizeof(Produto));

    // Verifica se a alocação deu certo
    if (p == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Agora p aponta para memória válida
    strcpy(p->nome, "arroz");
    p->preco = 2.99;

    printf("Nome: %s\n", p->nome);
    printf("Preco: %.2f\n", p->preco);

    // Libera a memória
    free(p);

    return 0;
*/