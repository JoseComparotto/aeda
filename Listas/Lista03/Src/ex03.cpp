#include <stdio.h>

/**
 * 3. Altere o programa anterior para resolver problemas com expoente negativo.
 **/ 

long double potencia(int base, int expoente);

int main(){
    int x, y;

    printf("> x = "); scanf("%d", &x);
    printf("> y = "); scanf("%d", &y);

    printf("< x^y = %Lf\n\n", potencia(x,y));

}

long double potencia(int base, int expoente){
    
    if ( expoente == 0 ) return 1.0;
    if ( expoente < 0 ) return 1.0 / potencia(base, -expoente);
    
    return base * potencia(base, expoente - 1);
}
