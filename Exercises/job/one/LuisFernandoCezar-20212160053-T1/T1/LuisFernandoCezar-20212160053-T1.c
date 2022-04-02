#include "util/utility.h"
#include "function/function.h"
#include "validation/validation.h"

void question1();
void question2();

void main(){

    question1();
    question2();
    
}

void question1(){

    /*
        /	47	0057	0x2f
        0	48	0060	0x30
        1	49	0061	0x31
        2	50	0062	0x32
        3	51	0063	0x33
        4	52	0064	0x34
        5	53	0065	0x35
        6	54	0066	0x36
        7	55	0067	0x37
        8	56	0070	0x38
        9	57	0071	0x39
    */
    
    char date[MAX_DATE];
    long dateFormated[3];

    printf("Informe data no formato: ");
    fgets(date, MAX_DATE, stdin);
    removeBreakLine(date);
    getchar();

    if(validateDate(date, dateFormated))
        printf("Válido!\n");
    else
        printf("Não é válido!\n");
}

void question2(){

    char date[MAX_DATE];
    long dateFormated[3];

    printf("Informe data no formato: ");
    fgets(date, MAX_DATE, stdin);
    removeBreakLine(date);
    getchar();

    if(validateDate(date, dateFormated)){
        printf("Válido!\n");
        compareDate(dateFormated);
    }else
        printf("Não é válido!\n");
}