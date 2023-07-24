/*------------------------------------------------
exercicios.c
Arquivo com exercícios do TAD Árvore Binária de
Pesquisa (Binary Search Tree)
---------------------------------------------------
Autor: Anderson Lopes Silva
July/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "abp.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);
void visit(void *data);
// PROVA 2017_1: QUESTÃO 3
int abpCalculaDiferencaMaiorParaMenor(TNode *t, int (*getvalue)(void *));
int abpMaiorValor(TNode *t);
int abpMenorValor(TNode *t);
int getvalue(void *data);

int main(void)
{
    TNode *raiz = NULL;

    raiz = abpInsert(raiz, (void *)20, cmp);
    raiz = abpInsert(raiz, (void *)25, cmp);
    raiz = abpInsert(raiz, (void *)10, cmp);
    raiz = abpInsert(raiz, (void *)5, cmp);
    raiz = abpInsert(raiz, (void *)12, cmp);
    raiz = abpInsert(raiz, (void *)22, cmp);
    raiz = abpInsert(raiz, (void *)23, cmp);
    raiz = abpInsert(raiz, (void *)11, cmp);
    /*simetrico(raiz, visit);
    printf("\n");
    posOrdem(raiz, visit);
    printf("\n");
    preOrdem(raiz, visit);*/

    int teste;
    teste = abpCalculaDiferencaMaiorParaMenor(raiz, getvalue);
    printf("Diferenca: %d", teste);
}

// PROVA 2017_1: QUESTÃO 3
/*Escreva um algoritmo que calcula a diferença entre o maior e o menor valor existente
em uma árvore binária de pesquisa, use obrigatoriamente o protótipo do algoritmo abaixo.*/
int abpCalculaDiferencaMaiorParaMenor(TNode *t, int (*getvalue)(void *))
{
    int maior, menor;
    if (t != NULL)
    {
        menor = abpMenorValor(t);
        maior = abpMaiorValor(t);
        return maior - menor;
    }
}

int abpMenorValor(TNode *t)
{
    if (t != NULL)
    {
        if (t->left != NULL)
        {
            return abpMenorValor(t->left);
        }
        else
        {
            return getvalue(t->data);
        }
    }
}

int abpMaiorValor(TNode *t)
{
    if (t != NULL)
    {
        if (t->right != NULL)
        {
            return abpMaiorValor(t->right);
        }
        else
        {
            return getvalue(t->data);
        }
    }
}

int getvalue(void *data)
{
    int *item = (int *)data;
    int aux = item;
    return aux;
}

int cmp(void *data, void *key)
{
    int *newdata = (int *)data;
    int *node = (int *)key;

    if (newdata > node)
    {
        return 1;
    }
    else if (newdata < node)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void visit(void *data)
{
    int *item = (int *)data;
    printf("\nItem: %d", item);
}