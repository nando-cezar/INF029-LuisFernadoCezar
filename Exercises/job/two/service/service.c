#include "../utility/utility.h"
#include "../model/linked.h"

void insertElement(List* structural[SIZE]){

    int position;
    int value;
    int size;
    
    printf("\nInforme qual posição deseja inserir: ");
    scanf("%d", &position);
    getchar();

    printf("\nInforme valor: ");
    scanf("%d", &value);
    getchar();

    structural[position] = listInsert(structural[position], value);
    getchar();
}

void retrieveElements(List* structural[SIZE]){
    listRetrieveAll(structural);
    getchar(); getchar();
}

void sortElementsInStructure(){

}

void sortElements(List* structural[SIZE]){
    listSorted(structural);
    getchar(); getchar();
}

void deleteElement(List* structural[SIZE]){

    int position;
    int value;

    listRetrieveAll(structural);

    printf("\nInforme qual posição deseja excluir: ");
    scanf("%d", &position);
    getchar();

    printf("\nInforme valor: ");
    scanf("%d", &value);
    getchar();

    structural[position] = listDelete(structural[position], value);

    retrieveElements(structural);
    getchar();
}

void resizeStructure(){

}


