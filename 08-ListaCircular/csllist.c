/*------------------------------------------------
csllist.c
Arquivo com a especificação para o TAD Lista
Circular Encadeada
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "csllist.h"

#ifndef __CSLLIST_C_
#define __CSLLIST_C_

#define TRUE 1
#define FALSE 0

SLList *csllCreate()
{
    SLList *l;
    l = (SLList *)malloc(sizeof(SLList));
    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int csllDestroy(SLList *l)
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

int csllInsertFirst(SLList *l, void *data)
{
    SLNode *newnode, *last;
    if (l != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
            newnode->data = data;
        if (l->first != NULL)
        {
            newnode->next = l->first;
            last = l->first;
            while (last->next != l->first)
            {
                last = last->next;
            }
            last->next = newnode;
            l->first = newnode;
        }
        else
        {
            l->first = newnode;
            newnode->next = l->first;
        }
        return TRUE;
    }
    return FALSE;
}

int csllInsertLast(SLList *l, void *data)
{
    SLNode *newnode, *last;
    if (l != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            if (l->first == NULL)
            {
                l->first = newnode;
            }
            else
            {
                last = l->first;
                while (last->next != l->first)
                {
                    last = last->next;
                }
                last->next = newnode;
            }
            newnode->next = l->first;
        }
        return TRUE;
    }
    return FALSE;
}

int csllInsertAfterSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    SLNode *spec, *newnode;
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

void *csllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *))
{
    SLNode *spec, *prev;
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
                prev = spec;
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                data = spec->data;
                prev->next = spec->next;
                if (spec == l->first)
                {
                    if (spec->next == spec)
                    {
                        l->first = NULL;
                    }
                    else
                    {
                        l->first = spec->next;
                    }
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void *csllGetFirst(SLList *l)
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

void *csllGetNext(SLList *l)
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