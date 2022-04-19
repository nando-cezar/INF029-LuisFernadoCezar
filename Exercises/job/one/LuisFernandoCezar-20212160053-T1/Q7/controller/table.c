#include "../utility/utility.h"
#include "table.h"

void initializeMatrix(char matrix[LINE][COLUMN]){

    for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN; j++){
            matrix[i][j] = SPACE;
        }
    }

}

int verifyValuesInMatrix(char matrix[LINE][COLUMN], int i, int j){

    if(matrix[i][j] == SPACE) return 1;
    else return 0;
}

int haveSpaceInMatrix(char matrix[LINE][COLUMN]){

    for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN; j++){
            if(matrix[i][j] == SPACE){
                return 1;
            }
        }
    }
    return 0;
}

int verifyColumn(char matrix[LINE][COLUMN], char symbol){

    for(int i = 0; i < 3; i++){
        if(
            matrix[0][i] == symbol &&
            matrix[1][i] == symbol &&
            matrix[2][i] == symbol
        ){
            return 1;
        } 
    }

    return 0;
}

int verifyLine(char matrix[LINE][COLUMN], char symbol){

    for(int i = 0; i < 3; i++){
        if(
            matrix[i][0] == symbol &&
            matrix[i][1] == symbol &&
            matrix[i][2] == symbol
        ){
            return 1;
        } 
    }

    return 0;
}

int verifyDiagonal(char matrix[LINE][COLUMN], char symbol){
    
    if(matrix[0][0] == symbol && matrix[1][1] == symbol && matrix[2][2] == symbol) return 1;
    else if(matrix[2][0] == symbol && matrix[1][1] == symbol && matrix[0][2] == symbol) return 1;
    else return 0;
}

int verifyResult(char matrix[LINE][COLUMN], int player){

    if(player == 1){
        if(verifyColumn(matrix, 'X')) return 1;
        else if(verifyLine(matrix, 'X')) return 1; 
        else if(verifyDiagonal(matrix, 'X')) return 1;
        else return 0;
    
    }else if(player == 2){

        if(verifyColumn(matrix, 'O')) return 1;
        else if(verifyLine(matrix, 'O')) return 1; 
        else if(verifyDiagonal(matrix, 'O')) return 1;
        else return 0;
    }
    
}

int setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char keyLine, int indexLine, char symbol){

    int flag = 0;

    if(line == keyLine){
        for(int i = 0; i < COLUMN; i++){
            if(column == i+1){
                if(verifyValuesInMatrix(matrix, indexLine, i)) matrix[indexLine][i] = symbol;
                else flag = 1;
            }
        }
    }

    return flag;
}