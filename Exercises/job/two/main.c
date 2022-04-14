#include <stdio.h>
#include <stdlib.h>
#include "model/linked.h"


int main(){

    List* l;
    l = list_create();
    l = list_insert(l, 23);
    l = list_insert(l, 45);

    list_update(&l, 23);

    return 0;
}