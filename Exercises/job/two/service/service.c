#include "../utility/utility.h"
#include "../model/linked.h"

void resizing(List* structural[SIZE], int position, int size, int flag);

void insertElement(List* structural[SIZE]){

    int position;
    int value;
    int size;
    
    printf("\nInforme qual posição deseja inserir: ");
    scanf("%d", &position);
    getchar();
 
    if(!listEmpty(structural[position])){
        printf("\nInforme valor: ");
        scanf("%d", &value);
        getchar(); 

        structural[position] = listUpdate(structural[position], value);
    }else{
        printf("\nInforme tamanho da estrutura auxiliar: ");
        scanf("%d", &size);
        getchar();

        resizing(structural, position, size, 1);
    }

    getchar();
}

void retrieveElements(List* structural[SIZE]){
    listRetrieveAll(structural);
    getchar(); getchar();
}

void sortElementsInStructure(List* structural[SIZE]){

}

void sortElements(List* structural[SIZE]){
    listSortedAsc(structural);
    getchar(); getchar();
}

void deleteElement(List* structural[SIZE]){

    int position;
    int value;

    listRetrieveAll(structural);

    printf("\nInforme qual posição deseja excluir: ");
    scanf("%d%*i", &position);
    getchar();

    printf("\nInforme valor: ");
    scanf("%d%*i", &value);
    getchar();

    structural[position] = listReallocateValue(structural[position], value);

    retrieveElements(structural);
}

void resizeStructure(List* structural[SIZE]){

    int position;
    int size;

    printf("\nInforme qual posição deseja inserir: ");
    scanf("%d%*i", &position);
    getchar();

    printf("\nInforme tamanho da estrutura auxiliar: ");
    scanf("%d%*i", &size);
    getchar();

    resizing(structural, position, size, 0);

}

void resizing(List* structural[SIZE], int position, int size, int flag){
    
    if(flag)
        for(int i = 0; i < size; i++) 
            structural[position] = listInsert(structural[position], 0);
    else
        for(int i = 0; i < size; i++) 
            structural[position] = listInsertEnd(structural[position], 0);
}


