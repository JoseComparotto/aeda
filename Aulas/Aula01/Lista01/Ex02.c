#include <stdio.h>
#include <stdlib.h>

/**
 * 2. O fatorial de um número inteiro positivo n é definido como sendo o produto dos
 * inteiros de 1 a n. O fatorial de zero é definido como 1. Faça um programa que
 * contenha uma função que receba um inteiro como parâmetro e retorne seu fatorial.
 */

int main(int argc, char** argv) {
    int n, resultado;
    
    printf("> ");
    scanf("%d", &n);

    resultado = fatorial(n);

    printf("< %d\n", resultado);
	return 0;
}

int fatorial(int n){

    if (n == 0) return 1;
    return n * fatorial(n-1);

}