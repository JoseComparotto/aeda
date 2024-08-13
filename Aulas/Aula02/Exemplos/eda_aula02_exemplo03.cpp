#include <stdio.h>
#include <stdlib.h>
int main (){
	int *p;
	p = (int *) malloc(sizeof(int));
	
	if (!p)
		printf("Erro de memoria insuficiente!");
	else
		printf("Memoria alocada com sucesso!");
	return 0;
}


