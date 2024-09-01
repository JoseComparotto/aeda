#include <stdio.h>
#include <stdlib.h>

/**
 * 1. Sabendo que o programa principal lê um número, escreva uma função em
 *    C/C++ que mostre na tela a tabuada deste número digitado e retorne ao
 *    programa principal o valor da somatória das parcelas da tabuada.
 */

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