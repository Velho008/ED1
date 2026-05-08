/*  Write a program to display the content of file that have been created in the previous example program
    –Name
    –Age
    –Basic salary   */
#include <stdio.h>

int main()
{
    char name[50];
    int age;
    float basicSalary;
    FILE *arquivo;

    arquivo = fopen("bin/employee.dat", "r");
    if (arquivo == NULL)
    {
        printf("ERRO: arquivo nao foi aberto corretamente");
        return 1;
    }
    
    // espaço antes de %49[^;] faz o fscanf ignorar quebras de linha e outros espaços em branco pendentes do registro anterior
    while (fscanf(arquivo, " %49[^;];%d;%f", //%49[^;] já foi explicado em arquivos.c
                  name, &age, &basicSalary) == 3) //basicamente vai rodar enquanto existirem grupos de 3
    {
        printf("nome: %s\nidade: %d\nsalario: %.2f\n\n", name, age, basicSalary);
    }

    fclose(arquivo);
    arquivo = NULL;
    return 0;
}