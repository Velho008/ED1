/*
ponteiros servem pra alocar memoria
ao criar a main o programa aloca memoria pra main
ao criar variaveis, elas são alocadas em um lugar na memoria
ao dar valor pras variaveis, aquele local na memoria passa a ter aquele valor
um ponteiro é uma variavel que armazena o endereço de um local de memoria (ou o endereço de outra variavel)

DECLARANDO UM PONTEIRO
tipo *nome_ponteiro //tipo é o tipo do dado que o ponteiro aponta

& pega endereço
* pega o valor do endereço
*nome é um ponteiro ou o valor do endereço de um ponteiro

SEMPRE INICIALIZA O PONTEIRO ANTES DE USAR
nao tente acessar areas nao alocadas da memoria


*/

int main()
{
    int numero; //inicializei a variavel
    numero = 12983; //dei valor
    printf("%d\n", numero); //valor printado
    printf("%p\n", &numero); //endereço da variavel numero
    int *ponteiro; //inicializei o ponteiro
    ponteiro = &numero; //agora o ponteiro tem o endereço de numero

    *ponteiro = 333; //agora numero = 333, pois o valor do endereço foi alterado
    printf("%d", *ponteiro); //printa o valor do numero

    // exemplo de trocar um num por outro usando funcao com e sem ponteiro
    // mostrar a coisa de ponteiro com vetor, pra imprimir os termos
    // mostrar aumentando o valor do ponteiro em 1
    // mostrar malloc() e free()
    return 0;
}