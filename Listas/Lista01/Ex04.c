#include <stdio.h>
#include <stdlib.h>

/**
 * 4. Considerando a estrutura:
 * struct Ponto {
 *   int x;
 *   int y;
 * };
 * para representar um ponto em uma grade 2D, implemente um programa que
 * indique se um ponto p está localizado dentro ou fora de um retângulo.
 * O retângulo é definido por seus vértices inferior esquerdo v1 e superior
 * direito v2. Utilize uma função que deve imprimir caso o ponto esteja 
 * localizado dentro do retângulo ou não.
 */

typedef struct {
    int x;
    int y;
} Ponto;

int main(int argc, char** argv) {
    Ponto v1, v2, p;
    int result;
    
    printf("> v1 = "); scanf("%d %d", &v1.x, &v1.y);
    printf("> v2 = "); scanf("%d %d", &v2.x, &v2.y);
    printf("> p = "); scanf("%d %d", &p.x, &p.y);

    result = ex04(v1, v2, p);

    if(result){
        printf("< Está dentro do retângulo.\n");
    }else{
        printf("< Não está dentro do retângulo.\n");
    }

	return 0;
}

int ex04(Ponto v1, Ponto v2, Ponto p){

    int minX, maxX, minY, maxY;

    if (v1.x > v2.x){
        maxX = v1.x;
        minX = v2.x;
    } else {
        maxX = v2.x;
        minX = v1.x;
    }

    if (v1.y > v2.y){
        maxY = v1.y;
        minY = v2.y;
    } else {
        maxY = v2.y;
        minY = v1.y;
    }

    return 
        (minX <= p.x && p.x <= maxX) 
    &&  (minY <= p.y && p.y <= maxY);

}
