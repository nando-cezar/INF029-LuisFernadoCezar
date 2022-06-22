#include <stdio.h>
#include "questions.h"

int input(){

    int value;

    printf("Informe valor para realizar operação: ");
    scanf("%d", &value);

    return value;
}
int main(){

    int option;

    do{
        printf("BEM-VINDO, selecione a questão desejada (1 a 16): ");
        scanf("%d", &option);
        getchar();

        switch (option){
            case 1:  printf("Resultado = %d;\n", fatorial              (input())); break;
            case 2:  printf("Resultado = %d;\n", fibonacci             (input())); break;
            case 3:  printf("Resultado = %d;\n", inverteSig            (input())); break;
            case 4:  printf("Resultado = %d;\n", maxDivCom             (input(), input()));    break;
            case 5:  printf("Resultado = %d;\n", potenciakn            (input(), input()));    break;
            case 6:  printf("Resultado = %d;\n", soma1aN               (input())); break;
            case 7:  printf("Resultado = %d;\n", multRec               (input(), input()));    break;
            case 8:  printf("Resultado = %d;\n", fatDuplo              (input())); break;
            case 9:  printf("Resultado = %d;\n", fatQuadruplo          (input())); break;
            case 10: printf("Resultado = %d;\n", superFat              (input())); break;
            case 11: printf("Resultado = %d;\n", tribonacci            (input())); break;
            case 12: printf("Resultado = %d;\n", tetranacci            (input())); break;
            case 13: printf("Resultado = %d;\n", padovan               (input())); break;
            case 14: printf("Resultado = %d;\n", pell                  (input())); break;
            case 15: printf("Resultado = %d;\n", catalan               (input())); break;
            case 16: printf("Resultado = %d;\n", converteParaBinario   (input())); break;
            default: option = 0;                                    break;
        }

        getchar();

    }while(option != 0);
    
    printf("Programa finalizado!\n");

    return 0;
}