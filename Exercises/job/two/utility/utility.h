#ifndef UTILITY_H // include guard

    #define UTILITY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h> 
    #include <ctype.h>
    #include <unistd.h>

    #define SIZE 10
    
    #define SPACE_ 32

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif