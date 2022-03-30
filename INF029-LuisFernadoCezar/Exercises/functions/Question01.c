#include <stdio.h>

int sum(int n1, int n2);

int main(){

    int n1, n2;
 
    printf("Insert first value: ");
    scanf("%d", &n1);
    printf("Insert second value: ");
    scanf("%d", &n2);

    printf("Result: %d", sum(n1, n2));

    return 0;
}

int sum(int n1, int n2){
    return n1 + n2;
}