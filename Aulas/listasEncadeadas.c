#include <stdio.h>

/*
em C, um vetor não pode ter seu tamanho alterado, após criado, tem tamanho fixo
o problema é que, ao usar todos os espaços, não se pode aumentar o vetor
e ao não usar todos os espaços, tem-se desperdício de memória

já as listas encadeadas são estruturas de dados dinâmicas, onde cada elemento (nó) contém um valor e um ponteiro para o próximo nó
elas permitem a inserção e remoção de elementos de forma eficiente, sem a necessidade de realocar a memória, como acontece com os vetores
as listas encadeadas são compostas por nós, onde cada nó contém um valor e um ponteiro para o próximo nó
a primeira posição da lista é chamada de cabeça (head) e a última posição é chamada de cauda (tail)

o problema de uma lista encadeada é o acesso a um nó especifico, pois o que com vetores é O(1), com listas encadeadas é O(n)
pois é necessário percorrer a lista do início até o nó desejado
*/

typedef struct No
{
    int valor; // valor armazenado no nó
    struct No *proximo; // ponteiro para o próximo nó da lista
} No;

No *IncluiCabeca(No *pLista, int pValor)
{
//Cria um novo nó e o torna a nova cabeça da lista

    No *pNovoNo; // Declara um ponteiro para o novo nó que será criado
    pNovoNo = (No *) malloc(sizeof(No)); // Aloca memória dinamicamente para um novo nó
    pNovoNo->valor = pValor; // Armazena o valor recebido no campo valor do novo nó
    pNovoNo->proximo = pLista; // Faz o novo nó apontar para a lista atual, o antigo primeiro elemento da lista
    pLista = pNovoNo; // Atualiza a cabeça da lista para ser o novo nó
    return pLista; // Retorna o endereço da nova cabeça da lista

//complexidade O(1) - melhor caso, pior caso e caso médio, pois não depende do tamanho da lista
}

No *IncluiCalda(No *pLista, int pValor)
{
//Cria um novo nó e o inclui no final da lista

    // pNovoNo será o novo elemento
    // pAux será usado para percorrer a lista
    No *pNovoNo, *pAux;
    pNovoNo = (No *) malloc(sizeof(No)); // Aloca memória para o novo nó

    pNovoNo->valor = pValor; // Armazena o valor recebido
    pNovoNo->proximo = NULL; // Como será o último nó da lista, ele aponta para NULL

    pAux = pLista; // Começa a percorrer a lista a partir da cabeça

    while (pAux->proximo != NULL) // Avança até encontrar o último nó
    {
        pAux = pAux->proximo; // Move o ponteiro pAux para o próximo nó
    } 

    pAux->proximo = pNovoNo;  // Faz o último nó apontar para o novo nó

    return pLista; // Retorna a cabeça da lista (que não mudou)

//complexidade O(n) - melhor caso, pior caso e caso médio, pois depende do tamanho da lista, pois é necessário percorrer a lista até o final para inserir o novo nó
}

No *IncluiAntes(No *pLista, int pChave, int pValor)
{
// Cria um novo nó e o inclui antes do nó que contém a chave recebida, não funciona caso seja o primeiro no da lista

    No *pNovoNo, *pAux;// Ponteiro para o novo nó e para percorrer a lista
    pNovoNo = (No *) malloc(sizeof(No)); // Aloca memória para o novo nó

    pNovoNo->valor = pValor;// Armazena o valor que será inserido
    pAux = pLista;// Começa a busca pela cabeça da lista

    while (pAux->proximo != NULL && pAux->proximo->valor != pChave) // Procura o nó que está imediatamente antes do nó que contém a chave
    {   
        pAux = pAux->proximo;
    }

    pNovoNo->proximo = pAux->proximo; // O novo nó aponta para o nó que contém a chave
    pAux->proximo = pNovoNo; // O nó anterior passa a apontar para o novo nó

    return pLista;// Retorna a cabeça da lista

//complexidade O(n) - melhor caso, pior caso e caso médio, pois depende do tamanho da lista, pois é necessário percorrer a lista para encontrar o nó que contém a chave
}

No *ExcluiCabeca(No *pLista)
{
// Exclui o primeiro nó da lista e retorna a nova cabeça da lista

    No *pAux; // Ponteiro auxiliar para guardar o nó que será removido
    pAux = pLista;// pAux aponta para o primeiro nó da lista
    pLista = pLista->proximo; // A cabeça passa a ser o segundo nó
    free(pAux); // Libera a memória do antigo primeiro nó
    return pLista; // Retorna a nova cabeça da lista

//complexidade O(1) - melhor caso, pior caso e caso médio, pois não depende do tamanho da lista
}

No *ExcluiCalda(No *pLista)
{
// Exclui o último nó da lista e retorna a cabeça da lista

    No *pAux; // Ponteiro auxiliar para percorrer a lista
    pAux = pLista;// Começa pela cabeça
    while (pAux->proximo->proximo != NULL) // Procura o penúltimo nó
    {
        pAux = pAux->proximo;
    }

    free(pAux->proximo); // Libera o último nó
    pAux->proximo = NULL; // O penúltimo passa a ser o último
    return pLista; // Retorna a cabeça da lista

//complexidade O(n) - melhor caso, pior caso e caso médio, pois depende do tamanho da lista, pois é necessário percorrer a lista para encontrar o penúltimo nó
}

No *ExcluiChave(No *pLista, int pChave)
{
// Exclui o nó que contém a chave recebida e retorna a cabeça da lista

    No *pAnt, *pPost; // pAnt ficará apontando para o nó anterior ao nó que será removido e pPost para o nó posterior ao nó que será removido
    pAnt = pLista;// Começa pela cabeça da lista

    while (pAnt->proximo != NULL && pAnt->proximo->valor != pChave) // Procura o nó anterior ao nó que contém a chave
    {
        pAnt = pAnt->proximo;
    }

    if (pAnt->proximo != NULL) // Se encontrou a chave
    {
        pPost = pAnt->proximo->proximo; // Guarda o nó seguinte ao que será removido
        free(pAnt->proximo); // Libera o nó que contém a chave
        pAnt->proximo = pPost; // Liga o nó anterior ao próximo nó
    }
    return pLista; // Retorna a cabeça da lista

//complexidade O(n) - melhor caso, pior caso e caso médio, pois depende do tamanho da lista, pois é necessário percorrer a lista para encontrar o nó que contém a chave
}

/*
visando diminuir a complexidade de O(n) para O(1) em operações que envolvem a calda, pode-se usar uma lista encadeada com descrição
que seria basicamente adicionar um ponteiro para a cauda da lista.
*/
typedef struct ListaEncadeada
{
    No *cabeca; // Ponteiro para o primeiro nó da lista
    No *calda; // Ponteiro para o último nó da lista
    int Qtde; // Quantidade de elementos na lista
} ListaEncadeada;

int main()
{

    return 0;
}