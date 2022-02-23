#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COLUMNS 255


char ** allocateBoard(int rows, int columns);
char ** getPhrases();

int main(){

    char ** array = allocateBoard(ROW, COLUMNS);

    array = getPhrases();

    for(int i = 0; i < ROW; i++)
        printf("Position result %d: %s\n", i, array[i]);  

    return 0;
}

char ** getPhrases(){ 
 
   char ** phrases = allocateBoard(ROW, COLUMNS);
    
    for(int i = 0; i < ROW; i++){
        printf("Insert phrase %d: ", i);
        fgets(phrases[i], COLUMNS, stdin);
    }

    return phrases;
}

char ** allocateBoard(int rows, int columns){

    char **board = (char **)malloc(rows * sizeof(char *));

    for (int row = 0; row < rows; row++) {
        board[row] = (char *)malloc(columns * sizeof(char));
    }

    return board;
}