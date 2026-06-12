#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h" //arquivo ligado a esse trabalho, com as structs
/*  enunciado do trabalho pode ser encontrado em trabalho02Enunciado.pdf    */

//NOME: GABRIEL VELHO DE SOUZA
//MATRICULA: 242015218

void reset(TTemperaturas *temp)
{
    if (temp->medidas != NULL)
    {
        for (int i = 0; i < temp->qtde_medidas; i++)
        {
            free(temp->medidas[i].temperatura);
        }

        free(temp->medidas);
    }

    printf("Digite a quantidade de dias: ");
    scanf("%d", &temp->qtde_dias);

    temp->medidas = (TMedidas *)malloc(
        temp->qtde_dias * sizeof(TMedidas)
    );

    temp->qtde_medidas = 0;

    printf("Estrutura reinicializada com sucesso.\n");
}

void inserirMedida(TTemperaturas *temp)
{
    if (temp->medidas == NULL)
    {
        printf("Execute o Reset primeiro.\n");
        return;
    }

    if (temp->qtde_medidas >= temp->qtde_dias)
    {
        printf("Limite de medidas atingido.\n");
        return;
    }

    int pos = temp->qtde_medidas;

    printf("Cidade: ");

    getchar(); //limpa o buffer

    fgets(
        temp->medidas[pos].cidade,
        sizeof(temp->medidas[pos].cidade),
        stdin
    );

    temp->medidas[pos].cidade[
        strcspn(temp->medidas[pos].cidade, "\n")
    ] = '\0';

    temp->medidas[pos].temperatura =
        (float *)malloc(sizeof(float));

    printf("Temperatura: ");
    if (scanf("%f", temp->medidas[pos].temperatura) != 1)
    {
        printf("Temperatura invalida.\n");

        free(temp->medidas[pos].temperatura);
        temp->medidas[pos].temperatura = NULL;

        return;
    }

    temp->qtde_medidas++;

    printf("Medida inserida com sucesso.\n");
}

void estatistica(TTemperaturas *temp)
{
    if (temp->qtde_medidas == 0)
    {
        printf("Nenhuma medida cadastrada.\n");
        return;
    }

    float soma = 0;

    int indiceMenor = 0;
    int indiceMaior = 0;

    for (int i = 0; i < temp->qtde_medidas; i++)
    {
        float temperatura = *(temp->medidas[i].temperatura);

        soma += temperatura;

        if (temperatura < *(temp->medidas[indiceMenor].temperatura))
        {
            indiceMenor = i;
        }

        if (temperatura > *(temp->medidas[indiceMaior].temperatura))
        {
            indiceMaior = i;
        }
    }

    float media = soma / temp->qtde_medidas;

    printf("\n===== ESTATISTICAS =====\n");

    printf("Temperatura media: %.2f\n", media);

    printf(
        "Menor temperatura: %s - %.2f\n",
        temp->medidas[indiceMenor].cidade,
        *(temp->medidas[indiceMenor].temperatura)
    );

    printf(
        "Maior temperatura: %s - %.2f\n",
        temp->medidas[indiceMaior].cidade,
        *(temp->medidas[indiceMaior].temperatura)
    );
}

void liberarMemoria(TTemperaturas *temp)
{
    if (temp->medidas != NULL)
    {
        for (int i = 0; i < temp->qtde_medidas; i++)
        {
            free(temp->medidas[i].temperatura);
        }

        free(temp->medidas);

        temp->medidas = NULL;
        temp->qtde_dias = 0;
        temp->qtde_medidas = 0;
    }
}

int main()
{
    int escolha;
    TTemperaturas temperaturas;

    temperaturas.qtde_dias = 0;
    temperaturas.qtde_medidas = 0;
    temperaturas.medidas = NULL;

    do 
    {
        printf("digite 1 para reset\ndigite 2 para inserir medida\ndigite 3 para estatisticas\ndigite 0 para sair\n: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            reset(&temperaturas);
            break;

        case 2:
            inserirMedida(&temperaturas);
            break;

        case 3:
            estatistica(&temperaturas);
            break;

        case 0:
            liberarMemoria(&temperaturas);
            printf("Encerrando programa...\n");
            break;

        default:
            printf("\nERRO: digite um numero valido\n\n");
            break;
        }
    }while(escolha != 0);

    return 0;
}