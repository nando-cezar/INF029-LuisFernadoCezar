#include <stdio.h>


int tetranacci(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 0;
	}
	if(n == 3) {
		return 1;
	}
	return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}

int main(){

    tetranacci(5);

    return 0;
}