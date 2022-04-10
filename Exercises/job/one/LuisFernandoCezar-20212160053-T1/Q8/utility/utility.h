#ifndef UTILITY_H // include guard

    #define UTILITY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h> 
    #include <ctype.h>

    #define SPACE_ 32
    #define A_ 65
    #define N_ 78
    #define O_ 79
    #define X_ 88

    #define LINE 10
    #define COLUMN 10
    #define QUANTITYBOAT 2

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif