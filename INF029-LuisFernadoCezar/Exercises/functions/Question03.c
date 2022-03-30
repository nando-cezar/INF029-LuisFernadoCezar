#include <stdio.h>

int factorial(int value);

int main(){

    int value, fact = 0;

    printf("Insert factorial: ");
    scanf("%d", &value);

    fact = factorial(value);

    if(fact == 0)
        printf("Internal Server Error");
    else
        printf("The factorial of %d is %d\n", value, fact);

    return 0;
}

int factorial(int value){

    if (value == 0)
        return 1;

    else if (value < 0)
        return 0;

    else    
        return value * factorial(value-1);

}
