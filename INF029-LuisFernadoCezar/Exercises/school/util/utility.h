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

    #define MAX_ENR_LEN 255
    #define MAX_NAME_LEN 255
    #define MAX_CPF_LEN 15
    #define MAX_STUDENTS_DISC 60 
    #define MAX_DISC 5

    #define MESSAGE_ERROR "\nFalha ao abrir o arquivo ou ponteiro!"
    #define STUDENT_PATH "db/student.txt"
    #define TEACHER_PATH "db/teacher.txt"
    #define DISCIPLINE_PATH "db/discipline.txt"

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif