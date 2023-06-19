/*------------------------------------------------
dllist.c
Arquivo com a especificação para o TAD Lista
Duplamente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

#ifndef __DLLIST_C_
#define __DLLIST_C_

#define TRUE 1
#define FALSE 0

DLList *dllCreate()
{
    DLList *l;
    l = (DLList *)malloc(sizeof(DLList));
    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int dllDestroy(DLList *l)
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

int dllDestroyNotEmpty(DLList *l, int (*myfree)(void *))
{
    DLNode *cur, *prev;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            cur = l->first;
            while (cur != NULL)
            {
                myfree(cur->data);
                prev = cur;
                cur = cur->next;
                free(prev);
            }
        }
        free(l);
        return TRUE;
    }
    return FALSE;
}

int dllInsertAsFirst(DLList *l, void *data)
{
    DLNode *newnode, *next;
    if (l != NULL)
    {
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = l->first;
            newnode->prev = NULL;
            next = l->first;
            if (next != NULL)
            {
                next->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertAsLast(DLList *l, void *data)
{
    DLNode *newnode, *last;
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            last = NULL;
        }
        else
        {
            last = l->first;
            while (last->next != NULL)
            {
                last = last->next;
            }
        }
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
        }
        newnode->next = NULL;
        newnode->prev = last;
        if (last == NULL)
        {
            l->first = newnode;
        }
        else
        {
            last->next = newnode;
        }

        return TRUE;
    }
    return FALSE;
}

int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    DLNode *spec, *nextspec, *prevspec, *newnode;
    int stat;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    nextspec = spec->next;
                    newnode->next = nextspec;
                    newnode->prev = spec;
                    if (nextspec != NULL)
                    {
                        nextspec->prev = newnode;
                    }
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    DLNode *spec, *nextspec, *prevspec, *newnode;
    int stat;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    prevspec = spec->prev;
                    newnode->next = spec;
                    newnode->prev = prevspec;
                    if (prevspec != NULL)
                    {
                        prevspec->next = newnode;
                    }
                    if (l->first == spec)
                    {
                        l->first = newnode;
                    }
                    spec->prev = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *))
{
    DLNode *spec, *nextspec, *prevspec;
    void *data;
    int stat;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                data = spec->data;
                prevspec = spec->prev;
                nextspec = spec->next;
                if (nextspec != NULL)
                {
                    nextspec->prev = prevspec;
                }
                if (prevspec != NULL)
                {
                    prevspec->next = nextspec;
                }
                if (l->first == spec)
                {
                    l->first = nextspec;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

#endif