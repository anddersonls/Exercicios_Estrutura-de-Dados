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

// ESTRUTURA DA POSICAO DA RAINHA
typedef struct _rainha_
{
    int lin, col;
} Rainha;

// ESTRUTURA DA POSSIVEL POSICAO DA RAINHA
typedef struct _posicao_
{
    int i, j;
} Posicao;

void nRainhas(SLList *ls, int n);
int EPosPossivel(SLNode *cur, Posicao *pos, int n);
void adicionaRainha(SLList *ls, Posicao *pos);
void retiraRainhaAnterior(SLList *ls, Posicao *pos);
void desenhaTabuleiro(SLList *ls, int n);

int main(void)
{
    int n, opcao;

    while (opcao != 2)
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Distribuir Rainhas no Tabuleiro NxN\n");
        printf("|| 2. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o tamanho do tabuleiro (NxN): ");
            scanf("%d", &n);
            printf("\n");
            if (n > 3)
            {
                SLList *ls;
                ls = sllCreate();
                nRainhas(ls, n);
            }
            else
            {
                printf("Nao foi possivel distribuir %d rainhas em um tabuleiro %dx%d!", n, n, n);
            }
            break;
        case 2:
            break;
        default:
            printf("Digite uma opcao valida!");
        }
    }

    printf("\nObrigado por utilizar meu codigo :) !");
}

int EPosPossivel(SLNode *cur, Posicao *pos, int n)
{
    int achou = TRUE, coluna, linha;
    Rainha *rainha;

    while (cur != NULL)
    {
        rainha = (Rainha *)cur->data;
        // printf("lin: %d , col: %d\n", pos->lin, pos->col);
        // printf("i: %d , j: %d\n\n", i, j);
        if (rainha->col == pos->j)
        {
            achou = FALSE;
        }
        linha = pos->i;
        coluna = pos->j;
        while (linha >= 0 && coluna < n)
        {
            if (coluna == rainha->col && linha == rainha->lin)
            {
                achou = FALSE;
            }
            linha -= 1;
            coluna += 1;
        }
        linha = pos->i;
        coluna = pos->j;
        while (linha >= 0 && coluna >= 0)
        {
            if (coluna == rainha->col && linha == rainha->lin)
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
    return achou;
}

void desenhaTabuleiro(SLList *ls, int n)
{
    Rainha *pos;
    SLNode *cur;
    cur = ls->first;
    char matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 'X';
        }
    }

    for (int i = 0; i < n; i++)
    {
        pos = (Rainha *)cur->data;
        matriz[pos->lin][pos->col] = 'O';
        cur = cur->next;
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

void adicionaRainha(SLList *ls, Posicao *pos)
{
    Rainha *novaPos = (Rainha *)malloc(sizeof(Rainha));
    novaPos->col = pos->j;
    novaPos->lin = pos->i;
    sllPush(ls, (void *)novaPos);
}

void retiraRainhaAnterior(SLList *ls, Posicao *pos)
{
    pos->i--;
    Rainha *rainha;
    rainha = (Rainha *)sllPop(ls);
    pos->j = rainha->col + 1;
}

void nRainhas(SLList *ls, int n)
{
    SLNode *cur;
    int achou = TRUE;
    cur = ls->first;
    Posicao posicao;
    Posicao *pos = &posicao;
    pos->i = 0;
    pos->j = 0;

    while (pos->i < n)
    {
        achou = EPosPossivel(cur, pos, n);
        if (achou)
        {
            adicionaRainha(ls, pos);
            pos->j = 0;
            pos->i++;
        }
        else if (achou == FALSE && pos->j >= n - 1)
        {
            retiraRainhaAnterior(ls, pos);
            while (pos->j > n - 1)
            {
                retiraRainhaAnterior(ls, pos);
            }
        }
        else
        {
            pos->j++;
        }
        achou = TRUE;
        cur = ls->first;
    }
    desenhaTabuleiro(ls, n);
}