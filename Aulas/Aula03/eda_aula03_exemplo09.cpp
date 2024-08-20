#include <stdio.h>

void zeraVet(float *V, int qtd){
    int i;
    for(i=0;i<qtd;i++)
       V[i] = 0.0;
}

int main(){
    int i;
    float Vet[10];

    zeraVet(Vet,10);  // Passa o nome do vetor como parâmetro
    for(i=0;i<10;i++)
    	printf("%d ", Vet[i]); 
    return 0;
}


