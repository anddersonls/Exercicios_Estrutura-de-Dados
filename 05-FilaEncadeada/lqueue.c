/*------------------------------------------------
lqueue.c
Arquivo com a especificação para o TAD Pilha Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "lqueue.h"

#ifndef __LSTACK_C_
#define __LSTACK_C_

#define TRUE 1
#define FALSE 0

LLQueue *llqCreate(void)
{
    LLQueue *lq;
    lq = (LLQueue *)malloc(sizeof(LLQueue));
    if (lq != NULL)
    {
        lq->front = NULL;
        lq->rear = NULL;
        return lq;
    }
    return NULL;
}

int llqDestroy(LLQueue *lq)
{
    if (lq != NULL)
    {
        if (lq->front == NULL)
        {
            free(lq);
            return TRUE;
        }
    }
    return FALSE;
}

int llqEnqueue(LLQueue *lq, void *data)
{
    SLNode *newnode, *last;
    if (lq != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = NULL;
            if (lq->front == NULL)
            { // lista ta vazia
                lq->front = newnode;
                lq->rear = newnode;
            }
            else
            { // lista não esta vazia
                last = lq->rear;
                last->next = newnode;
                lq->rear = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void *llqDequeue(LLQueue *lq)
{
    void *data;
    SLNode *first;
    if (lq != NULL)
    { // existe lq
        first = lq->front;
        if (first != NULL)
        { // fila tem alguém
            data = first->data;
            lq->front = first->next;
            if (lq->rear == first)
            {
                lq->rear = NULL;
            }
            free(first);
            return data;
        }
    }
    return NULL;
}

void *llqFirst(LLQueue *l)
{
    SLNode *first;
    void *data;
    if (l != NULL)
    {
        if (l->front != NULL)
        {
            first = l->front;
            data = first->data;
            return data;
        }
    }
    return NULL;
}

int llqIsEmpty(LLQueue *l)
{
    SLNode *first;
    if (l != NULL)
    {
        if (l->front == NULL)
        {
            return TRUE;
        }
    }
    return FALSE;
}

#endif