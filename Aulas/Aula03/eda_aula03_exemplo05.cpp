#include <stdio.h>
int multiplica (int x){
	x = x * x;
	return (x);
}
int main() {
	int t=10;
	printf("%d - %d", multiplica(t), t); 
	return 0;
}

