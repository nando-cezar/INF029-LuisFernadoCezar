#include <stdio.h>

int fatorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * fatorial(n - 1);
}

int main(){

    fatorial(5);

    return 0;
}