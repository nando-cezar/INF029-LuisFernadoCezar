
#include <stdio.h>

int verifyResult(char matrix[3][3], int player){

    if(player == 1){
        if     (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') return 1;
        else if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 1;
        else if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') return 1;

        else if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') return 1;
        else if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 1;
        else if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') return 1;

        else if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 1;
        else if(matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X') return 1;
        else return 0;
    
    }else if(player == 2){

        if     (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') return 1;
        else if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 1;
        else if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') return 1;

        else if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') return 1;
        else if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 1;
        else if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') return 1;

        else if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 1;
        else if(matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O') return 1;
        else return 0;
    }
    
}

int verifyValuesInMatrix(char matrix[3][3], int i, int j){

    if(matrix[i][j] == 32) return 1;
    else return 0;
}

void main(){
    
    char matrix[3][3];
    char line; 
    int column = 0;
    int continua = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 32;
        }
    }

    do{

        printf("      %d    %d    %d\n", 1, 2, 3);
        for(int i = 0; i < 3; i++){
            printf("%c ", 65 + i);
            printf("|");
            for(int j = 0; j < 3; j++){
                printf("  %c  |", matrix[i][j]);
                if(j == 2) printf("\n");
            }
        }

    

        printf("Jogador 1:");
        scanf(" %c %d", &line, &column);

        if(line == 'A'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 0, 0)) matrix[0][0] = 'X';
                //DO WHILE QUANDO FOR NÃO
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 0, 1)) matrix[0][1] = 'X';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 0, 2)) matrix[0][2] = 'X';
            }
        }else if(line == 'B'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 1, 0)) matrix[1][0] = 'X';
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 1, 1)) matrix[1][1] = 'X';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 1, 2)) matrix[1][2] = 'X';
            }
        }else if(line == 'C'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 2, 0)) matrix[2][0] = 'X';
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 2, 1)) matrix[2][1] = 'X';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 2, 2)) matrix[2][2] = 'X';
            }
        }

        if(verifyResult(matrix, 1)){
            printf("JOGADOR 1 VENCEU!!!\n");
            break;
        }

        printf("\nJogador 2:");
        scanf(" %c %d", &line, &column);

        if(line == 'A'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 0, 0)) matrix[0][0] = 'O';
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 0, 1)) matrix[0][1] = 'O';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 0, 2)) matrix[0][2] = 'O';
            }
        }else if(line == 'B'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 1, 0)) matrix[1][0] = 'O';
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 1, 1)) matrix[1][1] = 'O';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 1, 2)) matrix[1][2] = 'O';
            }
        }else if(line == 'C'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 2, 0)) matrix[2][0] = 'O';
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 2, 1)) matrix[2][1] = 'O';
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 2, 2)) matrix[2][2] = 'O';
            }
        }

        if(verifyResult(matrix, 2)){
            printf("JOGADOR 2 VENCEU!!!\n");
            break;
        }

    }while(continua == 1);

    
}