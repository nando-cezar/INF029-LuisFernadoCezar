#include <stdio.h>

int converteParaBinario(int n){
    if (n < 2) 
        return n;
    return ( 10 * converteParaBinario( n / 2 ) ) + n % 2;
}

int main(){

    converteParaBinario(3);

    return 0;
}