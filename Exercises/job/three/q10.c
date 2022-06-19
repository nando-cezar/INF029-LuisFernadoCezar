#include <stdio.h>
#include "questions.h"

int superFat(int n) {
	if(n == 0 || n == 1) {
		return 1;
	}
	int interna(int n) {
		if(n == 0 || n == 1) {
			return 1;
		}
		return n * interna(n - 1);
	}
	return interna(n) * superFat(n - 1);

}

int main(){

    printf("%d ", superFat(5));

    return 0;
}