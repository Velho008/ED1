#include<stdio.h>
#include <string.h>

//vetores e matrizes são compostos homogenios, tem varias coisas e sempre do mesmo tipo
// Função para buscar um caractere no vetor


typedef struct
{
    int idade;
    char nome[100];
}pessoa;

void PrintaPessoa(pessoa p)
{
    printf("idade: %d\nnome: %s", p.idade, p.nome);
}

pessoa SetPessoa(int idade, char nome[100]) //facilita a vida pra criar uma struct pessoa
{
    pessoa p;
    p.idade = idade;
    strcpy(p.nome, nome);
    return p;
}
int Busca(char vet[ ] , int tam, char target) 
{
    for (int i = 0; i < tam; i++) 
    {
        if ( vet[i] == target) return i;
    }
    return -1; // Retorna -1 se o caractere não for encontrado
}
int main()
{
    int vetor[10] = {0}; //iniciou um vetor com 10 elementos todos = 0 inicializados
    for(int i = 0; i<10; i++)
    {
        printf("%d", vetor[i]); //printando o vetor
    }

    float Notas[80][3], soma; //cada aluno tem 3 notas, tem 80 alunos (matriz 80x3, duas dimensoes)
    //adicionando mais uma dimensão, posso fazer pra 5 turmas de 80 alunos cada um com 3 notas por exemplo
    printf("Digite as 3 notas dos 80 alunos:\n");
    for (int i = 0; i < 80; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //scanf("%f", &Notas[i][j]);
        }
    }

    for (int i = 0; i < 80; i++)
    {
        soma = 0.0;
        for (int j = 0; j < 3; j++)
        {
            soma +=Notas[i][j];
        }
        printf("Media %d: %.2f\n",i+1, soma/3.0);
    }

    /*estruturas são assim:
    struct [tag da estrutura] 
    {
        tipo_da_variavel nome_da_variavel;
        tipo_da_variavel nome_da_variavel;
        ...
        tipo_da_variavel nome_da_variavel;
    }[uma ou mais variáveis da estrutura]; 
    */

    struct Livros 
    {
        char titulo[50];
        char autor[50];
        char assunto[100];

        int id_livro;
    }livro1; //não recomendavel declarar direto na estrutura

    struct Livros livro2; //declarei o livro

    strcpy(livro1.assunto, "Um livro bem genérico"); //assim pra colocar as strings
    livro1.id_livro = 567; //ai vai fazendo assim pra cada um

    //inicializando
    struct Livros livro3 = {"Titulo qualquer", "nickolilson", "um livro bem generico", 67420}; //aqui declarou e inicializou

    printf("%d\n", livro1.id_livro); // possivel mostrar só uma variavel da estrutura
    // diferença objeto/classe e estrutura
    //classes e objetos tem/podem ter metodos, "comportamento"

    //typedef é usado pra renomear um tipo de dado

    typedef struct {int x; int y;} ponto;
    //daqui pra baixo posso fazer isso 
    ponto a; //typedef funciona mto bem com struct
    a.x = 1;
    a.y = 3;


    pessoa povo[10]; //aqui fiz um vetor com 10 pessoas

    povo[3].idade = 20; //agora a pessoa 4 (indice 3) tem 20 anos

    //com o poder de set pessoa da pra fazer isso agr

    pessoa joao = SetPessoa(15, "joao");
    PrintaPessoa(joao);

    return 0;
}
//esse é bem interessante e completo, pra fazer uma pessoa (joguei la pra cima pro arquivo compilar)