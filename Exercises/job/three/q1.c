#include <stdio.h>
#include "questions.h"

int fatorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * fatorial(n - 1);
}