#include <stdio.h>

int factorial(int n);

int main(){

    int n, result = 0;

    printf("Informe valor: ");
    scanf("%d", &n);

    printf("%d\n", factorial(n));
         
    return 0;
}

int factorial(int n){

    int factorial = 1;
    int monitor = n;

    if(n == 0)
        return 1;

    if(n < 0)
        n = negativeConvert(n);
    
    for(int i = n; i > 0; i--, n--)
        factorial *= n; 
 
    if(monitor < 0)
        return negativeConvert(factorial);

    return factorial;
}

int negativeConvert(int n){
    return n * (-1);
}