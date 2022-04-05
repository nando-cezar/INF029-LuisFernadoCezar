
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

void presentationTable(char matrix[LINE][COLUMN]){

    system(CLEAR);

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

    return 1;
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

    return 1;
}

int playerMenu(int player, char matrix[LINE][COLUMN]){

    char line; 
    int column;
    int boatType;
    int guidance;
    int quantity;
    int count = 0;

    printf("\nJogador %d ", player);

    printf("\nInforme a quantidade de barcos: ");
    scanf("%d", &quantity);
    getchar();

    do{
        quantity--;

        presentationTable(matrix);
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

        if(setValuesMatrix(matrix, line, column, 'A', 0, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'B', 1, 'N')){} 
        else if(setValuesMatrix(matrix, line, column, 'C', 2, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'D', 3, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'E', 4, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'F', 5, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'G', 6, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'H', 7, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'I', 8, 'N')){}
        else if(setValuesMatrix(matrix, line, column, 'J', 9, 'N')){}
            

        /*if(verifyResult(matrix, player)){
            presentationTable(matrix);
            printf("JOGADOR %d VENCEU!\n", player);
            return 1;

        }else if(count == 1){
            printf("O caminho informado já se encontra preenchido!");
            getchar();

        }else if(!haveSpaceInMatrix(matrix)){
            printf("EMPATE!\n");
            return 1;
        }*/

    }while(quantity > 0);
        
    return 0;
}

void main(){

    setlocale(LC_ALL, "Portuguese");
    
    char matrixOne[LINE][COLUMN];
    char matrixTwo[LINE][COLUMN];

    initializeMatrix(matrixOne);
    initializeMatrix(matrixTwo);

    system(CLEAR);
    printf("\tInstruções \n\nDeve ter pelo menos 1 barco de tamanho 4, 1 de tamanho 3, 3 barcos de tamanho 1."); 
    printf("\nOs demais barcos, se existirem devem ser obrigatoriamente de tamanho 2.");
    printf("\nDesta forma, o número mínimo de barco é: 5 barcos.");

    while(1){

        if(playerMenu(1, matrixOne)) break;
        if(playerMenu(2, matrixTwo)) break;
    
    }

    
}