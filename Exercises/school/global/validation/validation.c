#include "../../util/utility.h"
#include "validation.h"

int validateDay(int day, int month, int year);

int validateCPF(char CPF[]){ 

    if(strlen(CPF)-1 == 13) return 1;
    else return 0;
}

int validateName(char name[]){

    for(int i = 0;  i < strlen(name);  i++){
        if(isdigit(name[i])) return 0;
    }

    return 1;
};

int validateEnrollment(char enrollment[]){

    for(int i = 0 ; i < strlen(enrollment)-1; i++){
        if(isalpha(enrollment[i])) return 0;
    }

    return 1;
}

int validateGender(char gender){

    if(
        gender == 'm' || 
        gender == 'M' ||
        gender == 'f' || 
        gender == 'F' 
    ){
        return 1;
    }
    return 0;
}

int validateSemester(int semester){

    if(semester <= 0) return 0;
    else return 1;
}

int validateDate(Date date){
   
    if(date.year <= 0 ) return 0;
    else if(date.month <= 0 || date.month > 12 ) return 0;
    else if(date.day <= 0 || date.day > 31) return 0;
    else if(validateDay( date.day, date.month, date.year)) return 0;
    else return 1;
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

int validateAlternative(char alternative){

    if(
        alternative == 's' || 
        alternative == 'S' ||
        alternative == 'n' || 
        alternative == 'N'
    ){
        return 1;
    }
    return 0;
}
