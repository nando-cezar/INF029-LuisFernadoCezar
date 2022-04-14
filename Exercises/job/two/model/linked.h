#ifndef LINKED_H // include guard

    #define LINKED_H

    struct list {
        int info;
        struct list *next;
    };
    typedef struct list List;

    List* list_create(void);
    List* list_insert(List* l, int i);
    void list_update(List** l, int i);
    void list_retrieve(List* l);
    int list_empty(List* l);
    List* list_delete(List* l, int v);
    void list_release(List *l);
    List* list_insert_sorted(List* l, int v);
    


#endif