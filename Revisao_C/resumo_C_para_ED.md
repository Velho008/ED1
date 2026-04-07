# 📘 Resumo de C para Estrutura de Dados
> Guia de referência rápida para quem já conhece Python ou Java

---

## Sumário
1. [Estrutura básica de um programa](#1-estrutura-básica-de-um-programa)
2. [Compilação e execução](#2-compilação-e-execução)
3. [Tipos de dados e variáveis](#3-tipos-de-dados-e-variáveis)
4. [Operadores](#4-operadores)
5. [Entrada e saída (printf / scanf)](#5-entrada-e-saída-printf--scanf)
6. [Controle de fluxo](#6-controle-de-fluxo)
7. [Funções](#7-funções)
8. [Arrays (vetores e matrizes)](#8-arrays-vetores-e-matrizes)
9. [Strings](#9-strings)
10. [Ponteiros ⚡](#10-ponteiros-)
11. [Alocação dinâmica de memória](#11-alocação-dinâmica-de-memória)
12. [Structs](#12-structs)
13. [Typedef](#13-typedef)
14. [Arquivos](#14-arquivos)
15. [Pré-processador e headers](#15-pré-processador-e-headers)
16. [Erros comuns e dicas](#16-erros-comuns-e-dicas)
17. [Comparação: C vs Python vs Java](#17-comparação-c-vs-python-vs-java)

---

## 1. Estrutura básica de um programa

```c
#include <stdio.h>   // biblioteca padrão de I/O (equivalente a import)

int main() {         // ponto de entrada do programa (obrigatório)
    printf("Olá, mundo!\n");
    return 0;        // 0 = sucesso; qualquer outro valor = erro
}
```

> **Diferença-chave:** Em C não existe coleta de lixo. Você é responsável pela memória.

---

## 2. Compilação e execução

```bash
# Compilar
gcc programa.c -o programa

# Compilar com avisos úteis (recomendado sempre!)
gcc -Wall -Wextra programa.c -o programa

# Executar
./programa
```

**Fluxo:** código-fonte `.c` → compilador (gcc) → executável binário

---

## 3. Tipos de dados e variáveis

### Tipos primitivos

| Tipo       | Tamanho típico | Exemplo de valor | Formato printf |
|------------|----------------|------------------|----------------|
| `int`      | 4 bytes        | `42`, `-7`       | `%d`           |
| `float`    | 4 bytes        | `3.14f`          | `%f`           |
| `double`   | 8 bytes        | `3.14159`        | `%lf`          |
| `char`     | 1 byte         | `'A'`, `65`      | `%c`           |
| `long`     | 4 ou 8 bytes   | `1000000L`       | `%ld`          |
| `long long`| 8 bytes        | `1LL`            | `%lld`         |

> Não existe `boolean` nativo em C puro. Use `int` (0 = falso, qualquer outro = verdadeiro), ou inclua `<stdbool.h>` para ter `bool`, `true` e `false`.

### Declaração de variáveis

```c
int idade;           // declaração (valor indefinido — CUIDADO!)
int idade = 20;      // declaração + inicialização
float altura = 1.75f;
char letra = 'A';
int x, y, z;         // múltiplas na mesma linha

const int MAX = 100; // constante (equivalente ao final do Java)
```

> ⚠️ Em C, variáveis locais não inicializadas contêm "lixo de memória".

### Modificadores

```c
unsigned int positivo = 300;  // só valores >= 0 (dobra o limite positivo)
short int pequeno = 10;       // geralmente 2 bytes
long double grande = 1.234L;
```

---

## 4. Operadores

### Aritméticos
```c
int a = 10, b = 3;
a + b   // 13
a - b   // 7
a * b   // 30
a / b   // 3  (divisão inteira!)
a % b   // 1  (módulo/resto)
```

> Para divisão real: `(float)a / b` — casting explícito

### Relacionais e lógicos
```c
a == b   // igual
a != b   // diferente
a > b    // maior
a >= b   // maior ou igual
a < b    // menor
a <= b   // menor ou igual

a > 0 && b > 0   // AND lógico
a > 0 || b > 0   // OR lógico
!(a > 0)         // NOT lógico
```

### Incremento / Decremento
```c
i++;   // pós-incremento (usa o valor, depois incrementa)
++i;   // pré-incremento (incrementa, depois usa o valor)
i--;
--i;
```

### Atribuição composta
```c
x += 5;   // x = x + 5
x -= 2;   // x = x - 2
x *= 3;
x /= 2;
x %= 4;
```

### Operador ternário
```c
int max = (a > b) ? a : b;   // equivale ao "a if a > b else b" do Python
```

---

## 5. Entrada e saída (printf / scanf)

### printf — saída formatada

```c
int n = 42;
float f = 3.14f;
char c = 'Z';

printf("Inteiro: %d\n", n);
printf("Float: %.2f\n", f);      // 2 casas decimais
printf("Char: %c\n", c);
printf("String: %s\n", "texto");
printf("Hex: %x\n", n);          // hexadecimal
printf("%d e %d\n", n, n*2);     // múltiplos valores
```

**Sequências de escape comuns:**
| Escape | Significado |
|--------|-------------|
| `\n`   | nova linha  |
| `\t`   | tab         |
| `\\`   | barra invertida |
| `\"`   | aspas duplas |

### scanf — entrada formatada

```c
int idade;
scanf("%d", &idade);   // o & é OBRIGATÓRIO (passa o endereço da variável)

float altura;
scanf("%f", &altura);

char nome[50];
scanf("%s", nome);     // strings NÃO usam & (arrays já são ponteiros)
// Atenção: %s para no primeiro espaço! Para ler linha inteira:
fgets(nome, 50, stdin);
```

> ⚠️ Esquecer o `&` no `scanf` é um dos erros mais comuns em C!

---

## 6. Controle de fluxo

### if / else if / else

```c
int x = 10;

if (x > 0) {
    printf("positivo\n");
} else if (x < 0) {
    printf("negativo\n");
} else {
    printf("zero\n");
}
```

### switch

```c
int opcao = 2;

switch (opcao) {
    case 1:
        printf("um\n");
        break;        // break é obrigatório! sem ele, cai no próximo case
    case 2:
        printf("dois\n");
        break;
    default:
        printf("outro\n");
}
```

### while

```c
int i = 0;
while (i < 5) {
    printf("%d ", i);
    i++;
}
```

### do-while (executa ao menos uma vez)

```c
int i = 0;
do {
    printf("%d ", i);
    i++;
} while (i < 5);
```

### for

```c
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}
// Atenção: em C89/C90 não é permitido declarar variável dentro do for.
// Use gcc com -std=c99 ou superior para garantir esse recurso.
```

### break e continue

```c
for (int i = 0; i < 10; i++) {
    if (i == 3) continue;  // pula o 3
    if (i == 7) break;     // para no 7
    printf("%d ", i);
}
// Saída: 0 1 2 4 5 6
```

---

## 7. Funções

```c
// Declaração (protótipo) — obrigatório se a função vem depois do main
int soma(int a, int b);

// Definição
int soma(int a, int b) {
    return a + b;
}

// Função sem retorno
void imprimir(int x) {
    printf("Valor: %d\n", x);
}

int main() {
    int resultado = soma(3, 4);   // chamada
    imprimir(resultado);
    return 0;
}
```

> **C passa argumentos por valor!** A função recebe uma *cópia*. Para modificar a variável original, use ponteiros (ver seção 10).

```c
// Passagem por referência (com ponteiro)
void dobrar(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 5;
    dobrar(&x);
    printf("%d\n", x);  // imprime 10
    return 0;
}
```

---

## 8. Arrays (vetores e matrizes)

### Vetor

```c
int v[5];                    // declara array de 5 inteiros
int v[5] = {10, 20, 30, 40, 50};   // declara e inicializa
int v[] = {1, 2, 3};         // tamanho inferido = 3

v[0] = 99;                   // acessa/modifica elemento (índice começa em 0)
printf("%d\n", v[2]);        // acessa elemento no índice 2
```

> ⚠️ C **não verifica** limites de array. Acessar `v[10]` em um array de 5 é comportamento indefinido (causa bugs difíceis de rastrear).

### Percorrendo com for

```c
int v[] = {5, 3, 8, 1, 9};
int tamanho = 5;

for (int i = 0; i < tamanho; i++) {
    printf("%d ", v[i]);
}
```

### Passando array para função

```c
// Arrays são sempre passados como ponteiro — a função modifica o original!
void zerar(int arr[], int n) {   // equivalente a: void zerar(int *arr, int n)
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    zerar(v, 5);
    // v agora é {0, 0, 0, 0, 0}
    return 0;
}
```

### Matriz (array bidimensional)

```c
int mat[3][4];                       // 3 linhas, 4 colunas
int mat[2][3] = {{1,2,3},{4,5,6}};  // inicialização

mat[1][2] = 10;                      // acessa linha 1, coluna 2

// Percorrendo matriz
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
```

---

## 9. Strings

Em C, strings são **arrays de `char` terminados com `\0`** (caractere nulo).

```c
char nome[20] = "Maria";
// Internamente: ['M','a','r','i','a','\0', ...]

char nome[] = "Maria";    // tamanho automático = 6 (5 letras + '\0')
```

### Funções de string (`#include <string.h>`)

```c
#include <string.h>

char s1[50] = "Hello";
char s2[] = "World";

strlen(s1);           // comprimento da string (sem contar o '\0') → 5
strcpy(s1, s2);       // copia s2 em s1 (CUIDADO com tamanho!)
strncpy(s1, s2, 49);  // cópia segura (máximo de 49 caracteres)
strcat(s1, s2);       // concatena s2 ao final de s1
strncat(s1, s2, 10);  // concatenação segura
strcmp(s1, s2);       // compara: 0 se iguais, <0 ou >0 caso contrário
```

> ⚠️ **Nunca use `==` para comparar strings!** Use `strcmp`.

```c
// ERRADO
if (s1 == s2) { ... }

// CORRETO
if (strcmp(s1, s2) == 0) { ... }
```

---

## 10. Ponteiros ⚡

Ponteiro é uma variável que armazena um **endereço de memória**.

```c
int x = 10;
int *p;         // declara um ponteiro para int
p = &x;         // p recebe o endereço de x

printf("%d\n", x);    // valor de x: 10
printf("%p\n", p);    // endereço de x (ex: 0x7ffd...)
printf("%d\n", *p);   // valor no endereço apontado: 10  (derreferência)

*p = 99;         // modifica x através do ponteiro
printf("%d\n", x);   // 99
```

### Operadores de ponteiro

| Operador | Nome           | Uso                              |
|----------|----------------|----------------------------------|
| `&`      | "endereço de"  | obtém o endereço de uma variável |
| `*`      | "valor em"     | acessa o valor no endereço       |

### Ponteiro e array

```c
int v[] = {10, 20, 30};
int *p = v;       // p aponta para o início do array (v já é um endereço)

printf("%d\n", *p);      // 10
printf("%d\n", *(p+1));  // 20 (aritmética de ponteiros)
printf("%d\n", p[2]);    // 30 (notação de array funciona igual)
```

### Ponteiro para ponteiro

```c
int x = 5;
int *p = &x;
int **pp = &p;   // ponteiro para ponteiro

printf("%d\n", **pp);   // 5
```

### Ponteiro nulo

```c
int *p = NULL;   // ponteiro que não aponta para nada (seguro)

if (p != NULL) {
    printf("%d\n", *p);
}
```

---

## 11. Alocação dinâmica de memória

Use `#include <stdlib.h>`.

### malloc — aloca memória sem inicializar

```c
int *v = (int *) malloc(5 * sizeof(int));   // aloca espaço para 5 inteiros

if (v == NULL) {
    printf("Erro: sem memória!\n");
    return 1;
}

v[0] = 10;
v[1] = 20;
// ...

free(v);    // OBRIGATÓRIO liberar a memória quando não precisar mais!
v = NULL;   // boa prática: evita ponteiro solto
```

### calloc — aloca e inicializa com zero

```c
int *v = (int *) calloc(5, sizeof(int));   // 5 elementos, todos = 0
```

### realloc — redimensiona memória alocada

```c
v = (int *) realloc(v, 10 * sizeof(int));  // agora tem espaço para 10
```

### sizeof

```c
sizeof(int)       // 4 (geralmente)
sizeof(double)    // 8
sizeof(v)         // tamanho do array estático em bytes
```

> ⚠️ Regra de ouro: cada `malloc`/`calloc` deve ter um `free` correspondente. Esquecer causa **vazamento de memória (memory leak)**.

---

## 12. Structs

Structs agrupam variáveis de tipos diferentes (parecido com classes sem métodos).

```c
struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};

// Criando e usando
struct Aluno a1;
a1.matricula = 12345;
a1.nota = 8.5f;
strcpy(a1.nome, "Ana");

// Inicialização direta
struct Aluno a2 = {"Carlos", 99001, 7.0f};

printf("Nome: %s, Nota: %.1f\n", a2.nome, a2.nota);
```

### Struct com ponteiro (operador ->)

```c
struct Aluno *p = &a1;

p->nota = 9.0f;               // equivale a: (*p).nota = 9.0f
printf("%s\n", p->nome);
```

### Struct com alocação dinâmica

```c
struct Aluno *p = (struct Aluno *) malloc(sizeof(struct Aluno));
p->matricula = 55555;
strcpy(p->nome, "Pedro");
free(p);
```

---

## 13. Typedef

Cria um apelido (alias) para um tipo, evitando repetir `struct`.

```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Agora pode usar "Pessoa" diretamente
Pessoa p1 = {"Julia", 21};
Pessoa *ptr = &p1;
printf("%s tem %d anos\n", ptr->nome, ptr->idade);
```

### Typedef com ponteiro (comum em ED)

```c
typedef struct No {
    int dado;
    struct No *prox;   // ponteiro para o próprio tipo (lista ligada!)
} No;
```

---

## 14. Arquivos

```c
#include <stdio.h>

// Escrita
FILE *arq = fopen("dados.txt", "w");   // "w"=escrita, "r"=leitura, "a"=append
if (arq == NULL) {
    printf("Erro ao abrir!\n");
    return 1;
}
fprintf(arq, "Linha 1\n");
fprintf(arq, "Valor: %d\n", 42);
fclose(arq);   // sempre fechar!

// Leitura
FILE *arq = fopen("dados.txt", "r");
char linha[100];
while (fgets(linha, 100, arq) != NULL) {
    printf("%s", linha);
}
fclose(arq);

// Leitura formatada
int n;
fscanf(arq, "%d", &n);
```

---

## 15. Pré-processador e headers

```c
#include <stdio.h>     // biblioteca do sistema (entre < >)
#include "minha.h"     // arquivo local (entre " ")

#define PI 3.14159     // constante de pré-processador (sem tipo, sem ;)
#define MAX(a,b) ((a)>(b)?(a):(b))   // macro com parâmetros

// Compilação condicional (evita incluir o mesmo header duas vezes)
#ifndef MINHA_H
#define MINHA_H
// ... conteúdo do header ...
#endif
```

### Principais bibliotecas

| Header         | O que oferece                                    |
|----------------|--------------------------------------------------|
| `<stdio.h>`    | printf, scanf, fopen, fclose, fgets...           |
| `<stdlib.h>`   | malloc, free, exit, atoi, rand...                |
| `<string.h>`   | strlen, strcpy, strcmp, strcat...                |
| `<math.h>`     | sqrt, pow, abs, floor, ceil... (compilar com -lm)|
| `<stdbool.h>`  | bool, true, false                                |
| `<limits.h>`   | INT_MAX, INT_MIN...                              |

---

## 16. Erros comuns e dicas

### 🔴 Erro clássico: esquecer `&` no scanf
```c
// ERRADO
scanf("%d", x);

// CERTO
scanf("%d", &x);
```

### 🔴 Comparar strings com ==
```c
// ERRADO
if (s1 == s2)

// CERTO
if (strcmp(s1, s2) == 0)
```

### 🔴 Usar memória após free
```c
free(p);
*p = 10;    // UNDEFINED BEHAVIOR! Use p = NULL logo após free.
```

### 🔴 Buffer overflow em string
```c
char s[5];
strcpy(s, "textomuuuuito_grande");   // PERIGOSO! Use strncpy.
```

### 🔴 Esquecer o break no switch
```c
switch (x) {
    case 1:
        printf("um");
        // sem break — vai cair no case 2 também!
    case 2:
        printf("dois");
        break;
}
```

### 🔴 Divisão inteira acidental
```c
float media = (nota1 + nota2) / 2;    // se nota1 e nota2 forem int, o resultado é inteiro!
float media = (nota1 + nota2) / 2.0;  // CERTO
```

### 🟡 Boas práticas
- Sempre inicialize variáveis antes de usar
- Sempre verifique se `malloc` retornou `NULL`
- Sempre dê `free` no que você alocou
- Compile com `-Wall -Wextra` para ver avisos úteis
- Use `valgrind ./programa` para detectar vazamentos de memória

---

## 17. Comparação: C vs Python vs Java

| Conceito             | Python                    | Java                       | C                                  |
|----------------------|---------------------------|----------------------------|------------------------------------|
| Tipo de variável     | dinâmico (implícito)      | estático (explícito)       | estático (explícito)               |
| Gerência de memória  | automática (GC)           | automática (GC)            | **manual** (malloc/free)           |
| Strings              | objeto nativo             | objeto String              | array de char com `\0`             |
| Booleano             | `True` / `False`          | `boolean` / `true`/`false` | `int` ou `<stdbool.h>`             |
| Herança/classes      | sim                       | sim                        | não (apenas structs)               |
| Array fora do limite | erro em tempo de execução | `ArrayIndexOutOfBounds`    | comportamento indefinido (silencioso!) |
| Ponteiros explícitos | não                       | não (referências ocultas)  | **sim** (ponto central da linguagem) |
| Compilação           | interpretado              | compilado para bytecode    | compilado para binário nativo      |
| Null/None/null       | `None`                    | `null`                     | `NULL` (é 0 numericamente)         |

---

> **Dica final:** Em Estrutura de Dados, ponteiros e structs são o coração de tudo. Liste ligada, pilha, fila, árvore — tudo usa `struct` + ponteiros. Domine a seção 10 e 12 e o resto flui naturalmente! 🚀
