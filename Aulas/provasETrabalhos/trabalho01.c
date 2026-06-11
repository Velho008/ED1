/*  enunciado do trabalho pode ser encontrado em trabalho01Enunciado.md
    ou em trabalho01Enunciado.pdf    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOME: GABRIEL VELHO DE SOUZA
//MATRICULA: 2420152183

typedef struct Cadastro
{ 
    char CNPJ[15]; 
    char RazaoSocial[50]; 
    char Cidade[30]; 
    char Fone[12]; 
    char Tipo; 
} TCadastro; 

typedef struct No
{ 
    TCadastro *Dados; 
    struct No *Ant; 
    struct No *Prox; 
} TNo; 

typedef struct Descritor
{ 
    TNo *Inicio; 
    int Tamanho; 
    TNo *Fim; 
} TDescritor;

void inserir(TNo **lista, char cnpj[], char razaoSocial[], char cidade[], char fone[], char tipo)
{
    TCadastro *cad = (TCadastro *)malloc(sizeof(TCadastro));

    strcpy(cad->CNPJ, cnpj);
    strcpy(cad->RazaoSocial, razaoSocial);
    strcpy(cad->Cidade, cidade);
    strcpy(cad->Fone, fone);
    cad->Tipo = tipo;

    TNo *novo = (TNo *)malloc(sizeof(TNo));

    novo->Dados = cad;
    novo->Prox = NULL;
    novo->Ant = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
    }

    else
    {
        TNo *aux = *lista;

        while (aux->Prox != NULL)
        {
            aux = aux->Prox;
        }
        aux->Prox = novo;
        novo->Ant = aux;
    }
}

void inserirIndustria(TNo **lista, char cnpj[], char razaoSocial[], char cidade[], char fone[])
{
    inserir(lista, cnpj, razaoSocial, cidade, fone, 'I');
}

void inserirComercio(TNo **lista, char cnpj[], char razaoSocial[], char cidade[], char fone[])
{
    inserir(lista, cnpj, razaoSocial, cidade, fone, 'C');
}

void inserirServicos(TNo **lista, char cnpj[], char razaoSocial[], char cidade[], char fone[])
{
    inserir(lista, cnpj, razaoSocial, cidade, fone, 'S');
}
void processarLinha(TNo **lista, char linha[], char tipo)
{
    char *cnpj = strtok(linha, ";");
    char *razao = strtok(NULL, ";");
    char *cidade = strtok(NULL, ";");
    char *fone = strtok(NULL, ";\n");

    if (cnpj && razao && cidade && fone)
    {
        printf("Lido: %s | %s | %s | %s | %c\n",
           cnpj,
           razao,
           cidade,
           fone,
           tipo);
        inserir(lista, cnpj, razao, cidade, fone, tipo);
    }
}

void carregarArquivo(TNo **lista, const char *nomeArquivo, char tipo)
{
    FILE *arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    char linha[120];

    while (fgets(linha, sizeof(linha), arq))
    {
        processarLinha(lista, linha, tipo);
    }

    fclose(arq);
}

void imprimir(TNo *lista)
{

    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (lista != NULL)
    {
        printf("%s | %s | %s | %s | %c\n",
               lista->Dados->CNPJ,
               lista->Dados->RazaoSocial,
               lista->Dados->Cidade,
               lista->Dados->Fone,
               lista->Dados->Tipo);
        lista = lista->Prox;
    }
}

void imprimirInvertido(TNo *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    TNo *aux = lista;

    while (aux->Prox != NULL)
    {
        aux = aux->Prox;
    }

    while (aux != NULL)
    {
        printf("\n------------------------\n");
        printf("CNPJ: %s\n", aux->Dados->CNPJ);
        printf("Razao Social: %s\n", aux->Dados->RazaoSocial);
        printf("Cidade: %s\n", aux->Dados->Cidade);
        printf("Fone: %s\n", aux->Dados->Fone);
        printf("Tipo: %c\n", aux->Dados->Tipo);

        aux = aux->Ant;
    }

    printf("\n");
}

void copiarParaUnificada(TNo *origem, TNo **unificada)
{
    TNo *aux = origem;

    while (aux != NULL)
    {
        inserir(
            unificada,
            aux->Dados->CNPJ,
            aux->Dados->RazaoSocial,
            aux->Dados->Cidade,
            aux->Dados->Fone,
            aux->Dados->Tipo
        );

        aux = aux->Prox;
    }
}

void gerarListaUnificada(
    TNo *industria,
    TNo *comercio,
    TNo *servicos,
    TNo **unificada)
{
    copiarParaUnificada(industria, unificada);
    copiarParaUnificada(comercio, unificada);
    copiarParaUnificada(servicos, unificada);
}

void apagarLista(TNo **lista)
{
    TNo *aux = *lista;

    while (aux != NULL)
    {
        TNo *proximo = aux->Prox;

        free(aux->Dados);
        free(aux);

        aux = proximo;
    }

    *lista = NULL;
}

int main()
{
    int escolha;
    TNo *listaIndustria = NULL;
    TNo *listaComercio = NULL;
    TNo *listaServicos = NULL;
    TNo *listaUnificada = NULL;

    do
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Carregar Dados de Entrada\n");
        printf("2 - Gerar Lista Unificada\n");
        printf("3 - Relatório: Industrias\n");
        printf("4 - Relatório: Comércio\n");
        printf("5 - Relatório: Comércio Invertida \n");
        printf("6 - Relatório: Serviços \n");
        printf("7 - Relatório: Serviços Invertida \n");
        printf("8 - Relatório: Lista Unificada \n");
        printf("9 - Relatório: Lista Unificada Invertida \n");
        printf("10 - Apagar Listas \n");
        printf("0 - Sair\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                carregarArquivo(&listaIndustria, "Industria.txt", 'I');
                carregarArquivo(&listaComercio, "Comercio.txt", 'C');
                carregarArquivo(&listaServicos, "Servicos.txt", 'S');
                printf("Dados carregados com sucesso.\n");
                break;

            case 2:

                if (listaUnificada != NULL)
                {
                    printf("Lista unificada ja foi gerada.\n");
                    break;
                }

                gerarListaUnificada(
                    listaIndustria,
                    listaComercio,
                    listaServicos,
                    &listaUnificada
                );

                printf("Lista unificada gerada com sucesso.\n");
                break;

            case 3:
                printf("\n===== RELATORIO INDUSTRIA =====\n");
                imprimir(listaIndustria);
                break;

            case 4:
                printf("\n===== RELATORIO COMERCIO =====\n");
                imprimir(listaComercio);
                break;

            case 5:
                printf("\n===== RELATORIO COMERCIO INVERTIDO =====\n");
                imprimirInvertido(listaComercio);
                break;

            case 6:
                printf("\n===== RELATORIO SERVICOS =====\n");
                imprimir(listaServicos);
                break;

            case 7:
                printf("\n===== RELATORIO SERVICOS INVERTIDO =====\n");
                imprimirInvertido(listaServicos);
                break;

            case 8:
                printf("\n===== RELATORIO LISTA UNIFICADA =====\n");
                imprimir(listaUnificada);
                break;

            case 9:
                printf("\n===== RELATORIO LISTA UNIFICADA INVERTIDA =====\n");
                imprimirInvertido(listaUnificada);
                break;

            case 10:

                apagarLista(&listaIndustria);
                apagarLista(&listaComercio);
                apagarLista(&listaServicos);
                apagarLista(&listaUnificada);

                printf("Listas apagadas com sucesso.\n");

                break;

            case 0:
                apagarLista(&listaIndustria);
                apagarLista(&listaComercio);
                apagarLista(&listaServicos);
                apagarLista(&listaUnificada);

                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }while(escolha !=0);

    return 0;
}