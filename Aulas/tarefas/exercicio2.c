#include <stdio.h> 
#include <stdlib.h>

int reservaLivre(int reserva)
{
    if(reserva)
    {
        printf("R");
        return 0;
    }
    printf("L");
    return 1;
}

void Mostrar(int fileiras, int assentos, int reservas[][20])
{
    printf("assim estao as atuais reservas\n");

    printf("            ");
    for (int i = 1; i <= assentos; i++)
    {
        printf("A%d  ", i);
    }

    for (int i = 1; i <= fileiras; i++)
    {
        if (i>=10)
        {
            printf("\nfileira %d: ", i);
        }
        else
        {
            printf("\nfileira %d:  ", i);
        }
        
        for (int j = 1; j <= 20; j++)
        {
            reservaLivre(reservas[i-1][j-1]);
            printf("   ");
            if (j >= 10)
            {
                printf(" ");
            }
        }
        
    }
    printf("\nL = livre\nR = reservado");
}

void reservar(int fileiras, int assentos, int reservas[][20])
{
    int fileiraReserva;
    int assentoReserva;
    printf("bem vindo ao sistema de reservas\n");
    Mostrar(fileiras, assentos, reservas);

    printf("\ndigite a fileira da reserva: ");
    scanf("%d", &fileiraReserva);
    if (fileiraReserva > 15 || fileiraReserva < 1)
    {
        printf("ERRO: fileira não existe");
        return;
    }

    printf("            ");
    for (int i = 1; i <= assentos; i++)
    {
        printf("A%d  ", i);
    }

    if (fileiraReserva>=10)
    {
        printf("\nfileira %d: ", fileiraReserva);
    }
    else
    {
        printf("\nfileira %d:  ", fileiraReserva);
    }

    for (int j = 1; j <= assentos; j++)
    {
        reservaLivre(reservas[fileiraReserva-1][j-1]);
        printf("   ");
        if (j >= 10)
        {
            printf(" ");
        }
    }

    printf("\ndigite o numero do assento para reservar: ");
    scanf("%d", &assentoReserva);

    if (assentoReserva > 20 || assentoReserva < 1)
    {
        printf("\nERRO: assento não existe");
        return;
    }
    if (reservas[fileiraReserva-1][assentoReserva-1])
    {
        printf("\nERRO: assento ja reservado");
        return;
    }
    
    printf("assento livre, reservado com sucesso");
    reservas[fileiraReserva-1][assentoReserva-1] = 1;
    printf("novas reservas:");
    Mostrar(fileiras, assentos, reservas);
}



/* ENUNCIADO
Descrição do Problema
Um teatro quer implementar um sistema de reservas online
onde os assentos podem ser visualizados e selecionados
através de uma matriz 2D. Cada linha representa uma
fileira e cada coluna um assento naquela fileira, onde 0
representa um assento disponível e 1 um assento ocupado.

Objetivo
Desenvolva um programa que inicialize uma matriz para um
teatro com 15 fileiras e 20 assentos por fileira, permita
ao usuário escolher um assento, verifique a
disponibilidade e atualize o status do assento de
disponível para ocupado após a reserva. O programa deve
ser capaz de mostrar a matriz de assentos atualizada após
cada reserva.
*/

int main()
{
    srand(42); //seed pra manter consistencia
    int reservas[15][20];
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            reservas[i][j] = rand() % 2; // 0 ou 1
        }
    } //deve ter apenas 0(livre) e 1(reservado)

    int escolha;

    do
    {

        printf("\nescolha o que fazer:\n1: reservar\n2: verificar reservas\n0: sair\ndigite a escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            reservar(15, 20, reservas);
            break;
        case 2:
            Mostrar(15, 20, reservas);
            break;
        case 0:
            break;
        default:
            printf("opção invalida");
            break;
        }
    } while(escolha !=0);

    return 0;
}
//daria pra separar a funcao que verifica reserva em 2 pra separar o print e tratar melhor entrada de strings