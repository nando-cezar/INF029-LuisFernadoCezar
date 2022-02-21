#include <stdio.h>

int subtract(int n1, int n2, int n3);

int main(){

    int n1, n2, n3;
 
    printf("Informe primeiro valor: ");
    scanf("%d", &n1);
    printf("Informe segundo valor: ");
    scanf("%d", &n2);
    printf("Informe segundo valor: ");
    scanf("%d", &n3);

    printf("Resultado: %d", subtract(n1, n2, n3));

    return 0;
}

int subtract(int n1, int n2, int n3) {
    return n1 - n2 - n3;
}