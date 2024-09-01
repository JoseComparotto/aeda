# Lista 03 - Recursividade

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto) | RA: 398439413098 |
| ------------- | ------------------------------------------------------------------------------------- | :--------------: |
| Curso:        | Ciência da Computação                                                                 | Noturno          |
| Professora:   | Noiza Waltrick Trindade                                                               |                  |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                             | 2024.2 - Turma A |
| Universidade: | Anhanguera-Uniderp - Matriz                                                           | Campo Grande, MS |
| Atividade     | [Lista 03 - Recursividade](./Docs/EDA%20-%20Lista03.pdf)                              | Data: 27/08/2024 |

## Exercício 1

Implemente uma função recursiva para computar o valor de `2^n`. O programa deve
solicitar o valor de n, uma sequência indeterminada de vezes, mostrando o valor
da potência a cada execução. O programa termina quando a potência informada for
negativa.

### Resposta

[ex01.cpp](./Src/ex01.cpp)

```cpp
#include <stdio.h>

long exp2(int n);

int main(){
    int n;

    while(true){
        printf("> n = "); scanf("%d", &n);

        if(n < 0) break;
        printf("< 2^%d = %ld\n\n", n, exp2(n));
    }
}

long exp2(int n){
    long exp;

    if (n == 0) return 1;

    return 2 * exp2(n-1);
}
```

## Exercício 2

Escreva  um  programa  com  uma  função  recursiva  para  calcular  o valor de
uma base `x` elevada a um expoente `y` (positivo), sem usar operador de
exponenciação.

### Resposta

[ex02.cpp](./Src/ex02.cpp)

```cpp
#include <stdio.h>

long potencia(int base, int expoente);

int main(){
    int x, y;

    printf("> x = "); scanf("%d", &x);
    printf("> y = "); scanf("%d", &y);

    if(y < 0) return 0; 

    printf("< x^y = %ld\n\n", potencia(x,y));

}

long potencia(int base, int expoente){
    
    if ( expoente == 0) return 1;
    
    return base * potencia(base, expoente -1);
}
```

## Exercício 3

Altere o programa anterior para resolver problemas com expoente negativo.

### Resposta

[ex03.cpp](./Src/ex03.cpp)

```cpp
#include <stdio.h>

long double potencia(int base, int expoente);

int main(){
    int x, y;

    printf("> x = "); scanf("%d", &x);
    printf("> y = "); scanf("%d", &y);

    printf("< x^y = %Lf\n\n", potencia(x,y));

}

long double potencia(int base, int expoente){
    
    if ( expoente == 0 ) return 1.0;
    if ( expoente < 0 ) return 1.0 / potencia(base, -expoente);
    
    return base * potencia(base, expoente - 1);
}
```

## Exercício 4

O que faz a função abaixo?
 
```c
int f(int a, int b){
    if(b==0)
        return a;
    else 
    return f(b, a%b);
}
```

Prove que funciona para um caso real.

### Resposta

A função calcula o MDC (Máximo Divisor Comum) entre dois números inteiros
usando o algoritmo de Euclides.

#### Exemplo: MDC(98, 42)

1. f(98, 42) -> f(42, 98 % 42) = f(42, 14)
2. f(42, 14) -> f(14, 42 % 14) = f(14, 0)
3. f(14, 0) -> retorna 14 (critério de parada)

#### Critério de Parada:

Quando `b == 0`, a função retorna `a` porque `a` é o maior divisor comum de 
ambos os números nesse ponto. Se `b` chegou a 0, significa que `a` é um 
divisor que divide ambos os números sem deixar resto. Como a função tem um
comportamento decrescente, o primeiro divisor comum encontrado é o maior.
 
#### Lógica da Recursão:

A função é chamada recursivamente com os valores trocados e `a % b` até que 
`b` seja 0. O valor de `a` neste ponto é o MDC.

#### Conclusão:

A função encontra o maior número que divide ambos os valores com resto 0.
