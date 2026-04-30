#include <stdio.h>
// Definição de um tipo struct para 'ponto'. Este é um ponto 2D com coordenadas x e y inteiras.
typedef struct 
{
    int x;
    int y;
} ponto;

int main() 
{
    // Inicialização de uma variável do tipo 'ponto' chamada 'p1'. As coordenadas deste ponto são (10, 20).
    ponto p1 = {10, 20};
    // Declaração de uma variável do tipo 'ponto' chamada 'p2'.
    ponto p2;
    // Atribui valores às coordenadas deste segundo ponto.
    p2.x = 30;
    p2.y = 40;

    // Até aqui, tudo funcionou perfeitamente normalmente.

    // Definição de um ponteiro para 'ponto' chamado 'ptr'. Este é utilizado para acessar os valores dos pontos por referência.
    ponto *ptr;
    // Atribui o endereço da variável p1 à este ponteiro, permitindo-nos acessar os seus valores através deste ponteiro.
    ptr = &p1;

    //ptr.y pra var comum
    //ptr->y pra struct
    printf("%d %d\n", ptr->x, (*ptr).y);

    return 0;
}

