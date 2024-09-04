#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

void gerar(int [], int);
void imprimir(int [], int);
int particionar(int [], int, int);
void quickSort(int v[], int, int);
void trocar(int [], int, int);
	
int main()
{
    setlocale(LC_ALL, "");
    const int N=10;
    int A[N];
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO QUICK SORT");
    gerar(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");
	quickSort(A, 0, N-1);
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


//Particionamento de Lomuto
int particionar(int A[], int left, int right){
    int pivo = A[left];
    int i = left;
	for (int j = left + 1; j <= right; j++){
        if (A[j] <= pivo) {
            i++;
            trocar(A, i, j);
        }
    }
    // troca pivot (A[left]) com i.
    trocar(A, left, i);
    return i; 
}

void quickSort(int A[], int left, int right){
    if (left < right) {
        //realiza a partição
        int p = particionar(A, left, right);
        //ordena a partição esquerda
        quickSort(A, left, p - 1);
        //ordena a partição direita
        quickSort(A, p + 1, right);
    }
}

void trocar(int A[], int i, int j){
    int aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}


