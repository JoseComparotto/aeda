#include <stdio.h>

/**
 * 2. Escreva  um  programa  com  uma  função  recursiva  para  calcular  o 
 *    valor  de  uma base x elevada a um expoente y (positivo), sem usar
 *    operador de exponenciação.
 */

long potencia(int base, int expoente);

int main(){
    int x, y;

    printf("> x = "); scanf("%d", &x);
    printf("> y = "); scanf("%d", &y);

    if(y < 0) return 0; 

    printf("< x^y = %ld\n\n", potencia(x,y));

}

long potencia(int base, int expoente){
    
    if ( expoente == 0) return 1;
    
    return base * potencia(base, expoente -1);
}
