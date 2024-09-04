#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

void gerar(int [], int);
void imprimir(int [], int);
void bubleSort(int [], int);
	
int main()
{
    setlocale(LC_ALL, "");
    const int N=10;
    int A[N];
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO BUBBLE SORT");
    gerar(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");
	bubleSort(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores ordenados");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    return 0;
}

void gerar(int A[], int N){
	int i;
	srand(time(NULL));
	for (i=0; i<N; i++){
		A[i] = rand() % 100; //gera aleatoriamente um número entre 0 e 99
	}	
}

void imprimir(int A[], int N){
	int i;
    printf("\n--------------------------------------------");
    for (i=0; i<N; i++)
    {
        if(A[i] < 10)
			printf("\n|Posicao: %d | Número: 0%d|", i, A[i]);
		else
			printf("\n|Posicao: %d | Número: %d|", i, A[i]);
    }
}

void bubleSort(int A[], int N){
	int i, j, aux;
	//requer N - 1 passagens para cada elemento
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
        	//compara o valor com o próximo e 
        	//faz a troca quando o valor é maior que seu próximo
			if (A[j] > A[j+1]) {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }    
}



