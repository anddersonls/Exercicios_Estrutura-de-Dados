/*------------------------------------------------
exercicios.c
Arquivo com exercicios do TAD Lista Duplamente
Encadeada (Doubly Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dllist.h"

#define TRUE 1
#define FALSE 0

// compara dois itens
int cmp(void *data, void *key);
// mmostra os itens da lista
void mostrarlista(DLList *dll);
// Questao 3: prova 20XX(6).pdf
void *verificaNoCompartilhado(DLList *LL1, DLList *LL2);

int main(void)
{
    DLList *dll;
    dll = dllCreate();
    dllInsertAsLast(dll, (void *)7);
    dllInsertAsLast(dll, (void *)2);
    dllInsertAsLast(dll, (void *)1);
    dllInsertAsLast(dll, (void *)6);
    dllInsertAsLast(dll, (void *)5);
    DLList *dll2;
    dll2 = dllCreate();
    dllInsertAsLast(dll2, (void *)5);
    dllInsertAsLast(dll2, (void *)2);
    dllInsertAsLast(dll2, (void *)9);
    dllInsertAsLast(dll2, (void *)6);
    dllInsertAsLast(dll2, (void *)8);

    mostrarlista(dll);
    printf("\n\n");
    mostrarlista(dll2);
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

void mostrarlista(DLList *dll)
{
    if (dll->first != NULL)
    {
        int aux = 0, *item;
        DLNode *node;
        node = dll->first;
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
}

// Questao 3: prova 20XX(6).pdf
/*Faça um algoritmo que recebe duas listas lineares duplamente encadeadas (LL1 e LL2) como
mostrado na figura, veriifica se elas compartilham um nó e encontra o nó que pertence as duas
listas removendo-o da lista LL1*/
void *verificaNoCompartilhado(DLList *LL1, DLList *LL2)
{
    if (LL1 != NULL && LL1->first != NULL && LL1->first != NULL && LL2->first != NULL)
    {
        int stat = FALSE;
        DLNode *l1node, *l2node, *noCompartilhado, *l1prev, *l2prev;
        l1node = LL1->first;

        while (l1node->next != NULL && stat != TRUE)
        {
            l2node = LL2->first;
            while (l2node->next != NULL && stat != TRUE)
            {
                stat = cmp(l1node, l2node);
                if (stat)
                {
                    noCompartilhado = l1node;
                    l1prev = l1node->prev;
                    l2prev = l2node->prev;
                }
                l2node = l2node->next;
            }
            l1node = l1node->next;
        }
        if (stat == TRUE)
        {
            l1prev->next = NULL;
            noCompartilhado->prev = l2prev;
            return noCompartilhado;
        }
    }
    return NULL;
}