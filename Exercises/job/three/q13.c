#include <stdio.h>
#include "questions.h"

int padovan(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return padovan(n - 2) + padovan(n - 3);
}

int main(){

    printf("%d ", padovan(5));

    return 0;
}