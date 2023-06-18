/*------------------------------------------------
sllist.c
Arquivo com a especificação para o TAD Lista
Simplesmente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

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

int sllIsEmpty(SLList *l)
{
    SLNode *first;
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int sllNNodes(SLList *l)
{
    int n = 0;
    if (l != NULL)
    {
        SLNode *last;
        last = l->first;
        if (last != NULL)
        {
            n++;
            while (last->next != NULL)
            {
                last = last->next;
                n++;
            }
        }
        return n;
    }
    return -1;
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

int sllInsertLast(SLList *l, void *data)
{
    SLNode *newnode, *last;
    if (l != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = NULL;
            if (l->first == NULL)
            {
                l->first = newnode;
            }
            else
            {
                last = l->first;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = newnode;
            }
        }
        return TRUE;
    }
    return FALSE;
}

int sllInserftAfterSpecQuery(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    SLNode *spec, *newnode;
    int stat = FALSE;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int sllInsertBefSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    SLNode *prev, *spec;
    int stat = FALSE;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            prev = NULL;
            spec = l->first;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL)
            {
                prev = spec;
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = spec;
                    if (prev != NULL)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
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
        {
            first = l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveLast(SLList *l)
{
    SLNode *last, *prev;
    void *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            last = l->first;
            prev = NULL;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            data = last->data;
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            else
            {
                l->first = NULL;
            }
            free(last);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *))
{
    SLNode *spec, *prev, *data;
    int stat = FALSE;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            prev = NULL;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL)
            {
                prev = spec;
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                data = spec->data;
                if (prev == NULL)
                {
                    l->first = spec->next;
                }
                else
                {
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
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

void *sllGetLast(SLList *l)
{
    SLNode *last, *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            last = l->first;
            while (last->next != NULL)
            {
                last = last->next;
            }
            data = last->data;
            return data;
        }
    }
    return NULL;
}

#endif