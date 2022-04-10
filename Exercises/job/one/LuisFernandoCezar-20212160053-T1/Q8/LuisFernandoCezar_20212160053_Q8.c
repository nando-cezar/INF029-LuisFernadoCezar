#include "utility/utility.h"
#include "controller/table.h"
#include "view/view.h"

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
    
    instructions();

    // popular tables
    popularTables(1, matrixOne, cleanMatrixOne);
    popularTables(2, matrixTwo, cleanMatrixTwo);

    // fight players
    while(1){

        if(battleField(1, matrixOne, cleanMatrixOne, matrixTwo)){
            printf("\n\n\t\tJOGADOR %d VENCEU!!!", 1);
            getchar();
            break;
        }
            
        if(battleField(2, matrixTwo, cleanMatrixTwo, matrixOne)){
            printf("\n\n\t\tJOGADOR %d VENCEU!!!", 2);
            getchar();
            break;
        }
        
    }

    
}