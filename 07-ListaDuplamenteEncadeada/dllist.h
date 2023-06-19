/*------------------------------------------------
dllist.h
Arquivo com a definição das funções do TAD Lista
Duplamente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#ifndef __DLLIST_H_
#define __DLLIST_H_

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

DLList *dllCreate();
int dllDestroy(DLList *l);
int dllDestroyNotEmpty(DLList *l, int (*myfree)(void *));
int dllInsertAsFirst(DLList *l, void *data);
int dllInsertAsLast(DLList *l, void *data);
int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));

#endif