#ifndef TABLE_H // include guard

    #define TABLE_H
    
    #include "../utility/utility.h"

    void setValuesMatrix(char matrix[LINE][COLUMN], char line, int column, char symbol, int boatType, int guidance);
    int verifyValueInMatrix(char matrix[LINE][COLUMN], int c, char line, int column, int swap);
    int battleField(int player, char matrix[LINE][COLUMN], char cleanMatrix[LINE][COLUMN], char enemyMatrix[LINE][COLUMN]);
    void initializeMatrix(char matrix[LINE][COLUMN]);

#endif