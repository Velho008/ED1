#include <stdio.h>
// Definição da estrutura Livro com três campos: titulo (um array de caracteres de 100 elementos), autor (um array de caracteres de 50 elementos) e anoPublicacao (um número inteiro).
typedef struct 
{
    char titulo[100];
    char autor[50];
    int anoPublicacao;
} Livro;

int main()
{
    // Declaração de um livro do tipo Livro.
    Livro livro1;
    
    printf("digite o titulo do livro: ");
    fgets(livro1.titulo, 100, stdin);
    
    printf("digite o autor do livro: ");
    fgets(livro1.autor, 50, stdin);
    
    printf("digite o ano de publicacao do livro: ");
    scanf("%d", &livro1.anoPublicacao);
    
    // Impressão dos dados do livro digitado pelo usuário.
    printf("%s %s %d\n", livro1.titulo, livro1.autor, livro1.anoPublicacao);
    
    Livro *ptr; 
    // Atribuição da posição de memória do 'livro1' ao ponteiro 'ptr'.
    ptr = &livro1;
    // Impressão dos dados do livro através do ponteiro.
    printf("%s %s %d\n", ptr->titulo, ptr->autor, ptr->anoPublicacao);
    
    return 0;
}