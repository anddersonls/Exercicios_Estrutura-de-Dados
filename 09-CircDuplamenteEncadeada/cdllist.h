/*------------------------------------------------
cdllist.h
Arquivo com a definição das funções do TAD Lista
Circular Duplamente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#ifndef __CDLLIST_H_
#define __CDLLIST_H_

typedef struct _dlnode_
{
    struct _dlnode_ *next,
        *prev;
    void *data;
} DLNode;

typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;
} DLList;

DLList *cdllCreate();
int cdllDestroy(DLList *l);
int cdllInsertFirst(DLList *l, void *data);
int cdllInsertLast(DLList *l, void *data);
int cdllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
void *cdllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));
void *cdllGetFirst(DLList *l);
void *cdllGetNext(DLList *l);

#endif