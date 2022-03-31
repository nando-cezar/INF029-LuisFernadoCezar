#ifndef UTILITY_H // include guard

    #define UTILITY_H

    #include "cxdate.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <locale.h>
    #include <ctype.h>
    #include <time.h>

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif