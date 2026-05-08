/*  Input record for employ
    –Name
    –Age
    –Basic salary
    Input record as much as user required
    Write record in file employee.dat   */
#include <stdio.h>
typedef struct 
{
    char name[50];
    int age;
    float basic_salary;
} Empregado;

Empregado criarEmpregado()
{
    Empregado empregado;
    printf("\ndigite o nome do empregado: ");
    scanf("%s", empregado.name); //pra string nao precisa do &

    printf("\ndigite a idade do empregado: ");
    scanf("%d", &empregado.age);

    printf("\ndigite o salario do empregado: ");
    scanf("%f", &empregado.basic_salary);

    return empregado;
}

void salvarEmpregado(Empregado empregado)
{
    FILE *arquivo;
    arquivo = fopen("bin/employee.dat", "a");

    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo");
        return;
    }

    fprintf(arquivo, "%s;%d;%.2f\n",
            empregado.name, 
            empregado.age, 
            empregado.basic_salary);
    fclose(arquivo);
}

int main() 
{
    int escolha;
    do
    {
        printf("\ndigite 1 para registrar um empregado ou 0 para sair: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            Empregado empregado;
            empregado = criarEmpregado();
            salvarEmpregado(empregado);
            break;

        case 0:
            break;
        
        default:
            printf("digite um numero valido");
            break;
        }
    }while(escolha !=0);


    return 0;
}
