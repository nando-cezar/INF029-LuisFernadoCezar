#include <stdio.h>
#include "questions.h"

int fatQuadruplo(int n) {
	int interna(int n, int k) {
		if(n == k) {
			return  k;
		}
		return n * interna(n - 1, k);
	}
	return interna(2 * n, n + 1);
}