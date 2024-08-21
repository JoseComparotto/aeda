#include <stdio.h>
#include <locale.h>

void soma(float a, int b) // parâmetros separados por vírgulas
{
	float result; // declaração de variáveis é igual a função main
	result = a+b;
	printf("A soma de %.2f com %d é %.2f", a, b, result); 
}

int main() {
	setlocale(LC_ALL,"");
	int a = 10;
	float b = 12.3;
	soma(b,a); // Chamada da função SOMA(12.3,10)
	return 0;
}


