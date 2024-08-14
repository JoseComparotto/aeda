#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 3) Inicialize um vetor de inteiros de 100 elementos aleatoriamente e percorra o vetor 
 * listando os elementos. Para percorrer o vetor use dois ponteiros: um começando do 
 * início do vetor e outro do final até se encontrarem no meio. 
 */

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
