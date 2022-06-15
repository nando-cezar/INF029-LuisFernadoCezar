#include <stdio.h>

float inverteVetor(float vet[], int n) {
	int aux;
	if(n % 2 == 0) {
		aux = 0;
	} else {
		aux = -1;
	}
	float interna(float vet[], int n, int i) {
		if(n == i) {
			return vet[n];
		}
		float aux;
		interna(vet, n - 1, i + 1);
		aux = vet[n-1];
		vet[n-1] = vet[i+1];
		vet[i+1] = aux;
	}
	return(interna(vet, n, aux));
}

int main(){

    int v = {1,2,3,4,3,7,4,9,3,5,1}
    inverteVetor(v, 5);

    return 0;
}