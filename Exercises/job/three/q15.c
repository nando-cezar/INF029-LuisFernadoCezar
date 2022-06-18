#include <stdio.h>

int catalan(int n) {
	if(n == 0) {
		return 1;
	}
	return 2 * (2 * n - 1) * catalan(n - 1) / (n + 1);
}

int main(){

    printf("%d ", catalan(3));

    return 0;
}