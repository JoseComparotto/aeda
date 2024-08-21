#include <stdio.h>
#include <math.h>

/**
 * 3. Faça um programa que possua uma função que receba os valores a, b e c
 *    passados por valor, receba também dois valores x1 e x2 passados por
 *    referência. Em seguida, calcule e retorne as duas raízes da equação do
 *    segundo grau nas variáveis x1 e x2.
 */

float raizes(float a, float b, float c, float *x1, float *x2);

int main(){
    float a, b, c, delta, x1, x2;

    printf("> a = "); scanf("%f", &a);
    printf("> b = "); scanf("%f", &b);
    printf("> c = "); scanf("%f", &c);
    
    delta = raizes(a, b, c, &x1, &x2);
    
    if(delta == 0){
        printf("\n< x = %.2f\n", x1);
    }else if(delta > 0){
        printf("\n< x = {%.2f, %.2f}\n", x1, x2);
    }else {
        printf("\n< x não tem solução real.\n");
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