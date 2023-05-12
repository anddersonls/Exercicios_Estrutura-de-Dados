/*------------------------------------------------
stack.c
Arquivo com a definição das funções do TAD Stack
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifndef _STACK_C_
#define _STACK_C_

#define TRUE 1
#define FALSE 0

typedef struct _stack_
{
    int maxItens;
    int top;
    void **item;
} Stack;

Stack *stkCreate(int max)
{
    Stack *s;
    if (max > 0)
    {
        s = (Stack *)malloc(sizeof(Stack));
        if (s != NULL)
        {
            s->item = (void **)malloc(sizeof(void *) * max);
            if (s->item != NULL)
            {
                s->maxItens = max;
                s->top = -1;
                return s;
            }
        }
    }
    return NULL;
}

int stkDestroy(Stack *s)
{
    if (s != NULL)
    {
        if (s->top < 0)
        {
            free(s->item);
            free(s);
            return TRUE;
        }
    }
    return FALSE;
}

int stkPush(Stack *s, void *elm)
{
    if (s != NULL)
    {
        if (s->top < s->maxItens - 1)
        {
            s->top++;
            s->item[s->top] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void *stkPop(Stack *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top];
            s->top--;
            return aux;
        }
    }
    return NULL;
}

void *stkTop(Stack *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            aux = s->item[s->top];
            return aux;
        }
    }
    return NULL;
}

int stkIsEmpty(Stack *s)
{
    if (s != NULL)
    {
        if (s->top < 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

#endif