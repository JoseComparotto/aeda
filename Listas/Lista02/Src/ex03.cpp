#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 3) Inicialize um vetor de inteiros de 100 elementos aleatoriamente e percorra o vetor 
 * listando os elementos. Para percorrer o vetor use dois ponteiros: um começando do 
 * início do vetor e outro do final até se encontrarem no meio. 
 */

#define TAMANHO 100

// Função para preencher o vetor com valores aleatórios
void fillRand(int* array, int len) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = 0; i < len; i++) {
        array[i] = rand() % len; // Preenche com valores aleatórios
    }
}

// Função para imprimir os elementos do vetor
void print(int* array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02d ", array[i]); // Imprime cada elemento com dois dígitos
    }
    printf("\n");
}

// Função para percorrer o vetor usando dois ponteiros
void ex03(int* array, int len) {
    int *p1 = array;              // Ponteiro inicial no começo do vetor
    int *p2 = array + len - 1;    // Ponteiro inicial no final do vetor

    printf("| P1 | P2 |\n");
    printf("| -- | -- |\n");

    while (p1 <= p2) { // Usa <= para garantir que p1 e p2 possam se encontrar
        printf("| %02d | %02d |\n", *p1, *p2);
        p1++; 
        p2--;
    }
}

int main() {
    int lista[TAMANHO];

    fillRand(lista, TAMANHO); // Preenche o vetor com valores aleatórios

    printf("Lista: ");
    print(lista, TAMANHO); // Imprime o vetor

    ex03(lista, TAMANHO); // Percorre o vetor com dois ponteiros

    return 0;
}
