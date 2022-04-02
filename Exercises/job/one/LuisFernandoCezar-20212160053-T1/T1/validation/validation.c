#include "../util/utility.h"
#include "validation.h"

int validateDay(int day, int month, int year);

int validateCharOnlyNumber(char c){

    if(isalpha(c) || ispunct(c)) return 0;

    return 1;
}

int validateDate(char* date,  long* dateFormated){
    
    //long* dateFormated = calloc(3, sizeof(long));

    if (strstr(date, BAR) != NULL) return 0;

    for (int i = 0; i < strlen(date); i++){
        if (date[i] != '/' && !validateCharOnlyNumber(date[i])) 
            return 0;
    }

    convertStringInInteger(date, dateFormated);

    if(dateFormated[1] <= 0 || dateFormated[1] > 12 ) return 0;
    else if(dateFormated[0] <= 0 || dateFormated[0] > 31) return 0;
    else if(validateDay(dateFormated[0], dateFormated[1], dateFormated[2])) return 0;
    else return 1;
}

void convertStringInInteger(char* date, long* dateFormated){

    //long* dateFormated = calloc(3, sizeof(long));
    const char delimiter[2] = "/";
    char* token = strtok(date, delimiter);

    for(int i = 0; token != NULL; i++){
        dateFormated[i] = strtol(token, NULL, 10);
        token = strtok(NULL, delimiter);
    }

    //return dateFormated;
}

int validateDay(int day, int month, int year){

    int isLeapYear;

    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) isLeapYear = 1;
    else isLeapYear = 0;

    if(
        month == 1 || 
        month == 3 ||
        month == 5 || 
        month == 7 ||
        month == 8 || 
        month == 10||
        month == 12
    ){
        if(day > 31) return 1;
        else return 0;
         
    }else if(month == 2 && isLeapYear ){
        if(day > 29) return 1;
        else return 0;          
    }else if(month == 2){
        if(day > 28) return 1;
        else return 0;
    }else{
        if(day > 30) return 1;
        else return 0;
    }

}



