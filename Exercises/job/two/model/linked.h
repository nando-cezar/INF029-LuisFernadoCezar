#ifndef LINKED_H // include guard

    #define LINKED_H

    typedef struct list {
        int info;
        struct list *next;
    } List;

    List    *listCreate(void);                      //Use External
    List    *listInsert(List* l, int i);            //Use External
    List    *listInsertEnd(List* l, int v);         //Use External
    List    *listUpdate(List* l, int i);            //Use External
    void    listRetrieve(List* l);                  //Use NULL
    void    listRetrieveAll(List** l);              //Use External
    int     listEmpty(List* l);                     //Use Internal linked
    List    *listDelete(List* l, int v);            //Use Internal linked
    List    *listReallocateValue(List* l, int v);   //Use External
    void    listRelease(List** l);                  //Use Internal linked
    List    *listInsertSortedAsc(List* l, int v);   //Use Internal linked
    List    *listInsertSortedDesc(List* l, int v);  //Use NULL
    void    listSortedAsc(List** l);                //Use External
    
#endif