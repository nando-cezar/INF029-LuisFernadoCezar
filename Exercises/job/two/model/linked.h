#ifndef LINKED_H // include guard

    #define LINKED_H

    typedef struct list {
        int info;
        struct list *next;
    } List;

    List    *listCreate(void);
    List    *listInsert(List* l, int i);
    void    listUpdate(List** l, int i);
    void    listRetrieve(List* l);
    void    listRetrieveAll(List** l);
    int     listEmpty(List* l);
    List    *listDelete(List* l, int v);
    void    listRelease(List *l);
    List    *listInsertSorted(List* l, int v);



#endif