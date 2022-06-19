#include <stdio.h>
#include "questions.h"

int maxDivCom(int a, int b) {
	if( b == 0) {
		return a;
	}
	maxDivCom(b, a % b);
}

int main(){

    printf("%d ", maxDivCom(30, 9));

    return 0;
}