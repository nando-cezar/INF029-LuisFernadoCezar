
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <ctype.h>

#define SPACE 32
#define LINE 10
#define COLUMN 10
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

void presentationTable(char matrix[LINE][COLUMN], int player){

    system(CLEAR);

    printf("\nTABELA JOGADOR %d\n\n", player);
    for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
    printf("\n");
    for(int i = 0; i < LINE; i++){
        printf("%c ", _A + i);
        printf("|");
        for(int j = 0; j < COLUMN; j++){
            printf("  %c  |", matrix[i][j]);
            if(j == 9) printf("\n");
        }
    }
}

void presentationComplexTable(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN]){

    system(CLEAR);

    printf("\nTABELA JOGADOR %d\n\n", player);
    for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
    printf("\n");
    for(int i = 0; i < LINE; i++){
        printf("%c ", _A + i);
        printf("|");
        for(int j = 0; j < COLUMN; j++){
            printf("  %c  |", matrix[i][j]);
            if(j == 9) printf("\n");
        }
    }
    printf("\n\n\t\t---------------------------------\n\n");
    for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
    printf("\n");
    for(int i = 0; i < LINE; i++){
        printf("%c ", _A + i);
        printf("|");
        for(int j = 0; j < COLUMN; j++){
            printf("  %c  |", cleanMatrix[i][j]);
            if(j == 9) printf("\n");
        }
    }
}

int verifyValuesInMatrix(char matrix[LINE][COLUMN], int i, int j){

    if(matrix[i][j] == SPACE) return 1;
    else return 0;
}

int verifyResult(char matrix[LINE][COLUMN], int player){

    return 1;
}

int setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char keyLine, int indexLine, char symbol, int boatType, int guidance){

    int flag = 0;

    if(line == keyLine){
        for(int i = 0; i < COLUMN; i++){
            if(column == i+1){
                if(verifyValuesInMatrix(matrix, indexLine, i)){
                    matrix[indexLine][i] = symbol;
                    switch(guidance){
                        case 1: 
                            for(int j = 1; j < boatType; j++) matrix[indexLine-j][i] = symbol;      
                        break;
                        case 2: 
                            for(int j = 1; j < boatType; j++) matrix[indexLine+j][i] = symbol;
                        break;
                        case 3: 
                            for(int j = 1; j < boatType; j++) matrix[indexLine][i+j] = symbol;
                        break;
                        default: 
                            for(int j = 1; j < boatType; j++) matrix[indexLine][i-j] = symbol;
                        break;
                    }
                } 
                else flag = 1;
            }
        }
    }

    return flag;
}

int inputValidate(char line, int column){

    return 1;
}

void popularTables(int player, char matrix[LINE][COLUMN]){

    char line; 
    int column;
    int boatType;
    int guidance;
    int quantity;
    int count;

    printf("\n\n.:: JOGADOR %d ::.", player);
    printf("\nInforme a quantidade de barcos: ");
    scanf("%d", &quantity);
    getchar();

    do{     

        do{
            count = 0;

            presentationTable(matrix, player);
            printf("\nInforme a localização dos barcos... \n\n");
            printf("\nSelecione posição: ");
            scanf(" %c %d", &line, &column);
            getchar();
            printf("\nInforme tipo de barco (1. tamanho 1, 2. tamanho 2, 3. tamanho 3, 4. tamanho 4): ");
            scanf("%d", &boatType);
            getchar();
            printf("\nInforme orientação (1. cima, 2. baixo, 3. direta, 4. esquerda): ");
            scanf("%d", &guidance);
            getchar();

            // setValuesMatrix monitorar se o campo já preenchido
            for(int i = 0, key = _A; i < COLUMN; i++, key++){
                if(setValuesMatrix(matrix, line, column, key, i, 'N', boatType, guidance)) count = 1;
            }

            if(count == 1){
                printf("\nO caminho informado já se encontra preenchido!");
                getchar();
            }
        }while(count == 1);

        quantity--;
    }while(quantity > 0);
}

void battleField(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN], char enemyMatrix[LINE][COLUMN]){

    char line; 
    int column;
    int count1;
    int count2;

    do{
        count1 = 0;
        count2 = 0;

        presentationComplexTable(player, matrix, cleanMatrix);
        printf("\n\n.:: JOGADOR %d ::.", player);

        printf("\nInforme a localização para atacar... \n\n");
        printf("\nSelecione posição: ");
        scanf(" %c %d", &line, &column);
        getchar();

        // setValuesMatrix monitorar se o campo já preenchido
        for(int i = 0, key = _A; i < LINE; i++, key++){
            if(line == key){
                if(!verifyValuesInMatrix(enemyMatrix, i, column)) count1 = 1;
            }
            if(count1 == 1){
                if(setValuesMatrix(cleanMatrix, line, column, key, i, 'O', 1, 1)) count2 = 1;
            }else{
                if(setValuesMatrix(cleanMatrix, line, column, key, i, 'X', 1, 1)) count2 = 1;
            }
        }

        if(count1 == 1){
            printf("\nAcertou, ataque novamente!");
            getchar();
        }else if(count2 == 1){
            printf("\nO caminho informado já se encontra preenchido!");
            getchar();
        }else if(count1 == 0){
            printf("\nErrou, vez do seu inimigo!");
            getchar();
        }
    }while(count1 == 1 || count2 == 1);
}

void main(){

    setlocale(LC_ALL, "Portuguese");
    
    char matrixOne[LINE][COLUMN];
    char matrixTwo[LINE][COLUMN];
    char cleanMatrixOne[LINE][COLUMN];
    char cleanMatrixTwo[LINE][COLUMN];

    initializeMatrix(matrixOne);
    initializeMatrix(matrixTwo);
    initializeMatrix(cleanMatrixOne);
    initializeMatrix(cleanMatrixTwo);

    system(CLEAR);
    printf("\tInstruções \n\nDeve ter pelo menos 1 barco de tamanho 4, 1 de tamanho 3, 3 barcos de tamanho 1."); 
    printf("\nOs demais barcos, se existirem devem ser obrigatoriamente de tamanho 2.");
    printf("\nDesta forma, o número mínimo de barco é: 5 barcos.");

    // popular tables
    popularTables(1, matrixOne);
    popularTables(2, matrixTwo);

    // fight players
    while(1){

        battleField(1, matrixOne, cleanMatrixOne, matrixTwo);
        battleField(2, matrixTwo, cleanMatrixTwo, matrixOne);
        
    }

    
}