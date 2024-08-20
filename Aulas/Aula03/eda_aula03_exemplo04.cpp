#include <stdio.h>
#include <locale.h>

void FUNC1(){
	int B = -100;
	printf("Valor de B dentro da função FUNC1: %d\n", B);
}
void FUNC2(){
	int B = -200;
	printf("Valor de B dentro da função FUNC2: %d\n", B);
}

int main() {
	setlocale(LC_ALL,"");
	int B = 10;
	printf("Valor de B: %d\n", B);
	B += 10;
	FUNC1();
	printf("Valor de B: %d\n", B);
	B += 10;
	FUNC2();
	printf("Valor de B: %d\n", B);
	return 0;
}


