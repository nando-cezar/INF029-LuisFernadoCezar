#include <stdio.h>
#include "questions.h"

int soma1aN(int n) {
	if(n == 1) {
		return 1;
	}
	return n + soma1aN(n - 1);
}
