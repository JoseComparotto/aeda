#include <stdio.h>

/**
 * 1. Implemente uma função recursiva para computar o valor de 2n. O programa
 *    deve solicitar o valor de n, uma sequência indeterminada de vezes,
 *    mostrando o valor da potência a cada execução. O programa termina quando
 *    a potência informada for negativa.
 */

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
