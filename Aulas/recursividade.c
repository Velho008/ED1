#include <stdio.h>

int fatorial(int n)
    {
        if (n==0) return 1; //caso base
        return n*fatorial(n-1); //caso recursivo
    }
void torreHanoi(int n, char origem, char destino, char auxiliar, int *jogadas)
    {
        if (n == 1)
        {
            (*jogadas)++;
            printf("Mover disco 1 de %c para %c\n", origem, destino);
            printf("foram feitas %d jogadas", *jogadas);
            return;
        }

        torreHanoi(n - 1, origem, auxiliar, destino, jogadas);

        (*jogadas)++;
        printf("Mover disco %d de %c para %c\n", n, origem, destino);

        torreHanoi(n - 1, auxiliar, destino, origem, jogadas);
        // solução minima = 2^n -1 (n = quantidade de discos)
    }
int main() 
{
    //funções recursivas são aquelas que se chamam diretamente ou indiretamente durante execução
    //basicamente um if else que checa condição base
    //a ideia é sempre chegar ao caso base, que finaliza a execução e chega em um resultado
    //computacionalmente pesado

    //exemplo no code:
        //terminou?
            //SIM:
                //retorne resultados
            //NÃO:
                //roda novamente
                //tende a convergir em uma solução
    //exemplo com codigo acima e uso abaixo

    int num = 12;
    printf("Fatorial de %d: %d\n", num, fatorial(num));

    //exemplo da torre de hanoi
    int n = 10;
    int jogadas = 0;
    torreHanoi(n, 'a','b','c', &jogadas);
    

    //recursão x iteração:
        //em iteração tem um maximo definido, tipo num for, while, do while
        //ja em recursão é baseado em chamadas repetidas da propria função até cair no caso base

    return 0;
}