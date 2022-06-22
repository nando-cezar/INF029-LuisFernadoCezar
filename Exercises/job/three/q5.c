#include <stdio.h>
#include "questions.h"

int potenciakn(int k, int n) {
	if(n == 1) {
		return k;
	}
	return k * potenciakn(k, n - 1);
}
