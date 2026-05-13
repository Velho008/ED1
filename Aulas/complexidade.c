#include <stdio.h>
#include <string.h>
#include <time.h>
/*  
um algoritmo é um conjunto de instruções que resolvem um problema, e um bom algoritmo deve:
    -estar correto, fazer o que foi projetado para fazer
    -exigir menos recursos (tempo, espaço, etc...) do que outros algoritmos para o mesmo problema
    -conseguir prever o crescimento de recursos exigidos conforme o tamanho dos dados de entrada crescem
    
complexidade espacial de um algoritmo: memoria que necessita para executar, S(n) -> espaço de memoria exigido em função do tamanho (n) da entrada

complexidade temporal de um algoritmo: tempo de execução, T(n) -> tempo de execução em função do tamanho (n) da entrada*/

//exemplo de um quebrador de senhas:

#include <stdio.h>
#include <string.h>
#include <time.h>

double quebrarSenha(int quantidadeCaracteres, char *senha)
{
    clock_t inicio, fim;

    inicio = clock();

    int max = 1;

    // calcula 10^n
    for(int i = 0; i < quantidadeCaracteres; i++)
    {
        max *= 10;
    }

    char tentativa[20];

    for(int i = 0; i < max; i++)
    {
        // gera tentativa com zeros à esquerda
        sprintf(tentativa, "%0*d", quantidadeCaracteres, i);
        printf("%s\n", tentativa);

        // compara
        if(strcmp(tentativa, senha) == 0)
        {
            fim = clock();

            return (double)(fim - inicio) / CLOCKS_PER_SEC;
        }
    }

    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main()
{
    int quantidade = 4;

    char senha[quantidade+1];

    printf("DIGITE A SENHA\n");
    printf("Ela deve ter exatamente %d numeros\n: ", quantidade);

    scanf("%8s", senha);

    double tempo = quebrarSenha(quantidade, senha);

    printf("\nSenha encontrada!\n");
    printf("Tempo para quebrar: %.3f segundos\n", tempo);

    return 0;
}