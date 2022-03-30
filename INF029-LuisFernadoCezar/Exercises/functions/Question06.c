#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

char * getChars();

int main(){

    char * array = (char *) calloc (SIZE, sizeof (char));

    array = getChars();

    for(char i = 0; i < SIZE; i++)
        printf("Position result %d: %c\n", i, array[i]);  

    return 0;
}

char * getChars() {
 
   char * chars = (char *) calloc (SIZE, sizeof (char));
    
    for(char i = 0; i < SIZE; i++){
        printf("Insert char %d: ", i);
        scanf(" %c", &chars[i]);
    }

    return chars;
}