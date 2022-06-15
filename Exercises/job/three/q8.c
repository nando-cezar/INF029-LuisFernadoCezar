#include <stdio.h>

int multRec(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + multRec(a, b - 1);
}

int main(){

    multRec(4, 5);

    return 0;
}