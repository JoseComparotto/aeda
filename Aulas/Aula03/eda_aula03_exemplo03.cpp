#include <stdio.h>
#include <locale.h>

void soma(float, int);

int main() {
	setlocale(LC_ALL,"");
	int a = 10;
	float b = 12.3;
	soma(b,a); 
	return 0;
}

void soma(float a, int b)
{
	float result;
	result = a+b;
	printf("A soma de %.2f com %d é %.2f", a, b, result); 
}


