#include <stdio.h>
/*
Passando uma Struct por Referência
Objetivo:Modificar os dados de uma struct dentro de uma função, utilizando passagem por referência.
Descrição:
Suponha que você tenha uma struct Produto com os seguintes campos:
    Nome:String de 50 caracteres
    Preço:Float
    Quantidade em estoque:Inteiro
Tarefa:Escreva uma função AtualizarProduto que recebe um ponteiro para uma structProduto e altera os dados do produto 
(por exemplo, aumenta o preço em 10% e diminui a quantidade em estoque em 1). Depois, declare uma variável Produto, 
chame a função para modificar os dados e mostre como ficaria o produto após a atualização.
*/

typedef struct 
{
    char nome [50];
    float preco;
    int quantidade;
}Produto;

void atualizarProduto(Produto *produto)
{
    if (produto -> quantidade <=0)
    {
        printf("NAO É POSSIVEL ATUALIZAR, ESTOQUE EM FALTA");
        return;
    }
    produto->preco += produto->preco/10.0;
    produto->quantidade--;
}

int main()
{
    Produto arroz = {"arroz", 15.43, 21};
    atualizarProduto(&arroz);
    printf("preco: %.2f, quantidade em estoque: %d", arroz.preco, arroz.quantidade);
    printf("\nMUDOU OS VALORES DO ORIGINAL POR MEIO DE UMA FUNCAO, DIRETO, SEM CRIAR OUTRA VARIAVEL");
}