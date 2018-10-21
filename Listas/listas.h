#ifndef LISTAS_H
#define LISTAS_H
#define TRUE 1
#define FALSE 0
typedef struct _dlnode_
{
    void *data;
    struct _dlnode_ *next;
    struct _dlnode_ *prev;
} dlnode;

typedef struct _dll_
{
    dlnode *first;

} dllist;

dllist * dllcreate();
int dllinsertFirst(dllist *l, void *data);
int dllinsertLast(dllist *l, void *data) ;
int dllremovespec (dllist *l, void *key,int (*cmp)(void*,void*));
int dllquery (dllist *l,void *key,int (*cmp) (void*,void*));
int comp(void *a, void *b);
dllist destroy( dllist *l);
#endif
