#include <stdio.h>

//para compreender essas anotações, veja "listasEncadeadas.c"

/*
a unica diferença entre uma lista encadeada e uma lista circular é que, na lista circular, o último nó aponta para o primeiro nó, formando um ciclo
essa estrutura é útil para representar situações em que o final da lista deve ser conectado ao início, como em jogos de tabuleiro, filas circulares, etc.

é possivel fazer tambem uma lista circular duplamente encadeada, onde cada nó tem um ponteiro para o próximo nó e um ponteiro para o nó anterior
permitindo uma navegação mais flexível pela lista
nesse caso o primeiro nó aponta para o último nó e o último nó aponta para o primeiro nó, formando um ciclo duplo
*/