#include "../utility/utility.h"
#include "../controller/table.h"
#include "../view/view.h"


void setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char symbol, int boatType, int guidance){

    for(int indexLine = 0, key = A_; indexLine < LINE; indexLine++, key++){
        if(key == line){
            matrix[indexLine][column] = symbol;
            switch(guidance){
                case 1: 
                    for(int indexColumn = 1; indexColumn < boatType; indexColumn++) 
                        matrix[indexLine-indexColumn][column] = symbol;      
                break;
                case 2: 
                    for(int indexColumn = 1; indexColumn < boatType; indexColumn++) 
                        matrix[indexLine+indexColumn][column] = symbol;
                break;
                case 3: 
                    for(int indexColumn = 1; indexColumn < boatType; indexColumn++) 
                        matrix[indexLine][column+indexColumn] = symbol;
                break;
                default: 
                    for(int indexColumn = 1; indexColumn < boatType; indexColumn++) 
                        matrix[indexLine][column-indexColumn] = symbol;
                break;
            }
        }
    }
}

int battleField(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN], char enemyMatrix[LINE][COLUMN]){

    char line; 
    int column;
    int target;
    int repeated;

    do{
        target = 0;
        repeated = 0;

        presentationComplexTable(player, matrix, cleanMatrix, 1);

        if(!verifyValueInMatrix(enemyMatrix, N_, 0, 0, 0)) return 1;

        printf("\n\n.:: JOGADOR %d ::.", player);
        printf("\nInforme a localização para atacar... \n\n");
        printf("\nSelecione posição: ");
        scanf(" %c %d", &line, &column);
        getchar();

        column--;

        if(verifyValueInMatrix(enemyMatrix, N_, line, column, 1)){
            target = 1;
            setValuesMatrix(enemyMatrix, line, column, O_, 1, 1);
            setValuesMatrix(cleanMatrix, line, column, O_, 1, 1);

        }else if(verifyValueInMatrix(enemyMatrix, SPACE_, line, column, 1)){
            setValuesMatrix(enemyMatrix, line, column, X_, 1, 1);
            setValuesMatrix(cleanMatrix, line, column, X_, 1, 1);

        }else if(verifyValueInMatrix(enemyMatrix, O_, line, column, 1)){
            repeated = 1;

        }else if(verifyValueInMatrix(enemyMatrix, X_, line, column, 1)){
            repeated = 1;
        }
    
        if(repeated == 1){
            printf("\nO caminho informado já se encontra preenchido!");
            getchar();

        }else if(target == 0){
            printf("\nErrou, vez do seu inimigo!");
            getchar();

        }else if(target == 1){
            printf("\nAcertou, ataque novamente!");
            getchar();
        }

    }while(target == 1 || repeated == 1);


    return 0;
}

int verifyValueInMatrix(char matrix[LINE][COLUMN], int c, char line, int column, int swap){

    if(swap){
        for(int i = 0, key = A_; i < LINE; i++, key++){
            if(key == line){
                if(matrix[i][column] == c) return 1;
            }
        }
    }else{
        for(int i = 0; i < LINE; i++){
            for(int j = 0; j < COLUMN; j++){
                if(matrix[i][j] == c) return 1;
            }
        }
    }
    
    return 0;
}

void initializeMatrix(char matrix[LINE][COLUMN]){

    for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN; j++){
            matrix[i][j] = SPACE_;
        }
    }

}