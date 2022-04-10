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

int verifyResult(char matrix[LINE][COLUMN], int player){

    if(player == 1){
        if     (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') return 1;
        else if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') return 1;
        else if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') return 1;

        else if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') return 1;
        else if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 1;
        else if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') return 1;

        else if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 1;
        else if(matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X') return 1;
        else return 0;
    
    }else if(player == 2){

        if     (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') return 1;
        else if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') return 1;
        else if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') return 1;

        else if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') return 1;
        else if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 1;
        else if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') return 1;

        else if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 1;
        else if(matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O') return 1;
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