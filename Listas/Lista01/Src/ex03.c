#include <stdio.h>
#include <stdlib.h>

/**
 * 3. Faça um programa que possua uma função que receba dois valores x1 e x2
 *    passados por referência. Em seguida, troque os valores das variáveis na
 *    função e os imprima trocados no programa principal.
 */

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