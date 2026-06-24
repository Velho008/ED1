#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
O arquivo de dados do censo 2010 do IBGE está ordenado pelo código de município (campo IBGE). Faça um programa com as seguintes opções:

1. Faça a carga de um vetor contendo IBGE e Linha. onde Linha refere-se ao número da linha do arquivo.

2. Leia um código de município e mostre na tela as seguintes informações deste município: 
Município, UF. Região, População em 2010 e Porte. Mostre ainda o tempo de execução desta busca com Busca Binária e Busca Sequencial.


3. Sair. Não deixe lixo na memória.
*/
#define MAX_MUNICIPIOS 6000

int validateFile(char* fileName)
{
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL)
    {
        return 0;
    }

    fclose(file);
    return 1;
}

typedef struct
{
    char concatUFMun[100];
    int ibge;
    int ibge7;
    char uf[3];
    char municipio[100];
    char regiao[50];
    int populacao;
    char porte[50];
    int linha;

} Municipio;

void printMunicipio(Municipio municipios[], int indice)
{
    printf
    (
        "Linha: %d\n"
        "ConcatUF+Mun: %s\n"
        "IBGE: %d\n"
        "IBGE7: %d\n"
        "UF: %s\n"
        "Municipio: %s\n"
        "Regiao: %s\n"
        "Populacao: %d\n"
        "Porte: %s\n",
        municipios[indice].linha,
        municipios[indice].concatUFMun,
        municipios[indice].ibge,
        municipios[indice].ibge7,
        municipios[indice].uf,
        municipios[indice].municipio,
        municipios[indice].regiao,
        municipios[indice].populacao,
        municipios[indice].porte
    );
}

void loadVector(Municipio municipios[], int *qtd)
{
    *qtd = 0;

    FILE *file;
    char caminho[] = "Lista_Municipios_com_IBGE_Brasil_Versao_CSV.csv";

    if (!validateFile(caminho))
    {
        return;
    }

    file = fopen(caminho, "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linhaCSV[1024];

    // Ignora o cabeçalho
    fgets(linhaCSV, sizeof(linhaCSV), file);

    while (fgets(linhaCSV, sizeof(linhaCSV), file) != NULL &&
           *qtd < MAX_MUNICIPIOS)
    {
        linhaCSV[strcspn(linhaCSV, "\r\n")] = '\0';

        municipios[*qtd].linha = *qtd + 2;

        char *token = strtok(linhaCSV, ";");

        if (token != NULL)
            strcpy(municipios[*qtd].concatUFMun, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            municipios[*qtd].ibge = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL)
            municipios[*qtd].ibge7 = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(municipios[*qtd].uf, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(municipios[*qtd].municipio, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(municipios[*qtd].regiao, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            municipios[*qtd].populacao = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(municipios[*qtd].porte, token);

        (*qtd)++;
    }

    fclose(file);

    printf("%d municipios carregados.\n", *qtd);
}

int main()
{
    Municipio municipios[MAX_MUNICIPIOS];
    int qtdMunicipios;
    int escolha;

    do 
    {
        printf
        (
            "\nbem vindo ao sistema do IGBE"
            "\ndigite 1 para inicializar o vetor."
            "\ndigite 2 para ler o codigo de um municipio e ver informações sobre ele e comparar o tempo de busca com busca binaria e busca sequencial"
            "\ndigite 3 para sair sem deixar lixo na memoria\n"
        );
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                loadVector(municipios, &qtdMunicipios);
                break;
            
            case 2:
                //falta aqui
                break;

            case 3:
                //falta aqui
                break;

            default:
                printf("ERRO: digite um numero valido");
                break;
        }
    }while(escolha !=3);


    return 0;
}