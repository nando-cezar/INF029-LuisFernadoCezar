#ifndef UTILITY_H // include guard
#define UTILITY_H

#include "cxdate.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <ctype.h>

#define MAX_ENR_LEN 255
#define MAX_NAME_LEN 255
#define MAX_CPF_LEN 15
#define MAX_REGISTER_LEN 255

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif