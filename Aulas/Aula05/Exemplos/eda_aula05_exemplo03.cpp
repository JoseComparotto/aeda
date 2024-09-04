#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

void gerar(int [], int);
void imprimir(int [], int);
void insertionSort(int [], int);
	
int main()
{
    setlocale(LC_ALL, "");
    const int N=10;
    int A[N];
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO INSERTION SORT");
    gerar(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");
	insertionSort(A, N);
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

void insertionSort(int A[], int N){
	int i, j, elemento;
    for (i=1; i < N; i++){
    	//O elemento que será usado para as comparações é guardado
    	elemento = A[i];
    	//enquanto não encontrar a posição do elementos desloca-se todos 
    	//os elementos uma posição para a direita
        for (j=i-1; j>=0 && A[j]>elemento; j--)
            A[j+1] = A[j];
        //a posição foi encontrada e o elemento é colocado na posição correta
    	A[j+1] = elemento;
    }
}



