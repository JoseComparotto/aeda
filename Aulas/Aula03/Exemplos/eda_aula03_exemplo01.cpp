#include <stdio.h>
#include <locale.h>

void esperaZero(){
	char tecla;
	do {
		fflush(stdin);
		tecla = getc(stdin);
		if (tecla != '0') {
			printf("Nao é zero\n");
		}
	} while (tecla != '0'); 
}
int main(){
	setlocale(LC_ALL,"");
	esperaZero(); // Chamada da função definida antes
	// ...........
	esperaZero(); // Chamada da função definida antes
	return 0;
}



