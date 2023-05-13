/*------------------------------------------------
cqueue.c
Arquivo com a especificação para o TAD Fila Circular
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

#ifndef __QUEUE_C_
#define __QUEUE_C_

#define TRUE 1
#define FALSE 0

typedef struct _queue_
{
    int front,
        rear;
    int maxItens;
    int nElms;
    void **elms;
} CQueue;

CQueue *qcCreate(int max)
{
    if (max > 0)
    {
        CQueue *cq = (CQueue *)malloc(sizeof(CQueue));
        if (cq != NULL)
        {
            cq->elms = (void **)malloc(sizeof(void *) * max);
            if (cq->elms != NULL)
            {
                cq->front = 0;
                cq->rear = -1;
                cq->maxItens = max;
                cq->nElms = 0;
                return cq;
            }
        }
    }
    return NULL;
}

int qcEnqueue(CQueue *q, void *elm)
{
    if (q != NULL)
    {
        if (q->nElms < q->maxItens)
        {
            q->rear = incCirc(q->rear, q->maxItens);
            q->elms[q->rear] = elm;
            q->nElms++;
            return TRUE;
        }
    }
    return FALSE;
}

void *qcDequeue(CQueue *q)
{
    void *data;
    if (q != NULL)
    {
        if (q->nElms > 0)
        {
            q->nElms--;
            printf("\nnelms: %d", q->nElms);
            data = q->elms[q->front];
            free(q->elms[q->front]);
            q->front = incCirc(q->front, q->maxItens);
            return data;
        }
    }
    return NULL;
}

void *qcFirst(CQueue *q)
{
    void *data;
    if (q != NULL)
    {
        if (q->nElms > 0)
        {
            data = q->elms[q->front];
            return data;
        }
    }
    return NULL;
}

int qcDestroy(CQueue *q)
{
    if (q != NULL)
    {
        if (q->nElms == 0)
        {
            free(q->elms);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}

int qcIsEmpty(CQueue *q)
{
    if (q != NULL)
    {
        if (q->nElms <= 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int incCirc(int i, int max)
{
    if (i == max - 1)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }
}

int decCirc(int i, int max)
{
    if (i == 0)
    {
        return max - 1;
    }
    else
    {
        return i - 1;
    }
}

#endif