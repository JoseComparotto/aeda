
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

void gerar(int [], int);
void imprimir(int [], int);
void selectionSort(int [], int);
	
int main()
{
    setlocale(LC_ALL, "");
    const int N=10;
    int A[N];
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO SELECTION SORT");
    gerar(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");
	selectionSort(A, N);
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

void selectionSort(int A[], int N){
	int i, j, aux, min;
    for (i=0; i < N-1; i++){
    	//primeiro número não ordenado ainda
    	min = i;
        for (j=i+1; j < N; j++){
    		//Caso tenha algum número menor faz a troca do mínimo
            if(A[j] < A[min])
            	min = j;
    	}
    	//Se o mínimo for diferente do primeiro número não ordenado
    	//faz a troca para ordená-los
		if (i != min){
            aux = A[i];
            A[i] = A[min];
            A[min] = aux;
        }
    }
}



