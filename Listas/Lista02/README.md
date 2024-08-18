# Lista 02

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto) | RA: 398439413098     |
| ------------- | ------------------------------------------------------------------------------------- | :------------------: |
| Curso:        | Ciência da Computação                                                                 | Noturno              |
| Professora:   | Noiza Waltrick Trindade                                                               |                      |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                             | 2024.2 - Turma A |
| Universidade: | Anhanguera-Uniderp - Matriz                                                           | Campo Grande, MS     |
| Atividade     | [Lista 02 - Ponteiros](./Docs/EDA%20-%20Lista02.pdf)                                 | Data: 13/08/2024               |

## Exercício 1

Explique o resultado de n e pn após a execução do programa abaixo:

[ex01.cpp](./Src/ex01.cpp)
```cpp
#include <stdio.h>
int main(){
    int n = 100;
    int *pn;
    printf("n = %d\n", n);
    pn = &n;
    *pn = 200;
    printf("n = %d\n", n);
    n = 2*(*pn);
    printf("*pn = %d\n", *pn);
    printf("n = %d\n", n);

    return 0;
}
```
### Resposta:

Tanto o identificador `n`, quanto o ponteiro `*pn`, identificam o mesmo endereço de memória. Logo, se comportam como se fossem a mesma variável.

## Exercício 2

Qual a falha no uso de ponteiros do programa abaixo?

[ex02.cpp](./Src/ex02.cpp)
```cpp
#include <stdio.h>
int main(){
    float x,y;
    int *p;
    x = 100.25;
    p = &x;
    y = *p;
    printf("x = %f e y = %f", x, y);
    return 0;
}
```
### Resposta:

O ponteiro `p` é do tipo `int *`, ou seja, identifica um endereço de memória que armazena valores do tipo `int`. Logo, a atribuição `p = &x;` é inválida pois tenta definir o endereço aramazenado em `p` para o endereço de uma variável do tipo `float`, quando era esperado um endereço de uma variável do tipo `int`.

## Exercício 3

Inicialize um vetor de inteiros de 100 elementos aleatoriamente e percorra o vetor listando os elementos. Para percorrer o vetor use dois ponteiros: um começando do início do vetor e outro do final até se encontrarem no meio. 

### Resposta:

[ex03.cpp](./Src/ex03.cpp)
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

// Função para preencher o vetor com valores aleatórios
void fillRand(int* array, int len) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = 0; i < len; i++) {
        array[i] = rand() % len; // Preenche com valores aleatórios
    }
}

// Função para imprimir os elementos do vetor
void print(int* array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02d ", array[i]); // Imprime cada elemento com dois dígitos
    }
    printf("\n");
}

// Função para percorrer o vetor usando dois ponteiros
void ex03(int* array, int len) {
    int *p1 = array;              // Ponteiro inicial no começo do vetor
    int *p2 = array + len - 1;    // Ponteiro inicial no final do vetor

    printf("| P1 | P2 |\n");
    printf("| -- | -- |\n");

    while (p1 <= p2) { // Usa <= para garantir que p1 e p2 possam se encontrar
        printf("| %02d | %02d |\n", *p1, *p2);
        p1++; 
        p2--;
    }
}

int main() {
    int lista[TAMANHO];

    fillRand(lista, TAMANHO); // Preenche o vetor com valores aleatórios

    printf("Lista: ");
    print(lista, TAMANHO); // Imprime o vetor

    ex03(lista, TAMANHO); // Percorre o vetor com dois ponteiros

    return 0;
}
```

## Exercício 4

Coloque em ordem o programa e explique.

```cpp
int main () {
    int x, *p;
    ( ) *p = x + 20;
    ( ) p = &x;
    ( ) x = 10;
}
```

### Resposta:

[ex04.cpp](./Src/ex04.cpp)
```cpp
int main () {
    int x, *p;      // Declara as variáveis
    x = 10;         // Inicializa x com o valor 10
    p = &x;         // Inicializa p com o endereço de x
    *p = x + 20;    // Equivalente a: (x = x + 20) ou (*p = *p + 20).
}
```

### Explicação

A ordem das instruções `x = 10;` e `p = &x;` poderia ser invertida sem causar problemas, pois `p` apenas precisa apontar para `x` antes de `*p` ser utilizado. No entanto, `*p = x + 20;` deve vir após essas duas instruções para garantir que `p` aponte para um endereço válido (o de `x`) e que `x` tenha um valor definido. Se `*p` fosse utilizado antes de `p` apontar para `x`, o programa poderia tentar acessar uma área de memória não inicializada, levando a um comportamento indefinido.

## Exercício 5

Em relação ao programa acima a linha abaixo está certa ou errada? Explique.

```cpp
p = x;
```

### Resposta:

Errada. A chamada do ponteiro `p` (sem o `*`) apenas atribui ou recupera endereços de memória. A instrução tenta atribuir o valor de `x` (um valor `int`) diretamente ao ponteiro. O que não é válido e retornará um erro de compilação. 
