#include <stdio.h>
/*  Exercício 8 — Contagem de caracteres
    Dada uma string:
        char nome[] = "programacao";

    Crie uma função:
        int conta(char *str, char c);
        
    Retorne quantas vezes c aparece
    Use apenas ponteiros    */

    int conta(char *str, char c)
    {
        int repeticoes = 0;

        while (*str != '\0') //enquanto o caractere atual NÃO for o fim da string, pois toda string termina com '\0'
        {
            if (*str == c)
            {
                repeticoes++;
            }
            str++; //aritmetica de ponteiro, é pra ir andando na lista
        }

        return repeticoes;
    }

int main()
{
    char nome[] = "programacao";

    printf("%d", conta(nome, 'a'));

    return 0;
}