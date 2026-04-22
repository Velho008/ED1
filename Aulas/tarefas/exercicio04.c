#include<stdio.h>
#include<string.h>
/*
Definindo uma Struct

Objetivo:Definir uma struct para armazenar as informações de um livro.
Descrição:
A struct deverá conter os seguintes campos:
    1.Título:String de 100 caracteres
    2.Autor:String de 50 caracteres
    3.Ano de publicação:Inteiro
    4.Número de páginas:Inteiro

Tarefa:Escreva o código para a definição da struct e crie duas variáveis dessa struct para armazenar informações de dois livros diferentes.
Mostre como você inicializaria os dados para essas duas variáveis.
*/

typedef struct 
{
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int numPaginas;
}Livro;

Livro setLivro(char titulo[100], char autor[50], int anoPublicacao, int numPaginas)
{
    Livro l;
    strcpy(l.titulo, titulo);
    strcpy(l.autor, autor);
    l.anoPublicacao = anoPublicacao;
    l.numPaginas = numPaginas;
    return l;
}

int main()
{
    Livro livro1 = setLivro("um livro ai", "eu mesmo", 1892, 67);
    Livro livro2 = setLivro("um autor legal :)", "aqui um autor", 1666, 677);

    return 0;
}