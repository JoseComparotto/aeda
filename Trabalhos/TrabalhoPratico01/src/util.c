#include <stdio.h>
#include <math.h>
#include "util.h"

int numeroDigitos(int numero) {

    if (numero == 0) 
        return 1;
    
    int negativo = numero < 0;
    if (negativo) 
        numero = -numero;

    // Arredonda para cima o valor de log10(numero) e soma 1.
    return (int)floor(log10(numero)) + 1 + negativo;
}

int maior(int a, int b){
    if(a > b) return a;
    else return b;
}