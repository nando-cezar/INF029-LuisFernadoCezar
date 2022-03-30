#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef struct {
    int value;
} NumberInfo; 

NumberInfo setValue();
void getValue(NumberInfo number);

int main(){

    NumberInfo number[SIZE];

    for(int i = 0; i < SIZE; i++)
        number[i] = setValue();

    for(int i = 0; i < SIZE; i++)
        getValue(number[i]); 

    return 0;
}

NumberInfo setValue(){

    NumberInfo number;

    printf("Insert value: ");
    scanf("%d", &number.value);
    
    return number;
}

void getValue(NumberInfo number){
    printf("Value: %d\n", number.value);
}
