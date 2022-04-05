
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <ctype.h>

#define SPACE 32
#define LINE 3
#define COLUMN 3
#define _A 65

#if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
#endif

void initializeMatrix(char matrix[LINE][COLUMN]){

    for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN; j++){
            matrix[i][j] = SPACE;
        }
    }

}

void presentationTable(char matrix[LINE][COLUMN]){

    system(CLEAR);

    for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
    printf("\n");
    for(int i = 0; i < LINE; i++){
        printf("%c ", _A + i);
        printf("|");
        for(int j = 0; j < COLUMN; j++){
            printf("  %c  |", matrix[i][j]);
            if(j == 2) printf("\n");
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

int inputValidate(char line, int column){

    if(
        (line == 'a' || line == 'b' || line == 'c')
        && 
        (column == 1 || column == 2 || column == 3)
    ) return 1;
    else return 0;
}

int playerMenu(int player, char symbol, char matrix[LINE][COLUMN]){

    
    char line; 
    int column = 0;
    int count;

    do{
        count = 0;

        presentationTable(matrix);

        do{
            printf("\nInstruções: Informe linha e coluna simultaneamente!");
            printf("\nJogador %d: ", player);
            scanf(" %c %d", &line, &column);
            getchar();

            line = tolower(line);

            if(!inputValidate(line, column)){
                printf("Comando inválido!\n");
                getchar();
            }

        }while(!inputValidate(line, column));

        
        
        if(line == 'a'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 0, 0)) matrix[0][0] = symbol;
                else count = 1;
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 0, 1)) matrix[0][1] = symbol;
                else count = 1;
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 0, 2)) matrix[0][2] = symbol;
                else count = 1;
            }
        }else if(line == 'b'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 1, 0)) matrix[1][0] = symbol;
                else count = 1;
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 1, 1)) matrix[1][1] = symbol;
                else count = 1;
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 1, 2)) matrix[1][2] = symbol;
                else count = 1;
            }
        }else if(line == 'c'){
            if(column == 1){
                if(verifyValuesInMatrix(matrix, 2, 0)) matrix[2][0] = symbol;
                else count = 1;
            }else if(column == 2){
                if(verifyValuesInMatrix(matrix, 2, 1)) matrix[2][1] = symbol;
                else count = 1;
            }else if(column == 3){
                if(verifyValuesInMatrix(matrix, 2, 2)) matrix[2][2] = symbol;
                else count = 1;
            }
        }

        if(verifyResult(matrix, player)){
            presentationTable(matrix);
            printf("JOGADOR %d VENCEU!\n", player);
            return 1;

        }else if(count == 1){
            printf("O caminho informado já se encontra preenchido!");
            getchar();

        }else if(!haveSpaceInMatrix(matrix)){
            printf("EMPATE!\n");
            return 1;
        }
    
    }while(count == 1);

    return 0;
}

void main(){

    setlocale(LC_ALL, "Portuguese");
    
    char matrix[LINE][COLUMN];

    initializeMatrix(matrix);

    while(1){

        if(playerMenu(1, 'X', matrix)) break;
        if(playerMenu(2, 'O', matrix)) break;
    
    }

    
}