#include "../utility/utility.h"
#include "../controller/table.h"
#include "../validation/validate.h"
#include "view.h"

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

            line = toupper(line);

            if(!inputValidate(line, column)){
                printf("Comando inválido!\n");
                getchar();
            }

        }while(!inputValidate(line, column));

        for(int i = 0, key = _A; i < COLUMN; i++, key++){
            if(setValuesMatrix(matrix, line, column, key, i, symbol)) count = 1;
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