#include <stdio.h>
/*  Exercício 11 — Comparação de strings
    Implemente sua própria versão de:
        int compara(char *s1, char *s2);
    Retorne:
    0 se iguais
    <0 se s1 < s2
    0 se s1 > s2
    Sem usar strcmp    */

//não compreendi 100% o que foi pedido, acho que é pra comparar tamanho de str

int compara(char *s1, char *s2)
{
    while (1)
    {
        if (*s2 == '\0') return 0; //se esse for o caso, s2 é igual ou menor a s1

        if (*s1 == '\0') return -1; //só acontece quando s1 é vazio e s2 não é, portanto s1 < s2

        s1++;
        s2++;
    }
}

int main()
{

    char s1[] = "programacao";
    char s2[] = "programacao";

    printf("%d", compara(s1, s2));

    return 0;
}