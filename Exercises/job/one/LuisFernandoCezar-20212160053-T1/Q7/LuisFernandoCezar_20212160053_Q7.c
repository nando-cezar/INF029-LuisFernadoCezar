#include "utility/utility.h"
#include "validation/validate.h"
#include "controller/table.h"
#include "view/view.h"
#include "view/menu.h"

void main(){

    setlocale(LC_ALL, "Portuguese");
    
    char matrix[LINE][COLUMN];

    initializeMatrix(matrix);

    logo();
    
    while(1){

        if(playerMenu(1, 'X', matrix)) break;
        if(playerMenu(2, 'O', matrix)) break;
    
    }
    
}