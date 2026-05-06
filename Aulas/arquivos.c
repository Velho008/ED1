#include <stdio.h>

void printarArquivo(char* caminho)
{
    FILE *arquivo;
    char ch;

    arquivo = fopen(caminho, "r");

    while(1)
    {
        ch = fgetc(arquivo);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }
    fclose(arquivo);
}

int validarArquivo(char* caminho)
{
    FILE *arquivo;
    arquivo = fopen(caminho, "r");
    //caso nao encontre o arquivo, retorna NULL
    if (arquivo == NULL)
    {
        fclose(arquivo);
        return 0; //invalido
    }
    fclose(arquivo);
    return 1; //valido
}
int contarCharArquivo(char* caminho)
{
    FILE *arquivo;
    arquivo = fopen(caminho, "r");
    int quantidade = 0;

    while (1)
    {
        quantidade++;
        if (fgetc(arquivo)==EOF)
        {
            break;
        }
    }
    fclose(arquivo);
    return quantidade;
}
void copiarArquivo(char* caminho, char* caminhoFinal)
{
    FILE *arquivo;
    FILE *arquivoFinal;

    arquivo = fopen(caminho, "r"); //le o arquivo existente
    arquivoFinal = fopen(caminhoFinal, "w"); //cria o arquivo novo pra escrever

    if (!validarArquivo(caminho) | !validarArquivo(caminhoFinal)) //caso não seja possivel abrir
    {
        printf("ERRO: algum arquivo nao pode ser aberto\n");
        fclose(arquivo);
        fclose(arquivoFinal);
        return;
    }

    int ch; //int pra aguentar o EOF, não tem problema ser int pq trabalha com ascii
    while ((ch = fgetc(arquivo))!=EOF) //já faz o loop aqui dentro mesmo, trocando o ch sempre
    {
        fprintf(arquivoFinal, "%c", ch); //faz a copia char por char
    }
    fclose(arquivo);
    fclose(arquivoFinal);
}

typedef struct
{
    char nome[50];
    int paginas;
    float preco;
} Livro;


int main()
{
    FILE *arquivo;

    arquivo = fopen("alunos.txt", "w"); 
/*  esse arquivo é o retorno de fopen para escrever em um arquivo com nome "tal coisa"
    MODOS:
    w = escrita | r = leitura | a = append(add novas coisas no fim do arquivo)
    w+ = leitura e escrita | r+ = leitura e escrita | a+ = leitura e append, sem escrita
    caso o arquivo não existe, o "w", "w+", "a" e o "a+" criam ele, o "r" e o "r+" retornam NULL    */


    //fopen() retorna um ponteiro para char que aponta pro primeiro digito do arquivo
    fprintf(arquivo, "gabriel velho\n"); //escreveu no arquivo
    //fprintf(onde, "oque \n");
    // para apenas um caracter pode user fputc()
    // fputs() é quase a mesma coisa, mas nao aceita print formatado

    fclose(arquivo); //precisa fazer isso, pra poder fechar na ram o arquivo

    //exemplo 2 da aula
    FILE *fp;
    char ch;
    fp = fopen("alunos.txt", "r");
    while (1)
    {
        ch = fgetc(fp); //fgetc pega o caracter atual e troca o ponteiro pra proxima posicao
        //fgets(linha, 100, fp); 
        // fgets lê até 99 caracteres do arquivo, incluindo o caractere de nova linha, e armazena na matriz de caracteres linha

        if (ch == EOF) //EOF End Of File, caracter inserido no fim de cada arquivo, macro definida em stdio.h
            break;
        printf("%c", ch);
    }

    fclose(fp);

    //testando outra forma de fazer o exemplo da aula
    printarArquivo("alunos.txt");
    printf("%d",contarCharArquivo("alunos.txt"));

    copiarArquivo("alunos.txt", "alunos2.txt");

    // exemplo final do slide 33+
    Livro livroOriginal = {"toda a verdade", 67, 99.99}; //criei um livro
    FILE *arquivoLivro;
    arquivoLivro = fopen("livro.txt", "w");
    fprintf(arquivoLivro, "%s;%d;%.2f\n",livroOriginal.nome, livroOriginal.paginas, livroOriginal.preco); //joguei no arquivo
    fclose(arquivoLivro);

    arquivoLivro = fopen("livro.txt", "r");
    Livro livroCopia;
    FILE *arquivoLivroCopia;
    arquivoLivroCopia = fopen("livro2.txt", "w");
    fscanf(arquivoLivro, "%49[^;];%d;%f", &livroCopia.nome, &livroCopia.paginas, &livroCopia.preco); //fscanf é um scan que vem de file, basicamente
/*  %49[^;] le ate o proximo ';' (inclui espacos no nome e evita overflow limitando a 49 chars)
    os ';' no formato devem existir no arquivo, garantindo que os campos sejam separados corretamente   */

    fprintf(arquivoLivroCopia, "%s;%d;%.2f\n",livroCopia.nome,livroCopia.paginas,livroCopia.preco);
    fclose(arquivoLivro);
    fclose(arquivoLivroCopia);

    return 0;
}