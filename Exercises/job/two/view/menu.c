#include "../utility/utility.h"
#include "../model/linked.h"
#include "menu.h"

void header(){

    system(CLEAR);

    printf("****************************************************\n");
    printf("\t ..:: ESTRUTURA DE DADOS ::..\n");
    printf("****************************************************\n\n");
}

void menu(){

    int option;

    setlocale(LC_ALL, "Portuguese");

    do{
        system(CLEAR);
        printf("\n\n\t ..:: ESTRUTURA DE DADOS ::..\n\n");
        printf("1 - Inserir Elemento;\n");
        printf("2 - Listar os números de todas as estruturas;\n");
        printf("3 - Listar os números ordenados para cada estrutura auxiliar;\n");
        printf("4 - Listar todos os números de forma ordenada;\n\n");
        printf("5 - Excluir um elemento;\n\n");
        printf("6 - Aumentar o tamanho de uma estrutura auxiliar;\n\n");
        printf("7 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1: //insertElement(); break;    
            case 2: //retrieveElements(); break;    
            case 3: //sortElementsInStructure(); break;
            case 4: //sortElements(); break;
            case 5: //deleteElement(); break;
            case 6: //resizeStructure(); break;
            case 7:
                printf("Acesso finalizado!");
                getchar();
                break;
            default:
                printf("Opção inválida!");
                getchar();
                break;
        }
    }while(option != 7);

}