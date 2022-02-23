#include <stdio.h>

int subtract(int n1, int n2, int n3);

int main(){

    int n1, n2, n3;
 
    printf("Insert first value: ");
    scanf("%d", &n1);
    printf("Insert second value: ");
    scanf("%d", &n2);
    printf("Insert third value: ");
    scanf("%d", &n3);

    printf("Result: %d", subtract(n1, n2, n3));

    return 0;
}

int subtract(int n1, int n2, int n3) {
    return n1 - n2 - n3;
}