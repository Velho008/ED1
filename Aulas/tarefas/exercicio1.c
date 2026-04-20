#include <stdio.h>

int mostrarEstoque(int estoque[], char catalogo[][10], int tamanho)
{
    printf("ESTOQUE\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%s: %d unidades\n", catalogo[i], estoque[i]);
    }
}

int comprar(int estoque[], char catalogo[][10], int tamanho)
{
    int produto;
    int quantidade;
    
    mostrarEstoque(estoque, catalogo, tamanho);

    printf("\nbem vindo ao mercadinho do velho\n");
    printf("selecione o produto que deseja comprar:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d %s\n", i, catalogo[i]);
    }
    printf("digite o numero do produto: ");
    scanf("%d", &produto);
    printf("produto escolhido: %s\n", catalogo[produto]);
    printf("o produto escolhido tem disponibilidade de %d unidades \n", estoque[produto]);
    printf("digite a quantidade de %s desejada: ", catalogo[produto]);
    scanf("%d", &quantidade);

    if (estoque[produto] < quantidade)
    { 
    printf("ERRO: deseja comprar mais do que o estoque(%d) permite", estoque[produto]);
    return 0;
    }
    estoque[produto] -= quantidade;
    printf("%d %s comprados com sucesso", quantidade, catalogo[produto]);
    printf("nova quantidade de %s: %d", catalogo[produto], estoque[produto]);
    return 1;
}

int estocar(int estoque[], char catalogo[][10], int tamanho)
{
    int produto;
    int quantidade;
    
    mostrarEstoque(estoque, catalogo, tamanho);

    printf("\nbem vindo ao mercadinho do velho\n");
    printf("selecione o produto que deseja estocar:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d %s\n", i, catalogo[i]);
    }
    printf("digite o numero do produto: ");
    scanf("%d", &produto);
    printf("produto escolhido: %s\n", catalogo[produto]);
    printf("o produto escolhido tem %d unidades no estoque\n", estoque[produto]);
    printf("digite a quantidade de %s a adicionar: ", catalogo[produto]);
    scanf("%d", &quantidade);

    estoque[produto] += quantidade;
    printf("%d %s estocados com sucesso\n", quantidade, catalogo[produto]);
    printf("nova quantidade de %s: %d", catalogo[produto], estoque[produto]);
    return 1;
}

/* ENUNCIADO:
Descrição do Problema
Você precisa criar um sistema de controle de estoque para
um supermercado que mantém a contagem de produtos
diferentes em um vetor. Cada índice do vetor representa um
tipo de produto (por exemplo, índice 0 para arroz, índice
1 para feijão , etc . ) , e o valor em cada índice indica a
quantidade atual desse produto no estoque.

Objetivo
Escreva um programa que inicialize este vetor com
quantidades aleatórias para 10 produtos diferentes,
permita ao usuário “comprar” produtos (diminuindo a
quantidade do estoque), e adicionar novos produtos ao
estoque. O programa deve imprimir o estado atual do
estoque após cada operação.
*/
int main()
{
    char catalogo[10][10] = 
    {
        "arroz",
        "feijao",
        "leite",
        "cafe",
        "macarrao",
        "frango",
        "carne",
        "fruta",
        "mel",
        "pao"
    };
    int estoque[10] = {3,2,4,5,61,1,8,9,22,0};
    int tamanho = (sizeof(catalogo)/sizeof(catalogo[0]));
    int escolha;
    
    do
    {

        printf("\nescolha o que fazer:\n1: comprar\n2: estocar\n3: mostrar estoque\n0: sair\ndigite a escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            comprar(estoque, catalogo, tamanho);
            break;
        case 2:
            estocar(estoque, catalogo, tamanho);
            break;
        case 3:
            mostrarEstoque(estoque, catalogo, tamanho);
            break;
        case 0:
            break;
        default:
            printf("opção invalida");
            break;
        }
    } while(escolha !=0);
    //pensei em implementar typedef pra produtos, catalogo e esse sizeof pra chamar de mercadinho, mas dá mto trabalho
    //pensei em tratar erros pra entrada aceitar string e dar erro no lugar de só crashar
    //falta começar com numero aleatorios, atualmente é fixo

    return 0;
}