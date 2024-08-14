#include <stdio.h>

/**
 * 2)  Qual a falha no uso de ponteiros do programa abaixo?
 */

int main(){
    float x,y;
    int *p;
    x = 100.25;
    p = &x;
    y = *p;
    printf("x = %f e y = %f", x, y);
    return 0;
}

/** 
 * Resposta:
 *  O ponteiro p é do tipo int *, ou seja, identifica um endereço de memória
 *  que armazena valores do tipo int. Logo, a atribuição p = &x; é inválida
 *  pois tenta definir o endereço aramazenado em p para o endereço de uma
 *  variável do tipo float, quando era esperado um endereço de uma variável
 *  do tipo int.
 */