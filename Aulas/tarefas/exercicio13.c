#include <stdio.h>
/*
* A estrutura de dados Aluno é definida para armazenar o nome do aluno (com máximo 50 caracteres) e a sua nota final.
*/
typedef struct 
{
    char nome[50];
    float NotaFinal;
} Aluno;

int main()
{
    // Um aluno "joaozinho" é inicializado com um nome e nota final especificos.
    Aluno joaozinho = {"joaozinho", 8.5};
    
    /* O ponteiro 'ptr' é declarado para apontar para a estrutura de dados 'Aluno'. Nesse caso, o endereço da memoria onde está armazenada a estrutura 'joaozinho' é atribuído a esse ponteiro. */
    Aluno *ptr = &joaozinho;
    
    /*imprimir o nome e nota final do aluno apontado pelo ponteiro 'ptr'. O operador '->' é usado para acessar os campos da estrutura de dados. */
    printf("%s %.2f", ptr->nome, ptr->NotaFinal);
    
    //Um array de alunos 'turma' é declarado.
    Aluno turma[3]; 
    
    /* O ponteiro 'ptrTurma' é inicializado para apontar para o primeiro elemento do array 'turma'. */
    Aluno *ptrTurma = turma; 
    
    // A nota final do primeiro aluno da turma é atualizada.
    ptrTurma->NotaFinal = 5.5;

    /* As seguintes linhas são utilizadas para atribuir notas finais aos outros alunos (segundo e terceiro aluno da turma) do array 'turma'. A aritmética de ponteiros é usada para isso. */
    (ptrTurma+1) -> NotaFinal = 6.5; 
    (ptrTurma+2) -> NotaFinal = 7.5; 
    
    /* O ponteiro 'ptrTurma' é utilizado para imprimir as notas finais dos alunos da turma. */
    printf("\n%.2f %.2f %.2f", ptrTurma->NotaFinal, (ptrTurma+1)->NotaFinal, (ptrTurma+2)->NotaFinal);

    return 0;
}