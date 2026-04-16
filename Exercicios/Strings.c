#include <stdio.h>




int main()
{



    return 0;
}

/*
Perfeito — agora começa a parte onde C fica mais “interessante” (e perigosa 😄).
Aqui vão **6 exercícios de strings (`char[]`)**, em ordem de dificuldade:

---

## **1. Ler e imprimir uma string**

Crie um programa que:

* leia uma string (sem espaços)
* imprima ela

👉 Use:

```c
scanf("%s", str);
```

---

## **2. Tamanho da string (sem `strlen`)**

Crie uma função que conte o tamanho da string manualmente.

* Protótipo:

```c
int tamanhoString(char str[]);
```

👉 Dica:

* percorra até `'\0'`

---

## **3. Contar vogais**

Crie uma função que conte quantas vogais existem na string.

* Considere: `a, e, i, o, u` (maiúsculas também)

---

## **4. Inverter string**

Crie uma função que inverta uma string.

Exemplo:

```
Entrada: "casa"
Saída: "asac"
```

👉 Pode:

* inverter na própria string
  ou
* criar outra

---

## **5. Verificar palíndromo**

Crie uma função que verifique se a string é um palíndromo.

Exemplo:

```
"arara" → sim  
"casa" → não  
```

👉 Compare início com fim.

---

## **6. Remover espaços**

Crie uma função que remova todos os espaços de uma string.

Exemplo:

```
"ola mundo legal" → "olamundolegal"
```

👉 Dica:

* use dois índices (um lendo, outro escrevendo)

---

## 🔥 Desafio (nível mais alto)

### **7. Contar palavras**

Crie uma função que conte quantas palavras existem na string.

Exemplo:

```
"ola mundo legal" → 3 palavras
```

👉 Dica:

* palavra = sequência entre espaços

---

## ⚠️ Dicas MUITO importantes em strings

* String em C termina com:

```c
'\0'
```

* Cuidado com:

```c
scanf("%s", str);
```

👉 para em espaço

Se quiser ler com espaço depois, a gente vê:

```c
fgets()
```

---

## 🚀 Estratégia boa

Faz nessa ordem:
1 → 2 → 3 → 4 → 5

(6 e 7 são mais chatinhos)

---

Manda o primeiro que eu corrijo igual fiz com vetores 👍
*/