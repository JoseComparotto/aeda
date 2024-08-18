# Lista 01

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto) | RA: 398439413098     |
| ------------- | ------------------------------------------------------------------------------------- | :------------------: |
| Curso:        | Ciência da Computação                                                                 | Noturno              |
| Professora:   | Noiza Waltrick Trindade                                                               |                      |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                             | 2024.2 - Turma A     |
| Universidade: | Anhanguera-Uniderp - Matriz                                                           | Campo Grande, MS     |
| Atividade     | [Lista 01](./Docs/EDA%20-%20Lista01.pdf)                                              | Data: 06/08/2024     |

## Exercício 1

Faça um programa que leia dois números inteiros, positivos, e determine
   o produto deles, utilizando o seguinte método de multiplicação:

   - Dividir, sucessivamente, o primeiro número por 2, até que se obtenha 1 como quociente;

   - Paralelamente, dobrar, sucessivamente, o segundo número;

   - Somar os números da segunda coluna que tenham um número ímpar na primeira coluna. O total obtido é o produto procurado.

### Resposta:

[ex01.c](./Src/ex01.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int ex01(int a, int b){

    assert(a > 0 && b > 0);  // Garante que 'a' e 'b' são positivos
    
    int auxA = a;
    int auxB = b;
    int soma = 0;

    printf("|  A  |  B  | Impar | Soma |\n");
    printf("| --- | --- | ----- | ---- |\n");

    do {
        printf("| %3d | %3d |", auxA, auxB);

        if(auxA % 2 == 1){
            printf("  Sim  ");
            soma += auxB;
        }else{
            printf("       ");
        }
        printf("| %4d |\n", soma);

        auxA = auxA / 2;
        auxB = auxB * 2;

    } while (auxA >= 1);

    return soma;
}

int main(int argc, char** argv) {
    int a, b, produto;
    
    printf("> a = "); scanf("%d", &a);
    printf("> b = "); scanf("%d", &b);

    produto = ex01(a,b);

    printf("< %d x %d = %d\n", a, b, produto);

	return 0;
}
```

## Exercício 2

O fatorial de um número inteiro positivo n é definido como sendo o produto dos inteiros de 1 a n. O fatorial de zero é definido como 1. Faça um programa que contenha uma função que receba um inteiro como parâmetro e retorne seu fatorial.

### Resposta:

[ex02.c](./Src/ex02.c)
```c
#include <assert.h>
#include <stdio.h>

int fatorial(int n) {
    int r = 1;

    assert(n >= 0);  // Garante que n é não-negativo
    
    for (int i = 2; i <= n; i++) {
        r *= i;
    }
    
    return r;
}

int main() {
    int n, resultado;

    printf("> n = ");
    scanf("%d", &n);

    resultado = fatorial(n);
    printf("< n! = %d\n", resultado);

    return 0;
}
```

## Exercício 3

Faça um programa que possua uma função que receba dois valores x1 e x2 passados por referência. Em seguida, troque os valores das variáveis na função e os imprima trocados no programa principal.

### Resposta:

[ex03.c](./Src/ex03.c)
```c
#include <stdio.h>
#include <stdlib.h>

void troca(int* x1, int* x2){
    int aux = *x1;
    *x1 = *x2;
    *x2 = aux;
}

int main(int argc, char** argv) {
    int x1, x2;
    
    printf("> x1 = "); scanf("%d", &x1);
    printf("> x2 = "); scanf("%d", &x2);

    troca(&x1, &x2);

    printf("< x1 = %d\n", x1);
    printf("< x2 = %d\n", x2);
	return 0;
}
```

## Exercício 4
 
4. Considerando a estrutura:

```c
struct Ponto {
    int x;
    int y;
 };
 ``` 
 para representar um ponto em uma grade 2D, implemente um programa que indique se um ponto p está localizado dentro ou fora de um retângulo. O retângulo é definido por seus vértices inferior esquerdo v1 e superior direito v2. Utilize uma função que deve imprimir caso o ponto esteja localizado dentro do retângulo ou não.

### Resposta:

[ex03.c](./Src/ex04.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    unsigned int width;
    unsigned int height;
} Rect;

Rect rectFrom(Point a, Point b) {
    Rect r;

    r.x = a.x < b.x ? a.x : b.x;
    r.y = a.y < b.y ? a.y : b.y;

    r.width = abs(a.x - b.x);
    r.height = abs(a.y - b.y);
    
    return r;
}

int isPointInRect(Point p, Rect r) {
    return (p.x >= r.x && p.x <= r.x + r.width &&
            p.y >= r.y && p.y <= r.y + r.height);
}

int main(int argc, char** argv) {
    Point v1, v2, p;
    Rect r;
    
    printf("> v1.x = "); scanf("%d", &v1.x);
    printf("> v1.y = "); scanf("%d", &v1.y);
    
    printf("> v2.x = "); scanf("%d", &v2.x);
    printf("> v2.y = "); scanf("%d", &v2.y);

    printf("> p.x = "); scanf("%d", &p.x);
    printf("> p.y = "); scanf("%d", &p.y);

    r = rectFrom(v1, v2);

    if(isPointInRect(p, r)) {
        printf("< Está dentro do retângulo.\n");
    } else {
        printf("< Não está dentro do retângulo.\n");
    }

    return 0;
}

```