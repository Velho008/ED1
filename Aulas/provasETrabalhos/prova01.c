#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NOME: GABRIEL VELHO DE SOUZA
//TURMA: 04
//MATRICULA: 242015218
int main()
{
    //questão 1:
    //a:
    printf("questao 1a:\n");
    int vetor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    //b:
    printf("questao 1b:\n");
    int matriz[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    printf("\n");

    //questão 2:
    //a:
    printf("questao 2a:\n");
    typedef struct 
    {
        char nome[50];
        int quantidade;
        float preco;
    }Produto;

    Produto p1;
    strcpy(p1.nome, "arroz");
    p1.quantidade = 10;
    p1.preco = 2.99;
    printf("\n");
    //b:
    printf("questao 2b:\n");
    printf("nome: %s\nquantidade: %d\npreco: %.2f\n", p1.nome, p1.quantidade, p1.preco);
    printf("\n");

    //questão 3:
    //a:
    printf("questao 3a:\n");
    Produto *ptr = &p1;
    printf("\n");

    //b:
    printf("questao 3b:\n");
    printf("nome: %s\npreco: %.2f\n", ptr->nome, ptr->preco);
    printf("\n");

    //c:
    printf("questao 3c:\n");
    // ptr -> var acessa a struct por meio do ponteiro
    // (*ptr).var primeiro pega o valor armazenado no local apontado pelo ponteiro (struct) para depois acessar a var disso
    printf("\n");

    //questão 4:
    printf("questao 4:\n");
    int n, i;
    printf("Quantos produtos deseja cadastrar?");
    scanf("%d", &n);
    Produto *produtos = (Produto*) malloc(sizeof(Produto) * n);
    for (i = 0; i < n; i++)
    {
        printf("\nPreencha os dados do produto %d\n", i + 1);
        printf("\nNome: ");
        scanf("%s", produtos[i].nome);
        printf("\nQuantidade: ");
        scanf("%d", &produtos[i].quantidade);
        printf("\nPreco: ");
        scanf("%f", &produtos[i].preco);
    }
    free(produtos); //importante para evitar memory leak
    produtos = NULL; //Boa prática para evitar ponteiros pendurados
    printf("\n");

    //questão 5:
    //a:
    printf("questao 5a:\n");
    int fatorial(int n) //o certo é colocar função fora da main, mas coloquei aqui pra manter a estrutura da prova
    {
        if (n==0) return 1; //caso base
        return n*fatorial(n-1); //caso recursivo
    }
    printf("\n");

    //b:
    printf("questao 5b:\n");
    int soma_vetor(int v[], int tam) //o certo é colocar função fora da main, mas coloquei aqui pra manter a estrutura da prova
    {
        if (tam==0) return 0;
        return v[tam-1] + soma_vetor(v, tam-1);
    }
    printf("\n");

    //c:
    printf("questao 5c:\n");
    //o item b tem complexidade O(n), por ser linear, quando n cresce uma vez, o algoritmo cresce linearmente
    printf("\n");

    //questão 6:
    //a:
    printf("questao 6:\n");
    FILE *arquivo;
    arquivo = fopen("produtos.txt", "w");
    fprintf(arquivo, "%s %d %.2f\n", p1.nome, p1.quantidade, p1.preco);
    fprintf(arquivo, "feijao 5 2.99\n");
    fclose(arquivo);
    arquivo = fopen("produtos.txt", "r");
    int ch;
    while((ch = fgetc(arquivo)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(arquivo);
    arquivo = NULL;
    printf("\n");

    //questão 7:
    //a:
    printf("questao 7a:\n");
    // O(1), O(log(n)), O(n), O(nlog(n)), O(n^2)
    printf("\n");

    //b:
    printf("questao 7b:\n");
    // o melhor caso é O(1), ocorre quando o alvo é o vet[0]
    // o pior caso é quando o alvo é o vet[n-1], ou não existe no vetor, complexidade O(n)
    printf("\n");
    
    return 0;
}