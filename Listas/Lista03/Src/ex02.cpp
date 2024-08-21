#include <stdio.h>
#include <stdlib.h>

/**
 * 2. Faça um programa que possua uma função que receba dois números a e b, em
 *    seguida, faça a troca destes dois números. Dica: a e b devem ser passados
 *    por referência e impressos fora da função.
 */

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
