#include "../utility/utility.h"
#include "../model/service.h"
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
    List* structural[SIZE];

    setlocale(LC_ALL, "Portuguese");

    for(int i = 0; i < SIZE; i++) structural[i] = listCreate();

    do{
        system(CLEAR);
        printf("\n\n\t ..:: ESTRUTURA DE DADOS ::..\n\n");
        printf("1 - Inserir Elemento;\n");
        printf("2 - Listar os números de todas as estruturas;\n");
        printf("3 - Listar os números ordenados para cada estrutura auxiliar;\n");
        printf("4 - Listar todos os números de forma ordenada;\n");
        printf("5 - Excluir um elemento;\n");
        printf("6 - Aumentar o tamanho de uma estrutura auxiliar;\n");
        printf("7 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1: insertElement(structural); break;    
            case 2: retrieveElements(structural); break;    
            case 3: //sortElementsInStructure(structural); break;
            case 4: sortElements(structural); break;
            case 5: deleteElement(structural); break;
            case 6: resizeStructure(structural); break;
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


