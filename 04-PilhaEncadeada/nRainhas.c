/*------------------------------------------------
nRainhas.c
Arquivo com o algoritmo para solução do problema
das N Rainhas com o TAD Pilha Encadeada (Linked Stack)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lstack.h"

#define TRUE 1
#define FALSE 0
#define n 8

typedef struct _posicao_
{
    int lin, col;
} Posicao;

int main(void)
{
    SLList *ls;
    ls = sllCreate();
    SLNode *cur, *data;
    Posicao *pos;
    int i = 0, j = 0, achou = FALSE, coluna, linha, cont = 0;

    if (ls->first == NULL)
    {
        Posicao *p = (Posicao *)malloc(sizeof(Posicao));
        p->col = 0;
        p->lin = 0;
        sllPush(ls, (void *)p);
        i++;
    }

    while (i < n && j < n)
    {
        cur = ls->first;
        while (cur->next != NULL || cur == ls->first)
        {
            pos = (Posicao *)cur->data;
            printf("lin: %d , col: %d\n", pos->lin, pos->col);
            printf("i: %d , j: %d\n", i, j);
            if (pos->col == j)
            {
                achou = FALSE;
            }
            linha = i;
            coluna = j;
            while (linha >= 0 && coluna < n)
            {
                if (coluna == pos->col && linha == pos->lin)
                {
                    achou = FALSE;
                }
                linha -= 1;
                coluna += 1;
            }
            linha = i;
            coluna = j;
            while (linha >= 0 && coluna >= 0)
            {
                if (coluna == pos->col && linha == pos->lin)
                {
                    achou = FALSE;
                }
                linha -= 1;
                coluna -= 1;
            }
            if (cur->next != NULL)
            {
                cur = cur->next;
            }
            if (achou)
            {
                Posicao *p = (Posicao *)malloc(sizeof(Posicao));
                p->col = j;
                p->lin = i;
                sllPush(ls, (void *)p);
                j = 0;
                i++;
            }
            achou = TRUE;
            j++;
        }
        printf("----------------------------------\n");
        Posicao *p;
        cur = ls->first;
        cont = 8;
        while (cont >= 0)
        {
            p = (Posicao *)cur->data;
            printf("%d %d\n", p->lin, p->col);
            cur = cur->next;
            cont--;
        }
    }