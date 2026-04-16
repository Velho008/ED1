#include<stdio.h>
//vetores e matrizes são compostos homogenios, tem varias coisas e sempre do mesmo tipo

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
            scanf("%f", &Notas[i][j]);
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
    }

    struct Livros 
    {
        char titulo[50];
        char autor[50];
        char assunto[100];

        int id_livro;
    };

    struct Livros livro1, livro2; //declarei os 2 livros

    //inicializando
    struct Livros livro3 = {"Titulo qualquer", "nickolilson", "um livro bem generico", 67420}; //aqui declarou e inicializou
    // é possivel inicializar cada valor separado, veja abaixo
    // possivel mostrar só uma variavel da estrutura
    // diferença objeto/classe e estrutura

    //mostrar typedef pra renomear um tipo de dado
    //exemplo para ponto {int x; int y} (ponto no cartesiano) 
    //typedef com struct, ver exemplo dos slides

    return 0;
}