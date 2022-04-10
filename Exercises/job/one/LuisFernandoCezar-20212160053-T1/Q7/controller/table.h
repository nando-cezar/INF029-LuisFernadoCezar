#ifndef TABLE_H // include guard

    #define TABLE_H

    #include "../utility/utility.h"

    void initializeMatrix(char matrix[LINE][COLUMN]);
    int verifyValuesInMatrix(char matrix[LINE][COLUMN], int i, int j);
    int haveSpaceInMatrix(char matrix[LINE][COLUMN]);
    int verifyResult(char matrix[LINE][COLUMN], int player);
    int setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char keyLine, int indexLine, char symbol);

#endif
