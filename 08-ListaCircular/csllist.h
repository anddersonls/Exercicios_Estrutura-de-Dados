/*------------------------------------------------
csllist.h
Arquivo com a definição das funções do TAD Lista
Circular Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#ifndef __CSLLIST_H_
#define __CSLLIST_H_

typedef struct _slnode_
{
    struct _slnode_ *next;
    void *data;
} SLNode;

typedef struct _sllist_
{
    SLNode *first;
    SLNode *cur;
} SLList;

SLList *csllCreate();
int csllDestroy(SLList *l);
int csllInsertFirst(SLList *l, void *data);
int csllInsertLast(SLList *l, void *data);
int csllInsertAfterSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *));
void *csllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));
void *csllGetFirst(SLList *l);
void *csllGetNext(SLList *l);

#endif