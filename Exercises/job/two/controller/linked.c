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

List* listUpdate(List* l, int i){ 

    List* new = (List*) malloc(sizeof(List));

    new = l;
    new = listDelete(new, 0);
    new = listInsert(new, i);

    return new;
}

void listRetrieve(List* l){

    List* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d\n", p->info);

}

void listRetrieveAll(List** l){

    List* p;

    for(int i = 0; i < SIZE; i++){
        if(!listEmpty(l[i])){
            printf("( %02d )", i);
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

List* listReallocateValue(List* l, int v){

    List* new = (List*) malloc(sizeof(List));

    new = l;
    new = listDelete(new, v);
    new = listInsert(new, 0);
       
    return new;
}

void listRelease(List** l){

    List** p = l;
    int i = 0;

    while(p[i] != NULL){
        List* t = p[i]->next;
        free(p[i]);
        p[i] = t;
        i++;
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

void listSorted(List** l){

    List* p;
    List* s[SIZE];

    for(int i = 0; i < SIZE; i++) s[i] = listCreate();
    
    for(int i = 0; i < SIZE; i++){
        if(!listEmpty(l[i])){
            for(p = l[i]; p != NULL; p = p->next) 
                s[i] = listInsertSorted(s[i], p->info);
        } 
    }
    
    listRetrieveAll(s);
    listRelease(s);
}