#ifndef VIEW_H // include guard

    #define VIEW_H

    #include "../utility/utility.h"

    void presentationComplexTable
    (
        int player, 
        char matrix[LINE][COLUMN], 
        char cleanMatrix[LINE][COLUMN], 
        int complex
    );

    
    void popularTables(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN]);
    void instructions();

#endif