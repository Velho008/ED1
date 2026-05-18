#include <stdio.h>

int main()
{
    //exemplo pra analisar nivel de complexidade:
    int vetor[20];
    //     a          b      c
    for (int i = 0; i < 10; i++) 
    {
        vetor[i]=i; //d
        vetor[i+1]=7; //e([i+1]) f = 7 
    }
/*  a executa uma vez (i = 0)
    b executa 11 vezes (true nas primeiras 10, false na 11)
    c executa 10 vezes
    d executa 10 vezes
    e executa 10 vezes
    f executa 10 vezes

    complexidade O(n): (com numeros reais, por conta do codigo contendo numeros reais)
    a = O(1)
    b = O(11)
    c = O(20) (pois executa += 10 vezes, totalizando 20 instruções)
    d = O(10)
    e = O(10)
    f = O(10)

    complexidade total do algoritmo = O(1) + O(11) + O(20) + O(10) + O(10) + O(10) = O(62)
    O(62)
*/
int n;
printf("digite o N: ");
scanf("%d\n", &n);
for (int i = 0; i < n; i++)
{
    vetor[i] = i;
    vetor[i+1] = 7;
}

/*  complexidade O(n):
    a = O(1)
    b = O(n+1)
    c = O(2n)
    d = O(n)
    e = O(n)
    f = O(n)

    complexidade total: O(1) + O(n+1) + O(2n) + O(n) + O(n) + O(n) = O(6n+3) -> O(n) (complexidade linear)
*/
int k = 0;
//      a        b     c
for (int i = 0; i < n; i++)
{
    //      d        e      f
    for (int j = 0; j < n; j++)
    {
        //g   h   i
        k = k + i*j;
    }
}

/*  complexidade O(n):
    a = O(1)
    b = O(n+1)
    c = O(2n+2)
    d = O(n)
    e = O(n(n+1)) -> O(n²+n) -> O(n²)
    f = O(n(n+1)) -> O(n²+n) -> O(n²)
    g = O(n²)
    h = O(n²)
    i = O(n²)

    complexidade total: O(1) + O(n+1) + O(2n+2) + O(n) + O(n²+n) + O(n²+n) + O(n²) + O(n²) + O(n²) = O(6n²+6n+4) -> O(n²) quadratica
*/

/*  portanto, se o algoritmo tiver varios niveis de complexidades misturados, o que prevalece é sempre o de maior complexidade
*/

    return 0;
}