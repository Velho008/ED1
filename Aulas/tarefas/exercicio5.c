#include<stdio.h>
#include<string.h>
/*
Acessando os Campos de uma Struct
Objetivo:Acessar os campos de uma struct e modificar seus valores.

Descrição:
Suponha que você tenha uma struct chamada Pessoa, com os campos:
    Nome:String de 50 caracteres
    Idade:Inteiro
    Altura:Float
Tarefa:Escreva o código que inicializa uma variável do tipo Pessoa com os seguintes dados:
Nome: "João"
Idade: 25
Altura: 1.80
Depois, modifique a idade para 26 e a altura para 1.81 e escreva o código para imprimir as novas informações.
*/
typedef struct 
{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

Pessoa setPessoa(char nome[50], int idade, float altura)
{
    Pessoa p;
    strcpy(p.nome, nome);
    p.idade = idade;
    p.altura = altura;
    return p;
}

void printPessoa(Pessoa p)
{
    printf("NOME: %s\nIDADE: %d\nALTURA: %.2f\n", p.nome, p.idade, p.altura);
}

int main()
{
    Pessoa joao = setPessoa("Joao", 25, 1.80);
    joao.idade = 26;
    joao.altura = 1.81;
    printPessoa(joao);

    return 0;
}