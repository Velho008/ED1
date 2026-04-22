#include<stdio.h>
#include<string.h>

/*
Usando Struct sem Funções
Objetivo:Passar uma struct como parâmetro para uma função.
Descrição:
Crie uma struct chamada Carro com os campos:
    Modelo: String de 50 caracteres
    Ano de fabricação: Inteiro
    Cor: String de 30 caracteres
Tarefa:Escreva uma função ImprimirCarroque recebe uma variável do tipo Carro como parâmetro e imprime as informações do carro na tela.
Em seguida, declare uma variável Carro e chame essa função para imprimir os dados.
*/
typedef struct 
{
    char modelo[50];
    int anoFabricacao;
    char cor[30];
}Carro;

/*Carro setCarro(char modelo[50], int anoFabricacao, char cor[30])
{
    Carro c;
    strcpy(c.modelo, modelo);
    c.anoFabricacao = anoFabricacao;
    strcpy(c.cor, cor);
    return c;
}
    tirei pq é struct sem funções*/

void ImprimirCarro(Carro c)
{
    printf("MODELO: %s\nANO DE FABRICACAO: %d\nCOR: %s\n", c.modelo, c.anoFabricacao, c.cor);
}

int main()
{
    Carro carrinho;
    strcpy(carrinho.modelo, "BMW legal");
    carrinho.anoFabricacao = 2008;
    strcpy(carrinho.cor, "branco");
    ImprimirCarro(carrinho);

    return 0;
}