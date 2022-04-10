#include "validate.h"

int inputValidate(char line, int column){

    if(
        (line == 'A' || line == 'B' || line == 'C')
        && 
        (column == 1 || column == 2 || column == 3)
    ) return 1;
    
    else return 0;

}