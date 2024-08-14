# Lista 02

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto) | RA: 398439413098     |
| ------------- | ------------------------------------------------------------------------------------- | :------------------: |
| Curso:        | Ciência da Computação                                                                 | Noturno              |
| Professora:   | Noiza Waltrick Trindade                                                               |                      |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                             | 2024.2 - Turma A |
| Universidade: | Anhanguera-Uniderp - Matriz                                                           | Campo Grande, MS     |
| Atividade     | [Lista 02 - Ponteiros](./Docs/EDA%20-%20Lista02.pdf)                                 | Data: 13/08/2024               |

# Exercício 1

Explique o resultado de n e pn após a execução do programa abaixo:

```c
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
## Resposta:
    Tanto o identificador "n", quanto o ponteiro "*pn", identificam
    o mesmo endereço de memória. Logo, o comportamento esperado é que
    eles se comportem como se fossem a mesma variável.

# Exercício 2

Qual a falha no uso de ponteiros do programa abaixo?

```c
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
## Resposta:
    O ponteiro "p" é do tipo "int *", ou seja, identifica
    um endereço de memória que armazena valores do tipo "int".
    Logo, a atribuição "p = &x;" é inválida pois tenta definir
    o endereço que aramazenado em "p" para o endereço de uma
    variável do tipo "float", quando era eserado uma endereço
    de uma variável do tipo "int".

# Exercício 3

Inicialize um vetor de inteiros de 100 elementos aleatoriamente e percorra o vetor listando os elementos. Para percorrer o vetor use dois ponteiros: um começando do início do vetor e outro do final até se encontrarem no meio. 

## Resposta:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

int main(){

    int lista[TAMANHO];

    srand(time(NULL));

    printf("Lista: ");
    for(int i = 0; i < TAMANHO; i++){
        lista[i] = rand() % TAMANHO;
    }

    for(int i = 0; i < TAMANHO; i++){
        printf("%02d ", lista[i]);
    }
    printf("\n\n");

    int *p1 = (int*) &lista;
    int *p2 = p1 + TAMANHO - 1;

    printf("| P1 | P2 |\n");
    printf("| -- | -- |\n");

     while(p1 < p2) {
        printf("| %02d | %02d |\n", *p1, *p2);
        p1++; p2--;
    }
}
```
