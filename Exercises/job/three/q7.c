#include <stdio.h>

int soma1aN(int n) {
	if(n == 1) {
		return 1;
	}
	return n + soma1aN(n - 1);
}

int main(){

    soma1aN(3);

    return 0;
}