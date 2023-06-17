/*------------------------------------------------
sllist.h
Arquivo com a definição das funções do TAD Lista
Simplesmente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#ifndef __SLNODE_H_
#define __SLLIST_H_

typedef struct _slnode_
{
    void *data;
    struct _slnode_ *next;
} SLNode;

typedef struct _sllist_
{
    SLNode *first;
} SLList;

SLList *sllCreate(void);
int sllDestroy(SLList *l);
int sllIsEmpty(SLList *l);
int sllNNodes(SLList *l);
int sllInsertFirst(SLList *l, void *data);
int sllInsertLast(SLList *l, void *data);
int sllInserftAfterSpecQuery(SLList *l, void *key, void *data, int (*cmp)(void *, void *));
int sllInsertBefSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *));
void *sllRemoveFirst(SLList *l);
void *sllRemoveLast(SLList *l);
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));
void *sllGetFirst(SLList *l);
void *sllGetLast(SLList *l);

#endif