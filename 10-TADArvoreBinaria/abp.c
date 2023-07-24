/*------------------------------------------------
abp.c
Arquivo com a especificação para o TAD Árvore
Binária de Pesquisa
---------------------------------------------------
Autor: Anderson Lopes Silva
July/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

#ifndef __ABP_C_
#define __ABP_C_

#define TRUE 1
#define FALSE 0

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *))
{
    TNode *newnode;
    int stat;
    if (t != NULL)
    {
        stat = cmp(data, t->data);
        if (stat <= 0)
        {
            t->left = abpInsert((TNode *)t->left, data, cmp);
        }
        else
        {
            t->right = abpInsert((TNode *)t->right, data, cmp);
        }
        return t;
    }
    else
    {
        newnode = (TNode *)malloc(sizeof(TNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->left = newnode->right = NULL;
            return newnode;
        }
        else
        {
            return NULL;
        }
    }
}

void simetrico(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        simetrico(t->left, visit);
        visit(t->data);
        simetrico(t->right, visit);
    }
}

void preOrdem(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        visit(t->data);
        preOrdem(t->left, visit);
        preOrdem(t->right, visit);
    }
}

void posOrdem(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        posOrdem(t->left, visit);
        posOrdem(t->right, visit);
        visit(t->data);
    }
}

TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2;
    int stat;
    TNode *aux;
    if (t != NULL)
    {
        stat = cmp(key, t->data);
        if (stat < 0)
        {
            t->left = abpRemove(t->left, key, cmp, data);
            return t;
        }
        else if (stat > 0)
        {
            t->right = abpRemove(t->right, key, cmp, data);
            return t;
        }
        else
        {
            if (t->left == NULL && t->right == NULL)
            {
                *data = t->data;
                free(t);
                return NULL;
            }
            else if (t->left == NULL)
            {
                aux = t->right;
                *data = t->data;
                free(t);
                return aux;
            }
            else if (t->right == NULL)
            {
                aux = t->left;
                *data = t->data;
                free(t);
                return aux;
            }
            else
            {
                *data = t->data;
                t->left = abpRemoveMaior(t->left, cmp, &data2);
                t->data = data2;
                return t;
            }
        }
    }
    *data = NULL;
    return NULL;
}

TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data)
{
    TNode *aux;
    if (t != NULL)
    {
        if (t->right != NULL)
        {
            t->right = abpRemoveMaior(t->right, cmp, data);
        }
        else
        {
            if (t->left != NULL)
            {
                aux = t->left;
                *data = t->data;
                free(t);
                return aux;
            }
            else
            {
                *data = t->data;
                free(t);
                return NULL;
            }
        }
        return t;
    }
}

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *))
{
    int stat;
    if (t != NULL)
    {
        stat = cmp(key, t->data);
        if (stat == 0)
        {
            return t->data;
        }
        else if (stat < 0)
        {
            return abpQuery(t->left, key, cmp);
        }
        else
        {
            return abpQuery(t->right, key, cmp);
        }
    }
    return NULL;
}

void *abpGetMin(TNode *t)
{
    if (t != NULL)
    {
        if (t->left != NULL)
        {
            return abpGetMin(t->left);
        }
        else
        {
            return t->data;
        }
    }
    return NULL;
}

void *abpGetMax(TNode *t)
{
    if (t != NULL)
    {
        if (t->right != NULL)
        {
            return abpGetMax(t->right);
        }
        else
        {
            return t->data;
        }
    }
    return NULL;
}

#endif