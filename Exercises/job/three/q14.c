#include <stdio.h>
#include "questions.h"

int pell(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return 2 * pell(n - 1) + pell(n - 2);
}
