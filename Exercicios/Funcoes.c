#include <stdio.h>

int soma(int x, int y)
{
    return (x+y);
}

int maior(int x, int y, int z)
{
    int m = x;

    if (y>m) m=y;
    if (z>m) m=z;

    return m;
}

int ehPar(int n)
{
    return n%2==0; //1 se for par e 0 se for impar
}

void trocar(int x, int y)
{
    printf("%d, %d, troquei a ordem no print\nnão tem como trocar a ordem sem alterar por ponteiro",y, x);
}

float media(float a, float b, float c)
{
    return ((a+b+c)/3);
}

int fatorial(int n)
{
    if (n==1) return n;
    return n*fatorial(n-1); //recursividade, se não entender, ver o arquivo recursividade em /aulas/
}

int main()
{
    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    printf("maior entre os 3: %d\n", maior(a,b,c));
    if (ehPar(maior(a,b,c)))
    {
        printf("e eh par\n");
    }
    else
    {
        printf("e eh impar\n");
    }
    printf("fatorial do numero: %d", fatorial(maior(a,b,c)));

    return 0;
}