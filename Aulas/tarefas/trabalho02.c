#include <stdio.h>
#include <tipos.h> //arquivo ligado a esse trabalho, com as structs
/*  enunciado do trabalho pode ser encontrado em trabalho02Enunciado.pdf    */

int main()
{
    int escolha;

    do 
    {
        printf("digite 1 para reset\ndigite 2 para inserir medida\ndigite 3 para estatisticas\ndigite 0 para sair\n: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 0:
            printf("encerrando o programa...");
            /* code */
            break;
        default:
            printf("\nERRO: digite um numero valido\n\n");
            break;
        }
    }while(escolha != 0);
}