/*------------------------------------------------
cqueue.c
Arquivo com a especificação para o TAD Fila Circular
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "lstack.h"

#ifndef __LSTACK_C_
#define __LSTACK_C_

#define TRUE 1
#define FALSE 0

SLList *sllCreate(void)
{
    SLList *l;
    l = (SLList *)malloc(sizeof(SLList));
    if (l != NULL)
    {
        l->first = NULL;
        return l;
    }
}

int sllDestroy(SLList *l)
{
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertFirst(SLList *l, void *data)
{
    SLNode *newnode;
    if (l != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
            newnode->data = data;
        newnode->next = l->first;
        l->first = newnode;
        return TRUE;
    }
    return FALSE;
}

void *sllRemoveFirst(SLList *l)
{
    SLNode *first;
    void *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        { // Se a lista não esta vazia
            first = l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

void *sllGetFirst(SLList *l)
{
    SLNode *first;
    void *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        { // Se a lista não esta vazia
            first = l->first;
            data = first->data;
            return data;
        }
    }
    return NULL;
}

#endif