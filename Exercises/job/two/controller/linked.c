#include <stdio.h>
#include <stdlib.h>
#include "../utility/utility.h"
#include "../model/linked.h"


List* listCreate(void){ return NULL; }

List* listInsert(List* l, int i){ 

    List* new = (List*) malloc(sizeof(List));
    new->info = i;
    new->next = l;
    return new;
}

void listUpdate(List** l, int i){ 

    List* new = (List*) malloc(sizeof(List));
    new->info = i;
    new->next = *l;
    *l = new;
}

void listRetrieve(List* l){

    List* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d\n", p->info);

}

void listRetrieveAll(List** l){

    List* p;

    for(int i = 0; i < SIZE; i++){
        if(!listEmpty(l[i])){
            printf("[ %02d ]", i);
            for(p = l[i]; p != NULL; p = p->next) printf("| %02d |", p->info); 
            printf("\n");
        } 

    }
}

int listEmpty(List* l){ return (l == NULL); }

List* listSearch(List* l, int v){
    List* p;
    for(p = l; p != NULL; p = p->next){
        if(p->info == v) return p;
    }
    return NULL;
}

List* listDelete(List* l, int v){

    List* ant = NULL;
    List* p = l;

    while(p != NULL && p->info != v){
        ant = p;
        p = p->next;
    }

    if(p == NULL) return l;

    if(ant == NULL) l = p->next;
    else ant->next = p->next;

    free(p);
    return l;
}

void listRelease(List *l){

    List* p = l;

    while(p != NULL){
        List* t = p->next;
        free(p);
        p = t;
    }
}

List* listInsertSorted(List* l, int v){

    List* new;
    List* ant = NULL;
    List* p = l;


    while(p != NULL && p->info < v){
        ant = p;
        p = p->next;
    }

    new = (List*) malloc(sizeof(List));
    new->info = v;

    if(ant == NULL){

        new->next = l;
        l = new;

    }else{
        new->next = ant->next;
        ant->next = new;
    }
    return l;
}