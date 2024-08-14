#include <stdio.h>

/**
 * 4) Coloque em ordem o programa e explique.
 * 
 * int main () {
 *   int x, *p;
 *   ( ) *p = x + 20;
 *   ( ) p = &x;
 *   ( ) x = 10;
 * }
*/

int main () {
    int x, *p;      // Declara as variáveis
    x = 10;         // Inicializa x com o valor 10
    p = &x;         // Inicializa p com o endereço de x
    *p = x + 20;    // Equivalente a: (x = x + 20) ou (*p = *p + 20).
}

/**
 * Explicação:
 *  A ordem das instruções x = 10; e p = &x; poderia ser invertida sem causar
 *  problemas, pois p apenas precisa apontar para x antes de *p ser utilizado.
 *  No entanto, *p = x + 20; deve vir após essas duas instruções para garantir
 *  que p aponte para um endereço válido (o de x) e que x tenha um valor
 *  definido. Se *p fosse utilizado antes de p apontar para x, o programa
 *  poderia tentar acessar uma área de memória não inicializada, levando a um
 *  comportamento indefinido.
 */