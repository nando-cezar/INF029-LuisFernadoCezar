#include <stdio.h>
#include "questions.h"

int converteParaBinario(int n){
    if (n < 2) 
        return n;
    return ( 10 * converteParaBinario( n / 2 ) ) + n % 2;
}
