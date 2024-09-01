# Exercícios da Aula 03 - Revisão de Funções

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto)                                            | RA: 398439413098     |
| ------------- | -------------------------------------------------------------------------------------------------------------------------------- | :------------------: |
| Curso:        | Ciência da Computação                                                                                                            | Noturno              |
| Professora:   | Noiza Waltrick Trindade                                                                                                          |                      |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                                                                        | 2024.2 - Turma A     |
| Universidade: | Anhanguera-Uniderp - Matriz                                                                                                      | Campo Grande, MS     |
| Atividade     | [Exercícios da Aula 03 - Revisão de Funções](../Docs/EDA%20-%20Encontro%2003%20-%20Revis%C3%A3o%20sobre%20fun%C3%A7%C3%B5es.pdf) | Data: 20/08/2024     |

## Exercício 1

Sabendo que o programa principal lê um número, escreva uma função em C/C++ que mostre na tela a tabuada deste número digitado e retorne ao programa principal o valor da somatória das parcelas da tabuada.

### Resposta:

[ex01.cpp](./Src/ex01.cpp)
```cpp
#include <stdio.h>
#include <stdlib.h>

int tabuada(int n);

int main(int argc, char** argv) {
    int n;

    printf("> n = "); scanf("%d", &n);

    printf("< Somatório: %d\n\n", tabuada(n));

	return 0;
}

int tabuada(int n){

    int parcial, somatorio = 0;

    printf("\nTabuada do (%d):\n", n);
    for(int i = 1; i<=10; i++){

        parcial = n*i;
        somatorio +=parcial;  

        printf("< %d x %d = %d\n", n, i, parcial);
    }
    printf("\n");

    return somatorio;
}
```

## Exercício 2

Faça um programa que possua uma função que receba dois números a e b, em seguida, faça a troca destes dois números. Dica: a e b devem ser passados por referência e impressos fora da função.

### Resposta:

[ex02.cpp](./Src/ex02.cpp)
```cpp
#include <stdio.h>
#include <stdlib.h>

void troca(int* x1, int* x2);

int main(int argc, char** argv) {
    int x1, x2;
    
    printf("> x1 = "); scanf("%d", &x1);
    printf("> x2 = "); scanf("%d", &x2);

    troca(&x1, &x2);

    printf("< x1 = %d\n", x1);
    printf("< x2 = %d\n", x2);
	return 0;
}

void troca(int* x1, int* x2){
    int aux = *x1;
    *x1 = *x2;
    *x2 = aux;
}
```

## Exercício 3

Faça um programa que possua uma função que receba os valores a, b e c passados por valor, receba também dois valores x1 e x2 passados por referência. Em seguida, calcule e retorne as duas raízes da equação do segundo grau nas variáveis x1 e x2.

### Resposta:

[ex03.cpp](./Src/ex03.cpp)
```cpp
#include <stdio.h>
#include <math.h>

float raizes(float a, float b, float c, float *x1, float *x2);

int main(){
    float a, b, c, delta, x1, x2;

    printf("> a = "); scanf("%f", &a);
    printf("> b = "); scanf("%f", &b);
    printf("> c = "); scanf("%f", &c);
    
    delta = raizes(a, b, c, &x1, &x2);
    
    if(delta == 0){
        printf("\n< x = %.2f\n", x1);
    }else if(delta > 0){
        printf("\n< x = {%.2f, %.2f}\n", x1, x2);
    }else {
        printf("\n< x não tem solução real.\n");
    }
    printf("\n");
}

float raizes(float a, float b, float c, float *x1, float *x2){

    float delta = b*b - 4*a*c;
    if(delta < 0) return delta;

    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);

    return delta;
}
```
