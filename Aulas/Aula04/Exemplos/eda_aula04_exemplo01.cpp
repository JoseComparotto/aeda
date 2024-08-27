#include <stdio.h>
#include <locale.h>

// Solução iterativa para o cálculo do fatorial
long fatorial(int n){
	// declarações locais
   	long fatN = 1;
	int i;
  	for (i = 1; i <= n; i++)
       	fatN *= i;
  	return fatN;
} //fim fatorial

int main (){
	setlocale(LC_ALL,"");
	int x;
	printf("Informe o valor para o cálculo do fatorial: ");
	scanf("%d",&x);
	long fat = fatorial(x);
	printf("O fatorial de %d é = %ld\n", x, fat);
	return 0;
}




