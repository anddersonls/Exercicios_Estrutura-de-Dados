/*------------------------------------------------
fila.c
Arquivo com a definição das funções do TAD Fila
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#ifndef _FILA_C_
#define _FILA_C_

#define TRUE 1
#define FALSE 0

Queue *qCreate(int n)
{
    Queue *q;
    if (n > 0)
    {
        q = (Queue *)malloc(sizeof(Queue));
        if (q != NULL)
        {
            q->item = (void **)malloc(sizeof(void *) * n);
            if (q->item != NULL)
            {
                q->maxItens = n;
                q->front = 0;
                q->rear = -1;
                return q;
            }
        }
        free(q);
    }
    return NULL;
}

int qDestroy(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear < 0)
        {
            free(q->item);
            free(q);
            return TRUE;
        }
        return FALSE;
    }
}

int qEnqueue(Queue *q, void *data)
{
    if (q != NULL)
    {
        if (q->rear < q->maxItens - 1)
        {
            q->rear++;
            q->item[q->rear] = data;
            return TRUE;
        }
    }
    return FALSE;
}

void *qDequeue(Queue *q)
{
    void *data;
    int cur, next, i;
    if (q != NULL)
    {
        if (q->rear >= 0)
        {
            data = q->item[q->front];
            for (i = q->front; i < q->rear; i++)
            {
                cur = i;
                next = i + 1;
                q->item[cur] = q->item[next];
            }
            q->rear--;
            return data;
        }
    }
    return NULL;
}

void *qFirst(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear >= 0)
        {
            return q->item[q->front];
        }
    }
    return NULL;
}

int qIsEmpty(Queue *q)
{
    if (q != NULL)
    {
        if (q->rear < 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

#endif