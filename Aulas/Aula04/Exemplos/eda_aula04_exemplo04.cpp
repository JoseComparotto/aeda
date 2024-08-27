#include <stdio.h>
#include <locale.h>

//Prototipação da função
long fibIter(int);

//Programa principal
int main (){
	setlocale(LC_ALL,"");
	int x;
	printf("Informe a posição do termo da sequência de Fibonacci: ");
	scanf("%d",&x);
	long fib = fibIter(x);
	printf("O termo na posição %d é = %ld\n", x, fib);
	return 0;
}

// Solução iterativa para o cálculo de Fibonacci
long fibIter(int n) { 
	int i=1, k, F=0; 
	for (k = 1; k <= n; k++) { 
    	F += i; 
		i = F - i; 
	} 
   	return F; 
} 




