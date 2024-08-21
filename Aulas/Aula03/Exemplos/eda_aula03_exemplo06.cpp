#include <stdio.h>
void multiplica (int &x){
	x = x * x;
}
int main() {
	int t=10;
	multiplica(t);
	printf("Valor de t: %d", t); 
	return 0;
}


