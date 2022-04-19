#ifndef UTILITY_H // include guard

    #define UTILITY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h> 
    #include <ctype.h>
    #include <unistd.h>
    
    #define SPACE 32
    #define LINE 3
    #define COLUMN 3
    #define _A 65

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif