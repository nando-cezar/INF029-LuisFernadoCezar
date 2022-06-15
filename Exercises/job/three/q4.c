#include <stdio.h>

int somaVetor(int vet[], int n) {
	if(n == 1) {
		return vet[0];
	}
	return vet[n - 1] + somaVetor(vet, n - 1);
}

int main(){

    int v = {1,2,3,4,3,7,4,9,3,5,1}
    somaVetor(v, 3);

    return 0;
}