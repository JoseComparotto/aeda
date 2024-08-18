#include <assert.h>
#include <stdio.h>

/**
 * 2. O fatorial de um número inteiro positivo n é definido como sendo o produto dos
 *    inteiros de 1 a n. O fatorial de zero é definido como 1. Faça um programa que
 *    contenha uma função que receba um inteiro como parâmetro e retorne seu fatorial.
 */

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