#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

void gerar(int [], int);
void imprimir(int [], int);
void mergeSort(int v[], int left, int right);
void merge(int [], int esq, int meio, int dir);
	
int main()
{
    setlocale(LC_ALL, "");
    const int N=10;
    int A[N];
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO MERGE SORT");
    gerar(A, N);
    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir(A, N);
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");
	mergeSort(A, 0, N-1);
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

void mergeSort(int v[], int esq, int dir){   
    if (esq >= dir)
        return;
    else { 
        int meio = (esq + dir) / 2;
        mergeSort(v, esq, meio);
        mergeSort(v, meio + 1, dir);
        merge(v, esq, meio, dir);
    }    
}

void merge(int v[], int esq, int meio, int dir){
        // transfere os elementos entre esq e dir para um vetor auxiliar.
        int aux[dir+1];
        for (int i = esq; i <= dir; i++)
            aux[i] = v[i];
        
        int i = esq;
        int j = meio + 1;
        int k = esq;
        
        while (i <= meio && j <= dir){
            if (aux[i] <= aux[j]){
                v[k] = aux[i];
                i++;
            } else{
                v[k] = aux[j];
                j++;
            }
            k++;    
        }
        
        // se a metade inicial não foi toda consumida, faz o append.
        while (i <= meio){
            v[k] = aux[i];
            i++;
            k++;
        }
        
        // se a metade final não foi toda consumida, faz o append.
        while (j <= dir){
            v[k] = aux[j];
            j++;
            k++;
        }
}

