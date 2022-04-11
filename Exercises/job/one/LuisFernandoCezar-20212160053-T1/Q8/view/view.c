#include "../utility/utility.h"
#include "../controller/table.h"
#include "view.h"

void presentationComplexTable(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN], int complex){

    system(CLEAR);

    printf("\n\n\t\t----------------------------- TABELA JOGADOR %d\n\n", player);
    for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
    printf("\n");
    for(int i = 0; i < LINE; i++){
        printf("%c ", A_ + i);
        printf("|");
        for(int j = 0; j < COLUMN; j++){
            printf("  %c  |", matrix[i][j]);
            if(j == 9) printf("\n");
        }
    }

    if(complex == 1){
        printf("\n\n\t\t------------------------------- TABELA RASCUNHO\n\n");
        for(int i = 0; i < COLUMN; i++) printf("     %d", i+1);
        printf("\n");
        for(int i = 0; i < LINE; i++){
            printf("%c ", A_ + i);
            printf("|");
            for(int j = 0; j < COLUMN; j++){
                printf("  %c  |", cleanMatrix[i][j]);
                if(j == 9) printf("\n");
            }
        }
    }
    
}

void popularTables(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN]){

    char line; 
    int column;
    int boatType;
    int guidance;
    int quantity = QUANTITYBOAT;
    int repeated, limited;

    do{      

        do{
            repeated = 0;
            limited = 0;

            presentationComplexTable(player, matrix, cleanMatrix, 0);
            printf("\n\n.:: JOGADOR %d ::.", player);

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

            column--;
            
            if(verifyContainerMatrix(matrix, line, column, boatType, guidance))
                limited = 1;
            else{
                if(verifyValueInMatrix(matrix, line, column, SPACE_, boatType, guidance, 1)) setValuesMatrix(matrix, line, column, N_, boatType, guidance);
                else repeated = 1;
            }
            

            if(repeated == 1){
                printf("\nO caminho informado já se encontra preenchido!");
                getchar();
            }else if(limited == 1){
                printf("\nO caminho informado ultrapassa o limite do tabuleiro!");
                getchar();
            }
            
            
        }while(repeated == 1 ||  limited == 1);

        quantity--;
    }while(quantity > 0);
}

void instructions(){

    system(CLEAR);
    
    printf(".:: Instruções ::. \n\nDeve ter pelo menos 1 barco de tamanho 4, 1 de tamanho 3, 3 barcos de tamanho 1."); 
    printf("\nOs demais barcos, se existirem devem ser obrigatoriamente de tamanho 2.");
    printf("\nDesta forma, o número mínimo de barco é: 5 barcos.");
    getchar();

}