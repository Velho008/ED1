#include <stdio.h>
/*
#include <graphics.h>

void estrela(int x, int y, int r)
{
    if (r <= 1)
        return;

    // desenha um quadrado
    rectangle(x - r, y - r, x + r, y + r);

    // chamadas recursivas
    estrela(x - r, y - r, r / 2);
    estrela(x + r, y - r, r / 2);
    estrela(x - r, y + r, r / 2);
    estrela(x + r, y + r, r / 2);
}
    */
int pot(int base, int expoente)
{
    if (!expoente)
    {
        return 1;
    }
    return base * pot(base, expoente - 1);
}

int main()
{
    printf("%d\n", pot(2, 10));

    return 0;
}