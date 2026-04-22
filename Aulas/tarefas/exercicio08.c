#include <stdio.h>
#include <string.h>
/*
Matrizes de Structs
Objetivo:Trabalhar com arrays de structs.
Descrição:
Crie uma struct Aluno com os campos:
    Nome:String de 50 caracteres
    Nota1:Float
    Nota2:Float
    Nota3:Float
Tarefa:Declare um array de 3 alunos e inicialize os dados de cada aluno manualmente. 
Em seguida, escreva um código que calcule a média das notas de cada aluno e imprima os nomes dos alunos com suas respectivas médias.
*/

typedef struct 
{
    char nome[50];
    float Nota1;
    float Nota2;
    float Nota3;
}Aluno;

float calcularMedia(Aluno a)
{
    return (a.Nota1 + a.Nota2 + a.Nota3)/3;
}

int main()
{
    Aluno turma[3];
    strcpy(turma[0].nome, "jose");
    strcpy(turma[1].nome, "joao");
    strcpy(turma[2].nome, "maria");
    turma[0].Nota1 = 4.1;
    turma[1].Nota1 = 2.2;
    turma[2].Nota1 = 5.2;
    turma[0].Nota2 = 4.5;
    turma[1].Nota2 = 7.5;
    turma[2].Nota2 = 8.5;
    turma[0].Nota3 = 4.5;
    turma[1].Nota3 = 4.5;
    turma[2].Nota3 = 4.5;

    for (int i = 0; i < 3; i++)
    {
        printf("ALUNO: %s MEDIA: %.2f\n", turma[i].nome, calcularMedia(turma[i]));
    }
}

