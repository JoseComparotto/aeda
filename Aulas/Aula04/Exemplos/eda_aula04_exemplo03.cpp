#include <stdio.h>
#include <locale.h>

//Prototipação da função
long fib(int);

//Programa principal
int main (){
	setlocale(LC_ALL,"");
	int x;
	printf("Informe a posição do termo da sequência de Fibonacci: ");
	scanf("%d",&x);
	long f = fib(x);
	printf("O termo na posição %d é = %ld\n", x, f);
	return 0;
}

// Solução recursiva para o cálculo de Fibonacci
long fib(int n){
    if (n == 1 || n==2)  // caso base
    	return 1;
    else 
		return (fib(n-1) + fib(n-2)); // caso geral
}




