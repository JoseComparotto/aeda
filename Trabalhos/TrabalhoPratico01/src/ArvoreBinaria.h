typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin *raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);

//implementações a serem realizadas
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
int menorValor_ArvBin(ArvBin *raiz);
int maiorValor_ArvBin(ArvBin *raiz);
int*** matrizPorNivel_ArvBin(ArvBin *raiz);
void imprimePorNivel_ArvBin(ArvBin *raiz);
