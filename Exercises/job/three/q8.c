#include <stdio.h>

int fatDuplo(int n) {
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatDuplo(n - 2);
}

int main(){

    fatDuplo(5);

    return 0;
}