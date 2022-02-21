#include <stdio.h>

int sum(int n1, int n2);

int main(){

    int n1, n2;
 
    printf("Informe primeiro valor: ");
    scanf("%d", &n1);
    printf("Informe segundo valor: ");
    scanf("%d", &n2);

    printf("Resultado: %d", sum(n1, n2));

    return 0;
}

int sum(int n1, int n2){
    return n1 + n2;
}