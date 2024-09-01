#include <stdio.h>

/**
 * 4. O que faz a função abaixo?
 * 
 * ```c
 * int f(int a, int b){
 *     if(b==0)
 *         return a;
 *     else 
 *         return f(b, a%b);
 * }
 * ```
 * 
 * Prove que funciona para um caso real.
 */ 

int f(int a, int b);

int main(){
    int a, b;

    printf("> a = "); scanf("%d", &a);
    printf("> b = "); scanf("%d", &b);

    printf("< f(a, b) = %d\n\n", f(a, b));

}

int f(int a, int b){
    if(b==0)
        return a;
    else 
        return f(b, a%b);
}

/**
 * Resposta:
 *  A função calcula o MDC (Máximo Divisor Comum) entre dois números inteiros
 *  usando o algoritmo de Euclides.
 * 
 * Exemplo: MDC(98, 42)
 *  1. f(98, 42) -> f(42, 98 % 42) = f(42, 14)
 *  2. f(42, 14) -> f(14, 42 % 14) = f(14, 0)
 *  3. f(14, 0) -> retorna 14 (critério de parada)
 * 
 * Critério de Parada:
 *  Quando `b == 0`, a função retorna `a` porque `a` é o maior divisor comum de
 *  ambos os números nesse ponto. Se `b` chegou a 0, significa que `a` é um
 *  divisor que divide ambos os números sem deixar resto. Como a função tem um
 *  comportamento decrescente, o primeiro divisor comum encontrado é o maior.
 *  
 * Lógica da Recursão:
 *  A função é chamada recursivamente com os valores trocados e `a % b` até que
 *  `b` seja 0. O valor de `a` neste ponto é o MDC.
 * 
 * Conclusão:
 *  A função encontra o maior número que divide ambos os valores com resto 0.
 */
