#include <stdio.h>
int main (){
	int x = 2;
	int *ptr;
	ptr = &x;
	
	*ptr = 6;

	printf("Valor de x = %d\n", x);
	printf("Endereco de x = %d\n", &x);
	printf("Conteudo armazenado no ponteiro = %d\n", ptr);
	printf("Conteudo do local onde o ponteiro aponta = %d\n", *ptr);

	printf("\n\n");

	return 0;
}


