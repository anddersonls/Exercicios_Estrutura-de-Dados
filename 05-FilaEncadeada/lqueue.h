/*------------------------------------------------
lstack.h
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

typedef struct _llqueue_
{
    SLNode *front;
    SLNode *rear;
} LLQueue;

LLQueue *llqCreate(void);
int llqDestroy(LLQueue *);
int llqEnqueue(LLQueue *, void *data);
void *llqDequeue(LLQueue *);
void *llqFirst(LLQueue *l);
int llqIsEmpty(LLQueue *l);

#endif