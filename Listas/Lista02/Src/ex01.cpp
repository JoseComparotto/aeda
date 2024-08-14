#include <stdio.h>

/**
 * 1) Explique o resultado de n e pn após a execução do programa abaixo:
 */

int main(){
    int n = 100;
    int *pn;
    printf("n = %d\n", n);
    pn = &n;
    *pn = 200;
    printf("n = %d\n", n);
    n = 2*(*pn);
    printf("*pn = %d\n", *pn);
    printf("n = %d\n", n);

    return 0;
}

/** 
 * Resposta:
 *  Tanto o identificador n, quanto o ponteiro *pn, identificam o mesmo
 *  endereço de memória. Logo, se comportam como se fossem a mesma variável.
 */