/*------------------------------------------------
abp.h
Arquivo com a definição das funções do TAD Árvore
Binária de Pesquisa
---------------------------------------------------
Autor: Anderson Lopes Silva
July/2023
-------------------------------------------------*/

#ifndef __ABP_H_
#define __ABP_H_

typedef struct t_node
{
    void *data;
    struct t_node *left;
    struct t_node *right;
} TNode;

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *));
void simetrico(TNode *t, void (*visit)(void *));
TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data);
TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data);

#endif