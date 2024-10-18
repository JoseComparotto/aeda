#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ArvoreBinaria.h"

void testa_consulta_ArvBin(ArvBin* raiz);

int main(){
	setlocale(LC_ALL,"");
	
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    for(int i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);
        
    printf("Pesquisa em Ordem\n");
	emOrdem_ArvBin(raiz);
	
	printf("\nPesquisa em Pré Ordem\n");
	preOrdem_ArvBin(raiz);
	
	printf("\nPesquisa em Pós Ordem\n");
	posOrdem_ArvBin(raiz);
	
	printf("\nAltura da árvore = %d\n", altura_ArvBin(raiz));

	testa_consulta_ArvBin(raiz);

    libera_ArvBin(raiz);

    return 0;
}

void testa_consulta_ArvBin(ArvBin* raiz){
	
	int valor;
	
	printf("\nConsultar valores na Árvore:\n");
	printf("0 = Encerrar.\n\n");
	
	do{
		printf("Valor = "); scanf("%d", &valor);
		
		if(consulta_ArvBin(raiz, valor)){
			printf("%d está presente!\n", valor);
		}else{
			printf("%d não está presente!\n", valor);
		}
	}while(valor != 0);
}