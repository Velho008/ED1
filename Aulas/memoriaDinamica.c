/*  alocação dinamica permite alocar e desalocar durante tempo de execução
    pois as vezes só é possivel saber o tamanho em tempo de execução, que varia cada vez que o programa é rodado ou não, dependendo de contextos

    principais pra manipular memória dinamica
    malloc: alocar memória
    free: desalocar memória (gerencia o lixo)
    calloc: alocar e zerar memória
    realloc: redimensionar memória


    fopen: abrir arquivos (não se sabe o tamanho até abrir)

    em C/C++ é feito via ponteiros e com funções/operadores de alocação e desalocação

    MALLOC
    exemplo de vetor dinamico em C:
    tipo do dado *nome = (tipo do dado *) malloc(sizeof(tipo do dado) * tamanho);
    tipo assim: 
    int *vetor= (int*)malloc(sizeof(int)*10);
        int *vetor cria um ponteiro para inteiro.
        malloc(...) reserva espaço na memória.
        sizeof(int) calcula quantos bytes um inteiro ocupa.
        sizeof(int) * 10 reserva espaço suficiente para 10 inteiros.
        O (int*) converte o retorno de malloc para ponteiro de inteiro.
        Em outras palavras, o programa está dizendo:
        “Reserve memória suficiente para armazenar 10 valores inteiros e faça o ponteiro vetor apontar para esse espaço.”

    CALLOC
    exemplo com calloc
    tipo do dado * nome = (tipo do dado *) calloc (tamanho, sizeof(tipo do dado));
    int *vetor= (int *) calloc(10, sizeof(int));
        “Reserve memória para 10 elementos do tipo inteiro.”
        malloc: Aloca memória, mas não inicializa os valores.
        calloc: Aloca memória e inicializa tudo com zero.

    ao fazer uma coisa com vetor ou matriz, com tamanho que pode variar, isso é um exemplo de alocação dinamica
    pilha, fila, arvore binaria, é tudo coisa que usa alocação dinamica     */

    #include <stdio.h>
    #include <stdlib.h>
int main() 
{
    int *vetor;
    vetor= (int *) calloc(5, sizeof(int)); //5 elementos, todos = 0

    if (vetor== NULL) //verifica se a memória foi alocada, boa pratica, seguir SEMPRE
    {
        printf("Erro ao alocarmemoria.\n"); //imprime erro
        return 1; //retorna 1 para indicar erro e encerra o programa, continuar com memoria errada é perigoso
    }

    vetor[0] = 10;
    vetor[1] = 20;
    printf("%d\n", vetor[0]);
    printf("%d\n", vetor[1]);

    free(vetor);//Isso evita vazamentos de memória (memoryleak)
    // agora o ponteiro vetor aponta para lugar nulo, causando um danging pointer
    vetor = NULL;//Boa prática para evitar ponteiros pendurados (danglingpointers)

    int *p; 
    p = malloc(sizeof(int));
    free(p);
    p = NULL;

/*  Vetores em C não armazenam seu tamanho e não existe len() nativo
    Para vetores estáticos, usamos:
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    Ex.: 16 bytes / 4 bytes = 4 elementos
    Isso só funciona para vetores estáticos
    Em vetores dinâmicos (malloc), a variável guarda apenas um ponteiro    */

    return 0;
}