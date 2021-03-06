#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "questions.h"

int inverte(int n) {
	if((n / 10) == 0) {
		return n;
	}
	return inverte(n / 10) + (n % 10) * pow(10, abs(log10(n)));
}

int inverteSig(int n) {
	if(n < 0) {
		return -1 * inverte(n * -1);
	}
	return inverte(n);
}
