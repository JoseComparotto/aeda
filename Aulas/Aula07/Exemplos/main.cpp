#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        printf("========================\n");
        printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
    }

    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

	//Remoções
    remove_ArvAVL(avl,6);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,7);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,4);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    libera_ArvAVL(avl);

    return 0;
}
