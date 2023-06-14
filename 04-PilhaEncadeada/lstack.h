/*------------------------------------------------
lstack.c
Arquivo com a definição das funções do TAD Pilha
Encadeada (Lista que se comporta como Pilha)
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
int sllPush(SLList *l, void *data);
void *sllPop(SLList *l);
void *sllTop(SLList *l);
int sllIsEmpty(SLList *l);

#endif