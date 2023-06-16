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
    int i = 0, j = 0, achou = TRUE, coluna, linha, cont = 0;
    cur = ls->first;

    while (i < n && cont < n)
    {
        while (cur != NULL)
        {
            pos = (Posicao *)cur->data;
            printf("lin: %d , col: %d\n", pos->lin, pos->col);
            printf("i: %d , j: %d\n\n", i, j);
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
            else
            {
                break;
            }
        }
        if (achou)
        {
            Posicao *p = (Posicao *)malloc(sizeof(Posicao));
            p->col = j;
            p->lin = i;
            sllPush(ls, (void *)p);
            j = 0;
            i++;
            cont++;
        }
        else if (achou == FALSE && j >= n - 1)
        {
            printf("\noi\n");
            i--;
            pos = (Posicao *)sllPop(ls);
            j = pos->col + 1;
            cont--;
            while (j > n - 1)
            {
                printf("%d %d\n\n", i, j);
                i--;
                pos = (Posicao *)sllPop(ls);
                j = pos->col + 1;
                cont--;
            }
        }
        else
        {
            j++;
        }
        achou = TRUE;
        cur = ls->first;
    }
    printf("----------------------------------\n");
    Posicao *p;
    cur = ls->first;
    cont = n;
    char matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 'X';
        }
    }

    while (cont > 0)
    {
        p = (Posicao *)cur->data;
        matriz[p->lin][p->col] = 'O';
        cur = cur->next;
        cont--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }
}