#ifndef LINKED_H // include guard

    #define LINKED_H

    typedef struct list {
        int info;
        struct list *next;
    } List;

    List    *listCreate(void);
    List    *listInsert(List* l, int i);
    List    *listUpdate(List* l, int i);
    void    listRetrieve(List* l);
    void    listRetrieveAll(List** l);
    int     listEmpty(List* l);
    List    *listDelete(List* l, int v);
    List    *listReallocateValue(List* l, int v);
    void    listRelease(List** l);
    List    *listInsertSortedAsc(List* l, int v);
    List    *listInsertSortedDesc(List* l, int v);
    void    listSortedAsc(List** l);
    



#endif