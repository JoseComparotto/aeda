#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#include "ArvoreBinaria.h" //inclui os Protótipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NO;

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(NO *no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);	//libera cada nó
    free(raiz);			//libera a raiz
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    NO* novo;
    novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        NO* atual = *raiz;
        NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

NO* remove_atual(NO *atual) {
    NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

//A função retorna 0 quando a árvore está vazia (ou seja, NULL) ou
//o valor procurado para remoção não existe na árvore.
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    NO* ant = NULL;
    NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return -1;
    if (*raiz == NULL)
        return -1;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int menorValor_ArvBin(ArvBin *raiz){

    if(estaVazia_ArvBin(raiz)) return 0;
    int menor = 0;

    NO* noAtual = *raiz;

    while (noAtual != NULL){
        menor = noAtual->info;
        noAtual = noAtual->esq;
    }
    
    return menor;
}

int maiorValor_ArvBin(ArvBin *raiz){

    if(estaVazia_ArvBin(raiz)) return 0;
    int maior = 0;

    NO* noAtual = *raiz;

    while (noAtual != NULL){
        maior = noAtual->info;
        noAtual = noAtual->dir;
    }
    
    return maior;
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_ArvBin(ArvBin *raiz, int valor){

    NO* noAtual = *raiz;

    while (noAtual != NULL)
    {
        if(valor < noAtual -> info){
            noAtual = noAtual -> esq;
        }
        else if(valor > noAtual -> info){
            noAtual = noAtual -> dir;
        }
        else return 1; // O valor é igual ao valor do nó atual.
    }

    return 0; // O valor não foi encontrado na árvore
}

struct ElementoFila {
    NO *no;
    int nivel;
    int posicao;
};

typedef struct ElementoFila ElementoFila;

int*** matrizPorNivel_ArvBin(ArvBin *raiz) {
    if (estaVazia_ArvBin(raiz))
        return NULL;

    int altura = altura_ArvBin(raiz);

    // Aloca a matriz de ponteiros onde cada linha i terá 2^i colunas
    int ***matriz = (int ***) malloc(altura * sizeof(int **));
    for (int i = 0; i <= altura; i++) {
        int largura = exp2(i); // 2^i

        matriz[i] = (int **) malloc(largura * sizeof(int *));
        // Inicializa todas as posições com NULL
        for (int j = 0; j < largura; j++) {
            matriz[i][j] = NULL;
        }
    }

    // Cria uma fila para armazenar os nós e suas posições
    ElementoFila *fila = (ElementoFila *) malloc(exp2(altura) * sizeof(ElementoFila));
    int inicio = 0, fim = 0; // Controladores do início e fim da fila

    // Coloca a raiz na fila
    fila[fim].no = *raiz;
    fila[fim].nivel = 0;
    fila[fim].posicao = 0;
    fim++;

    while (inicio < fim) {
        ElementoFila atual = fila[inicio];
        inicio++;

        // Coloca o ponteiro para o valor do nó na matriz na posição correta
        matriz[atual.nivel][atual.posicao] = &(atual.no->info);

        // Se o nó atual tiver filho à esquerda, coloca na fila
        if (atual.no->esq != NULL) {
            fila[fim].no = atual.no->esq;
            fila[fim].nivel = atual.nivel + 1;
            fila[fim].posicao = 2 * atual.posicao;
            fim++;
        }

        // Se o nó atual tiver filho à direita, coloca na fila
        if (atual.no->dir != NULL) {
            fila[fim].no = atual.no->dir;
            fila[fim].nivel = atual.nivel + 1;
            fila[fim].posicao = 2 * atual.posicao + 1;
            fim++;
        }
    }

    // Libera a fila após o uso
    free(fila);

    return matriz;
}

void imprime_ArvBin(ArvBin *raiz) {

    if (estaVazia_ArvBin(raiz)) return;

    int*** matriz = matrizPorNivel_ArvBin(raiz);

    int altura = altura_ArvBin(raiz);
    int maiorValor = maiorValor_ArvBin(raiz);
    int menorValor = menorValor_ArvBin(raiz);

    // Calcula o número máximo de dígitos a ser impresso (maior ou menor valor na árvore)
    int maxDigitos = maior(numeroDigitos(maiorValor), numeroDigitos(menorValor));
    int espacoMinimo = 3; // Espaçamento mínimo entre nós

    // Percorre cada nível da árvore
    for (int i = 0; i <= altura; i++) {
        int numNosNivel = exp2(i); // Número de nós no nível 'i'
        
        // Espaçamento inicial para centralizar o primeiro nó do nível
        int espacoInicial = (exp2(altura - i) - 1) * (maxDigitos + espacoMinimo) / 2;
        
        // Imprime o espaço inicial
        printf("%*s", espacoInicial, "");

        // Percorre os nós no nível atual
        for (int j = 0; j < numNosNivel; j++) {
            if (matriz[i][j] != NULL)
                printf("%*d", maxDigitos, *matriz[i][j]); // Imprime o valor do nó
            else
                printf("%*s", maxDigitos, ""); // Espaço vazio (nó ausente)

            // Espaçamento entre os nós no mesmo nível
            if (j < numNosNivel - 1) {
                int espacoEntreNos = (exp2(altura - i + 1) - 1) * (maxDigitos + espacoMinimo) / 2;
                printf("%*s", espacoEntreNos, "");
            }
        }
        printf("\n");
    }
}

