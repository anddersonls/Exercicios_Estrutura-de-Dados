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
// Questao 2: Prova 2022.1
void PegaElementosIguais(DLList *l1, DLList *l2, DLList *l3);

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
                if (l1node == l2node)
                {
                    l1prev->next = NULL;
                    l2node->prev = l2prev;
                    return l1node;
                }
                l2prev = l2node;
                l2node = l2node->next;
            }
            l1prev = l1node;
            l1node = l1node->next;
        }
    }
    return NULL;
}

// Questao 2: Prova 2022.1
/*Escreva um algoritmo que recebe três listas lineares duplamente encadeadas L1,
L2 e L3. E, retorna a Lista L3 com os nós de L1 que estão que tem um igual em L2
(data), ou seja que estão presentes em ambas as listas (L1 e L2). Não pode alocar novos
nós. L3 é recebida pelo algoritmo sem nenhum nó (vazia). Os elementos incluídos em
L3 devem ser retirados da lista L1.*/
void PegaElementosIguais(DLList *l1, DLList *l2, DLList *l3)
{
    if (l1 != NULL && l1->first != NULL && l2 != NULL && l2->first != NULL && l3 != NULL)
    {
        DLNode *l1node, *l2node, *l3node;
        l1node = l1->first;
        while (l1node->next != NULL)
        {
            l2node = l2->first;
            while (l2node->next != NULL)
            {
                if (l2node->data == l1node->data)
                {
                    if (l3->first == NULL)
                    {
                        l3->first = l1node;
                        l3node = l3->first;
                        l3node->next = NULL;
                        break;
                    }
                    else
                    {
                        l3node->next = l1node;
                        DLNode *l3prev;
                        l3prev = l3node;
                        l3node = l3node->next;
                        l3node->prev = l3prev;
                        l3node->next = NULL;
                        break;
                    }
                                }
                l2node = l2node->next;
            }
            l1node = l2node->next;
        }
    }
}