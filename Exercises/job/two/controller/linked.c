#include <stdio.h>
#include <stdlib.h>
#include "../utility/utility.h"
#include "../model/linked.h"


List* list_create(void){ return NULL; }

List* list_insert(List* l, int i){ 

    List* new = (List*) malloc(sizeof(List));
    new->info = i;
    new->next = l;
    return new;
}

void list_update(List** l, int i){ 

    List* new = (List*) malloc(sizeof(List));
    new->info = i;
    new->next = *l;
    *l = new;
}

void list_retrieve(List* l){

    List* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d\n", p->info);

}

void list_retrieveAll(List** l){

    List* p;

    for(int i = 0; i < SIZE; i++){  
        for(p = l[i]; p != NULL; p = p->next) printf("index = %d | info = %d\n", i, p->info);
    }
        

}

int list_empty(List* l){ return (l == NULL); }

List* list_search(List* l, int v){
    List* p;
    for(p = l; p != NULL; p = p->next){
        if(p->info == v) return p;
    }
    return NULL;
}

List* list_delete(List* l, int v){

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

void list_release(List *l){

    List* p = l;

    while(p != NULL){
        List* t = p->next;
        free(p);
        p = t;
    }
}

List* list_insert_sorted(List* l, int v){

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