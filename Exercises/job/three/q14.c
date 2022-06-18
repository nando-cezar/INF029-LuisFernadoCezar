#include <stdio.h>

int pell(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return 2 * pell(n - 1) + pell(n - 2);
}

int main(){

    printf("%d ", pell(5));

    return 0;
}