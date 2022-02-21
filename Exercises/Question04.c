#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int * getNumbers();

int main(){

    int * array = (int *) calloc (SIZE, sizeof (int));

    array = getNumbers();

    for(int i = 0; i < SIZE; i++)
        printf("Resultado posicao %d: %d\n", i, array[i]);  

    return 0;
}

int * getNumbers() {
 
   int * numbers = (int *) calloc (SIZE, sizeof (int));
    
    for(int i = 0; i < SIZE; i++){
        printf("Informe valor %d: ", i);
        scanf("%d", &numbers[i]);
    }

    return numbers;
}