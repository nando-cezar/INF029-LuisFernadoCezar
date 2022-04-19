#include <stdio.h>
#include <stdlib.h>
#include "utility/utility.h"
#include "model/linked.h"
#include "view/menu.h"

int main(){

    //menu();

    /* Modelo inicial */
    List* l[SIZE];

    int position;
    int v;

    for(int i = 0; i < SIZE; i++) l[i] = list_create();
    
    /* Modulo de inserção */
    for(int r = 0; r < 3; r++){

        printf("\nInforme qual posição deseja inserir: ");
        scanf("%d", &position);

        printf("\nInforme valor: ");
        scanf("%d", &v);

        l[position] = list_insert(l[position], v);

        //list_retrieve(l[position]);
        list_retrieveAll(l);
    }

    /* Modulo de exclusão */
    for(int e = 0; e < 3; e++){

        printf("\nInforme qual posição deseja excluir: ");
        scanf("%d", &position);

        printf("\nInforme valor: ");
        scanf("%d", &v);

        list_delete(l[position], v);

        list_retrieveAll(l);
    }

    return 0;
}