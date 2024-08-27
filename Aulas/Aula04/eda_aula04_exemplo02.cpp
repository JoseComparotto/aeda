#include <stdio.h>
#include <locale.h>

// Solução recursiva para o cálculo do fatorial
long fatorial(int n){
	if (n == 0)
		return 1;
	else
        return (n*fatorial(n-1));
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




