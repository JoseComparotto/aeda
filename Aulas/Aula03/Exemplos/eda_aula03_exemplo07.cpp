#include <stdio.h>
// Define que o parâmetro é uma referência à outra variável
void zera(float *a){
	// utiliza o operador de referência para alterar o conteúdo da variável
    *a = 0; 
}

int main(){
	float f;
    f = 20.7;
    zera(&f);  // Passa o endereço da variável f para a função
    printf("Valor final: %.2f", f);
}


