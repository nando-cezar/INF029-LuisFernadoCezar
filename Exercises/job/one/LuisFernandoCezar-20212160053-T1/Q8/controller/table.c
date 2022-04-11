#include "../utility/utility.h"
#include "../controller/table.h"
#include "../view/view.h"

int verifyContainerMatrix(char matrix[LINE][COLUMN], char line, int column, int boatType, int guidance){

    int count = 0;

    for(int indexLine = 0, key = A_; indexLine < LINE; indexLine++, key++){
        if(key == line){
            switch(guidance){
                case 1: 
                    for(int j = 0; j < boatType; j++) 
                        if(indexLine-j < 0)
                            count++;
                break;
                case 2: 
                    for(int j = 0; j < boatType; j++) 
                        if(indexLine+j > LINE-1)
                            count++;
                break;
                case 3: 
                    for(int j = 0; j < boatType; j++)  
                        if(column+j > COLUMN-1)
                            count++;
                break;
                default: 
                    for(int j = 0; j < boatType; j++) 
                        if(column-j < 0)
                            count++;
                break;
            }
        }
    }
    if(count > 0) return 1;
    else return 0;
}

void setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char symbol, int boatType, int guidance){

    for(int indexLine = 0, key = A_; indexLine < LINE; indexLine++, key++){
        if(key == line){
            switch(guidance){
                case 1: 
                    for(int j = 0; j < boatType; j++) 
                        matrix[indexLine-j][column] = symbol;      
                break;
                case 2: 
                    for(int j = 0; j < boatType; j++) 
                        matrix[indexLine+j][column] = symbol;
                break;
                case 3: 
                    for(int j = 0; j < boatType; j++) 
                        matrix[indexLine][column+j] = symbol;
                break;
                default: 
                    for(int j = 0; j < boatType; j++) 
                        matrix[indexLine][column-j] = symbol;
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
        
        if(!verifyValueInMatrix(enemyMatrix, 0, 0, N_, 0, 0, 0)) return 1;

        printf("\n\n.:: JOGADOR %d ::.", player);
        printf("\nInforme a localização para atacar... \n\n");
        printf("\nSelecione posição: ");
        scanf(" %c %d", &line, &column);
        getchar();

        column--;
        //char line, int column, char symbol, int boatType, int guidance, int swap
        if(verifyValueInMatrix(enemyMatrix, line, column, N_, 1, 1, 1)){
            target = 1;
            setValuesMatrix(enemyMatrix, line, column, O_, 1, 1);
            setValuesMatrix(cleanMatrix, line, column, O_, 1, 1);

        }else if(verifyValueInMatrix(enemyMatrix, line, column, SPACE_, 1, 1, 1)){
            setValuesMatrix(enemyMatrix, line, column, X_, 1, 1);
            setValuesMatrix(cleanMatrix, line, column, X_, 1, 1);

        }else if(verifyValueInMatrix(enemyMatrix, line, column, O_, 1, 1, 1)){
            repeated = 1;

        }else if(verifyValueInMatrix(enemyMatrix, line, column, X_, 1, 1, 1)){
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

int verifyValueInMatrix(char matrix[LINE][COLUMN], char line, int column, char symbol, int boatType, int guidance, int swap){

    int count = 0;

    if(swap){
        for(int indexLine = 0, key = A_; indexLine < LINE; indexLine++, key++){
            if(key == line){
                switch(guidance){
                    case 1: 
                        for(int j = 0; j < boatType; j++) 
                            if(matrix[indexLine-j][column] == symbol) count++;      
                    break;
                    case 2: 
                        for(int j = 0; j < boatType; j++) 
                            if(matrix[indexLine+j][column] == symbol) count++;
                    break;
                    case 3: 
                        for(int j = 0; j < boatType; j++) 
                            if(matrix[indexLine][column+j] == symbol) count++;
                    break;
                    default: 
                        for(int j = 0; j < boatType; j++) 
                            if(matrix[indexLine][column-j] == symbol) count++;
                    break;
                }
            }
        }
        if(count == boatType) return 1;
    }else{
        for(int indexLine = 0; indexLine < LINE; indexLine++){
            for(int indexColumn = 0; indexColumn < COLUMN; indexColumn++){
                if(matrix[indexLine][indexColumn] == symbol) return 1;
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