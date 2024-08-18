#include <stdio.h>
#include <stdlib.h>

/**
 * 1. Faça um programa que leia dois números inteiros, positivos, e determine
 * o produto deles, utilizando o seguinte método de multiplicação:
 * - Dividir, sucessivamente, o primeiro número por 2, até que se obtenha 1
 * como quociente;
 * - Paralelamente, dobrar, sucessivamente, o segundo número;
 * - Somar os números da segunda coluna que tenham um número ímpar na primeira
 * coluna. O total obtido é o produto procurado.
 */

int ex01(int a, int b){

    int auxA = a;
    int auxB = b;
    int soma = 0;

    printf("|  A  |  B  | Impar | Soma |\n");
    printf("| --- | --- | ----- | ---- |\n");

    do {
        printf("| %3d | %3d |", auxA, auxB);

        if(auxA % 2 == 1){
            printf("  Sim  ");
            soma += auxB;
        }else{
            printf("       ");
        }
        printf("| %4d |\n", soma);

        auxA = auxA / 2;
        auxB = auxB * 2;

    } while (auxA >= 1);

    return soma;
}

int main(int argc, char** argv) {
    int a, b, produto;
    
    printf("> a = "); scanf("%d", &b);
    printf("> b = "); scanf("%d", &a);

    produto = ex01(a,b);

    printf("< %d x %d = %d\n", a, b, produto);

	return 0;
}
