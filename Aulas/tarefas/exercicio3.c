#include <stdio.h> 
#include <stdlib.h>

void lerTemperaturas(float predio[5][10][24])
{
    int andar;
    int sala;
    printf("bem vindo ao sistema de medicao de temperatura do predio\nselecione um andar (0 a 4) para ver a temperatura: ");
    scanf("%d", &andar);
    if (andar > 4 || andar < 0)
    {
        printf("ERRO: andar selecionado nao existe");
        return;
    }

    printf("andar selecionado: %d\n", andar);

    printf("selecione uma sala (0 a 9): ");
    scanf("%d", &sala);
    if (sala > 9 || sala < 0)
    {
        printf("ERRO: sala selecionada nao existe");
        return;
    }

    printf("sala: %d do andar %d selecionada", sala, andar);

    printf("\nTEMPERATURAS AO LONGO DO DIA EM GRAUS CELSIUS\n");
    for(int i = 0; i < 24; i++)
    {
        if(i > 8)
        {
            printf("H%d:00 ",i+1);
        }
        else
        {
            printf("H%d:00  ",i+1);
        }
    }

    printf("\n");

    float soma = 0;
    for(int i = 0; i < 24; i++)
    {
        soma += predio[andar][sala][i];
        if (predio[andar][sala][i] > 9.0)
        {
            printf("%.2fC ", predio[andar][sala][i]);
        }
        else
        {
            printf("%.2fC  ", predio[andar][sala][i]);
        }
    }
    float media = soma/24.0;
    printf("\ntemperatura media da sala: %.2f", media);
}

void mediaAndares(float predio[5][10][24])
{
    printf("\nTEMPERATURA MEDIA DE CADA ANDAR EM GRAUS CELCIUS\n");
    for(int i = 0; i < 5; i++)
    {
        printf("A%d     ", i);
    }
    printf("\n");

    float somaTotal = 0;
    for(int i = 0;  i < 5; i++)
    {
        float somaAndar = 0;
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 24; k++)
            {
                somaTotal += predio[i][j][k];
                somaAndar += predio[i][j][k];
            }
        }
        printf("%.2fC ", somaAndar/240.0);
    }
    printf("\nMEDIA DO PREDIO TODO: %.2fC", somaTotal/(240.0*5.0));
}

/* ENUNCIADO
Descrição do Problema
Imagine um edifício com vários andares, onde cada andar
tem várias salas, e a temperatura de cada sala é
monitorada. As temperaturas de todas as salas são
armazenadas em uma matriz 3D, onde a primeira dimensão
representa o andar, a segunda a sala nesse andar, e a
terceira dimensão representa leituras de temperatura ao
longo do dia.

Objetivo
Escreva um programa que inicialize aleatoriamente as
temperaturas para um edifício de 5 andares, com 10 salas
por andar e 24 leituras de temperatura por dia (uma por
hora). O programa deve permitir ao usuário selecionar um
andar e uma sala e exibir as temperaturas dessa sala ao
longo do dia. Além disso, o programa deve calcular e
exibir a temperatura média de cada andar.
*/

int main()
{
    srand(42);
    float predio[5][10][24];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 24; k++)
            {
                predio[i][j][k] = (float)rand() / RAND_MAX * 40.0;
            }
        }
    }

    int escolha;
    do
    {
        printf("\nbem vindo ao menu de temperaturas do predio\nopcao 1: media dos andares e media geral\nopcao 2: temperaturas de uma sala ao longo do dia\nopcao 0: sair");
        printf("\ndigite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            mediaAndares(predio);
            break;

        case 2:
            lerTemperaturas(predio);
            break;

        case 0:
            break;

        default:
            printf("OPCAO INVALIDA");
            break;
        }

    }while(escolha !=0);

    return 0;
}