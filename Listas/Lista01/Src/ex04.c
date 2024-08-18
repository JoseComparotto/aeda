#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 4. Considerando a estrutura:
 * 
 *    ```c
 *    struct Ponto {
 *       int x;
 *       int y;
 *    };
 *    ``` 
 * 
 *    para representar um ponto em uma grade 2D, implemente um programa que
 *    indique se um ponto p está localizado dentro ou fora de um retângulo.
 *    O retângulo é definido por seus vértices inferior esquerdo v1 e superior
 *    direito v2. Utilize uma função que deve imprimir caso o ponto esteja 
 *    localizado dentro do retângulo ou não.
 */

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    unsigned int width;
    unsigned int height;
} Rect;

Rect rectFrom(Point a, Point b) {
    Rect r;

    r.x = a.x < b.x ? a.x : b.x;
    r.y = a.y < b.y ? a.y : b.y;

    r.width = abs(a.x - b.x);
    r.height = abs(a.y - b.y);
    
    return r;
}

int isPointInRect(Point p, Rect r) {
    return (p.x >= r.x && p.x <= r.x + r.width &&
            p.y >= r.y && p.y <= r.y + r.height);
}

int main(int argc, char** argv) {
    Point v1, v2, p;
    Rect r;
    
    printf("> v1.x = "); scanf("%d", &v1.x);
    printf("> v1.y = "); scanf("%d", &v1.y);
    
    printf("> v2.x = "); scanf("%d", &v2.x);
    printf("> v2.y = "); scanf("%d", &v2.y);

    printf("> p.x = "); scanf("%d", &p.x);
    printf("> p.y = "); scanf("%d", &p.y);

    r = rectFrom(v1, v2);

    if(isPointInRect(p, r)) {
        printf("< Está dentro do retângulo.\n");
    } else {
        printf("< Não está dentro do retângulo.\n");
    }

    return 0;
}
