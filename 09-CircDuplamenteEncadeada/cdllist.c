/*------------------------------------------------
cdllist.c
Arquivo com a especificação para o TAD Lista
Circular Duplamente Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "cdllist.h"

#ifndef __CDLLIST_C_
#define __CDLLIST_C_

#define TRUE 1
#define FALSE 0

DLList *cdllCreate()
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

int cdllDestroy(DLList *l)
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

int cdllInsertFirst(DLList *l, void *data)
{
    DLNode *newnode, *last;
    if (l != NULL)
    {
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            if (l->first != NULL)
            {
                newnode->next = l->first;
                last = l->first->prev;
                newnode->prev = last;
                l->first->prev = newnode;
                last->next = newnode;
                l->first = newnode;
            }
            else
            {
                l->first = newnode;
                newnode->next = l->first;
                newnode->prev = l->first;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int cdllInsertLast(DLList *l, void *data)
{
    DLNode *newnode, *last;
    if (l != NULL)
    {
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            if (l->first == NULL)
            {
                l->first = newnode;
                newnode->prev = l->first;
            }
            else
            {
                last = l->first->prev;
                last->next = newnode;
                newnode->prev = last;
                l->first->prev = newnode;
            }
            newnode->next = l->first;
            return TRUE;
        }
    }
    return FALSE;
}

int cdllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    DLNode *newnode, *spec, *next;
    int stat;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != l->first)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    next = spec->next;
                    newnode->data = data;
                    newnode->prev = spec;
                    newnode->next = next;
                    next->prev = newnode;
                    spec->next = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *cdllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *))
{
    DLNode *spec, *prev, *next;
    void *data;
    int stat;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != l->first)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                if (l->first != l->first->next && l->first != l->first->prev)
                {
                    data = spec->data;
                    prev = spec->prev;
                    next = spec->next;
                    prev->next = next;
                    next->prev = prev;
                    l->first = next;
                }
                else
                {
                    l->first = NULL;
                }
            }
            free(spec);
            return data;
        }
    }
    return NULL;
}

void *cdllGetFirst(DLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            l->cur = l->first;
            return l->cur->data;
        }
    }
    return NULL;
}

void *cdllGetNext(DLList *l)
{
    if (l != NULL)
    {
        if (l->cur != NULL)
        {
            l->cur = l->cur->next;
            return l->cur->data;
        }
    }
    return NULL;
}

#endif