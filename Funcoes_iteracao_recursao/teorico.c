#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("=== TESTE C / VS CODE ===\n");

    printf("Digite seu nome: ");
    scanf("%49s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("\nOla %s!\n", nome);
    printf("Voce tem %d anos.\n", idade);

    printf("\nSe chegou ate aqui, tudo esta funcionando!\n");

    return 0;
}