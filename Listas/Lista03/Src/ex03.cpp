#include <stdio.h>
#include <math.h>

/**
 * 3. Faça um programa que possua uma função que receba os valores a, b e c
 *    passados por valor, receba também dois valores x1 e x2 passados por
 *    referência. Em seguida, calcule e retorne as duas raízes da equação do
 *    segundo grau nas variáveis x1 e x2.
 */

void teste(float a, float b, float c);
float raizes(float a, float b, float c, float *x1, float *x2);

int main(){
    // Casos de Teste    # Resultado Esperado
    teste( 1, -4,   3);  // x = {3.00,  1.00}
    teste( 1,  3, -10);  // x = {2.00, -5.00}
    teste( 4,  8, -12);  // x = {1.00, -3.00}
    teste( 3, -7,  -6);  // x = {3.00, -0.67}
    teste( 4, 12,   9);  // x = 1.50
    teste( 2,  4,   8);  // x não tem solução real.
}

void teste(float a, float b, float c){
    float delta, x1, x2;

    printf("Para: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);

    delta = raizes(a, b, c, &x1, &x2);
    
    if(delta == 0){
        printf("x = %.2f\n", x1);
    }else if(delta > 0){
        printf("x = {%.2f, %.2f}\n", x1, x2);
    }else {
        printf("x não tem solução real.\n");
    }
    printf("\n");
}

float raizes(float a, float b, float c, float *x1, float *x2){

    float delta = b*b - 4*a*c;
    if(delta < 0) return delta;

    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);

    return delta;
}