#include <stdio.h>
#include "questions.h"

int main(){

    int question;

    do{
        system("clear");
        system("cls");
        printf("BEM-VINDO, selecione a questão desejada (1 a 16): ");
        scanf("%d", &quesion);

        switch (option){
            case 1:  fatorial(5);           break;
            case 2:  fibonacci(5);          break;
            case 3:  inverteSig(5);         break;
            case 4:  maxDivCom(5, 5);       break;
            case 5:  potenciakn(5, 5);      break;
            case 6:  soma1aN(5);            break;
            case 7:  multRec(5);            break;
            case 8:  fatDuplo(5);           break;
            case 9:  fatQuadruplo(5);       break;
            case 10: superFat(5);           break;
            case 11: tribonacci(5);         break;
            case 12: tetranacci(5);         break;
            case 13: padovan(5);            break;
            case 14: pell(5);               break;
            case 15: catalan(5);            break;
            case 16: converteParaBinario(5);break;
            default: question = 0;          break;
        }

    }while(question != 0);
    
    printf("Programa finalizado!\n");

    return 0;
}