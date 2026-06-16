#include <stdio.h>
#include <stdlib.h>

/*
uma lista duplamente encadeada é basicamente uma lista encadeada
mas cada nó contem um ponteiro adicional, para o nó anterior

isso permite que a lista seja navegada em ambas as direções
uma lista duplamente encadeada pode ser circular
o ultimo nó aponta para o primeiro nó e o primeiro nó aponta para o último nó, formando um ciclo duplo

em uma lista duplamente encadeada simples
o primeiro nó tem o ponteiro para o nó anterior apontando para NULL
e o ultimo nó tem o ponteiro para o nó seguinte apontando para NULL

em uma lista duplamente encadeada operações no final da lista são mais eficientes do que em uma lista encadeada simples
pois não é necessário percorrer toda a lista para encontrar o último nó caso exista descritor
O(1) vs O(n)

inclusões e exclusões demandam mais atenção, visto que devemos atualizar ambos os ponteiros
*/

typedef struct No
{
    int numero;
    struct No *proximo;
    struct No *anterior;
} No;

No *IncluiCabeca(No *pLista, int pValor)
{
    No *pNovoNo; //cria o novo nó
    pNovoNo = (No *) malloc(sizeof(No)); //aloca memoria para o novo nó

    pNovoNo->numero = pValor; //atribui o valor ao campo numero do novo nó
    pNovoNo->anterior = NULL; //o novo nó será o primeiro nó da lista, então seu ponteiro para o nó anterior deve apontar para NULL
    pNovoNo->proximo = pLista; //o ponteiro para o nó seguinte aponta para o primeiro nó da lista

    pLista->anterior = pNovoNo; //o ponteiro para o nó anterior do primeiro nó da lista deve apontar para o novo nó
    pLista = pNovoNo; //a cabeça da lista passa a ser o novo nó

    return pLista; //retorna a cabeça da lista
}

No *IncluiCalda(No *pLista, int pValor)
{
    No *pNovoNo, *pAux; //cria o novo nó e um ponteiro auxiliar para percorrer a lista
    pNovoNo = (No *) malloc(sizeof(No)); //aloca memoria para o novo nó

    pNovoNo->numero = pValor; //atribui o valor ao campo numero do novo nó
    pNovoNo->proximo = NULL; //o novo nó será o último nó da lista, então seu ponteiro para o nó seguinte deve apontar para NULL

    pAux = pLista; //comeca a percorrer a lista
    while (pAux->proximo != NULL)
    {
        pAux = pAux->proximo; //enquanto o ponteiro para o nó seguinte do nó auxiliar não for NULL, continua percorrendo a lista
    } 

    pAux->proximo = pNovoNo; //o ponteiro para o nó seguinte do último nó da lista deve apontar para o novo nó
    pNovoNo->anterior = pAux; //o ponteiro para o nó anterior do novo nó deve apontar para o último nó da lista

    return pLista; //retorna a cabeça da lista
}

No *IncluiDepois(No *pLista, int pChave, int pValor)
{
    No *pNovoNo, *pAux; //cria o novo nó e um ponteiro auxiliar para percorrer a lista
    pNovoNo = (No *) malloc(sizeof(No)); //aloca memoria para o novo nó

    pNovoNo->numero = pValor; //atribui o valor ao campo numero do novo nó

    pAux = pLista; //comeca a percorrer a lista
    while (pAux->proximo->numero != pChave)
    {
        pAux = pAux->proximo; //enquanto o ponteiro para o nó seguinte do nó auxiliar não for NULL e o campo numero do nó seguinte do nó auxiliar for diferente da chave, continua percorrendo a lista
    } 

    pNovoNo->proximo = pAux->proximo; //o ponteiro para o nó seguinte do novo nó deve apontar para o nó seguinte do nó auxiliar
    pNovoNo->anterior = pAux; //o ponteiro para o nó anterior do novo nó deve apontar para o nó auxiliar

    pAux->proximo = pNovoNo; //o ponteiro para o nó seguinte do nó auxiliar deve apontar para o novo nó

    pNovoNo->proximo->anterior = pNovoNo; //o ponteiro para o nó anterior do nó seguinte do novo nó deve apontar para o novo nó
    return pLista; //retorna a cabeça da lista
}

No *ExcluiCabeca(No *pLista)
{
    pLista = pLista->proximo; //a cabeça da lista passa a ser o segundo nó da lista
    free(pLista->anterior); //libera a memoria do antigo primeiro nó da lista
    pLista->anterior = NULL; //o ponteiro para o nó anterior do novo primeiro nó da lista deve apontar para NULL
    return pLista; //retorna a cabeça da lista
}

No *ExcluiCalda(No *pLista)
{
    No *pAux; //cria um ponteiro auxiliar para percorrer a lista

    pAux = pLista; //comeca a percorrer a lista
    while (pAux->proximo->proximo != NULL)
    {
        pAux = pAux->proximo; //enquanto o ponteiro para o nó seguinte do nó auxiliar não for NULL e o ponteiro para o nó seguinte do nó seguinte do nó auxiliar não for NULL, continua percorrendo a lista
    } 

    free(pAux->proximo); //libera a memoria do último nó da lista

    pAux->proximo = NULL; //o ponteiro para o nó seguinte do penúltimo nó da lista deve apontar para NULL

    return pLista; //retorna a cabeça da lista
}

No *ExcluiChave(No *pLista, int pChave)
{
    No *pAux; //cria um ponteiro auxiliar para percorrer a lista
    pAux = pLista; //comeca a percorrer a lista

    while (pAux->numero != pChave)
    {
        pAux = pAux->proximo; //enquanto o campo numero do nó auxiliar for diferente da chave, continua percorrendo a lista
    }

    pAux->anterior->proximo = pAux->proximo; //o ponteiro para o nó seguinte do nó anterior do nó auxiliar deve apontar para o nó seguinte do nó auxiliar
    pAux->proximo->anterior = pAux->anterior; //o ponteiro para o nó anterior do nó seguinte do nó auxiliar deve apontar para o nó anterior do nó auxiliar

    free(pAux); //libera a memoria do nó auxiliar, que é o nó que contém a chave a ser excluída

    return pLista; //retorna a cabeça da lista
}

//caso a lista tenha um descritor, as operações de inclusão e exclusão no final da lista podem ser feitas em O(1), 
//pois o descritor pode conter um ponteiro para o último nó da lista, evitando a necessidade de percorrer toda a lista para encontrar o último nó

typedef struct Descritor
{
    No *cabeca; //ponteiro para o primeiro nó da lista
    No *calda; //ponteiro para o último nó da lista
    int tamanho; //campo para armazenar o tamanho da lista
} Descritor;    


int main()
{

    return 0;
}