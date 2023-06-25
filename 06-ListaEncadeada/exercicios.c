/*------------------------------------------------
exercicios.c
Arquivo com os exercícios do TAD Lista Simplesmente
Encadeada (Single Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sllist.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);
void mostraLista(SLList *sll);
// Questao 1: Prova 2017.1
SLList *sllCulmulativeSum(SLList *l1, int (*getvalue)(void *));

int main(void)
{
    SLList *sll, *sll2;
    sll = sllCreate();
    sll2 = sllCreate();

    sllInsertLast(sll, (void *)8);
    sllInsertLast(sll, (void *)2);
    sllInsertLast(sll, (void *)1);
    sllInsertLast(sll, (void *)9);
    sllInsertLast(sll, (void *)5);

    mostraLista(sll);
}

int cmp(void *data, void *key)
{
    int *id = (int *)data;
    int *chave = (int *)key;

    if (id == chave)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void mostraLista(SLList *sll)
{
    if (sll->first != NULL)
    {
        int aux = 0, *item;
        SLNode *node;
        node = sll->first;
        while (node != NULL)
        {
            aux++;
            item = (int *)node->data;
            printf("\nElemento %d: %d", aux, item);
            node = node->next;
        }
    }
    else
    {
        printf("\nNao ha elementos na lista!");
    }
    printf("\n");
}

// Questao 1: Prova 2017.1
/* Faça um algoritmo que recebe uma Lista Linear Simplesmente Encadeada l1
e retorna uma lista simplesmente encadeada l2 com o mesmo comprimento de l1.
I k-esimo nó de l2 possui o valor da soma dos k primeiros nós de l1
obs: a função getvalue retorna o valor inteiro armazenado no campo data de cada nó*/
SLList *sllCulmulativeSum(SLList *l1, int (*getvalue)(void *))
{
    if (l1 != NULL)
    {
        if (l1->first != NULL)
        {
            SLList *l2;
            l2 = sllCreate();
            if (l2 != NULL)
            {
                int soma = 0;
                SLNode *node1, *node2;
                node1 = l1->first;
                while (node1 != NULL)
                {
                    soma += getvalue(node1->data);
                    // se puder usar as funções do TAD
                    sllInsertLast(l2, (void *)&soma);
                    // caso não possa
                    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                    newnode->data = (void *)&soma;
                    newnode->next = NULL;
                    if (l2->first == NULL)
                    {
                        l2->first = newnode;
                        node2 = l2->first;
                    }
                    else
                    {
                        node2->next = newnode;
                        node2 = node2->next;
                    }
                    node1 = node1->next;
                }
                return l2;
            }
        }
    }
    return NULL;
}
