/*------------------------------------------------
exercicios.c
Arquivo com exercícios do TAD Lista Circular
Encadeada (Circular Doubly Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cdllist.h"

#define TRUE 1
#define FALSE 0

// Compara duas chaves
int cmp(void *data, void *key);
// Mostra os itens da lista
void mostraLista(DLList *cdll);
// Questao 1: Prova 2022.1
int ÉInversa(DLList *l1, DLList *l2);
// Questão 1: Prova 2021.2
void *RemoveKEsimo(DLList *l, int k);
// Questao 2: Prova 2021.2
int NumComuns(DLList *l1, DLList *l2, int (*cmp)(void *, void *));

int main(void)
{
    DLList *cdll = cdllCreate();
    cdllInsertLast(cdll, (void *)1);
    cdllInsertLast(cdll, (void *)7);
    cdllInsertLast(cdll, (void *)3);
    cdllInsertLast(cdll, (void *)4);
    cdllInsertLast(cdll, (void *)9);

    DLList *cdll2 = cdllCreate();
    cdllInsertLast(cdll2, (void *)3);
    cdllInsertLast(cdll2, (void *)1);
    cdllInsertLast(cdll2, (void *)7);
    cdllInsertLast(cdll2, (void *)9);
    cdllInsertLast(cdll2, (void *)4);

    mostraLista(cdll);
    mostraLista(cdll2);
    // RemoveKEsimo(cdll, 1);
    int teste;
    teste = NumComuns(cdll, cdll2, cmp);
    printf("%d", teste);
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

void mostraLista(DLList *cdll)
{
    if (cdll->first != NULL)
    {
        int aux = 1, *item;
        DLNode *node;
        node = cdll->first;
        item = (int *)node->data;
        printf("\nElemento %d: %d", aux, item);
        while (node->next != cdll->first)
        {
            aux++;
            node = node->next;
            item = (int *)node->data;
            printf("\nElemento %d: %d", aux, item);
        }
        printf("\n");
    }
    else
    {
        printf("\nNao ha elementos na lista!");
    }
}

// Questao 1: Prova 2022.1
/*Escreva um algoritmo ÉInversa (L1, L2) que retorna 1 se a lista L1 tem os
mesmos elementos de L2 na ordem inversa, -1 se L1 tem menos elementos que L2 e 0
se L1 tem mais elementos que L2. Ambas as listas são circulares duplamente
encadeadas. Não pode alocar novos nós nem usar uma outra estrutura de dados auxiliar.*/
int ÉInversa(DLList *l1, DLList *l2)
{
    if (l1 != NULL && l1->first != NULL && l2 != NULL && l2->first != NULL)
    {
        int stat = TRUE;
        DLNode *l1node, *l2node;
        l1node = l1->first;
        l2node = l2->first->prev;
        while (l1node != l1->first->prev && l2node != l2->first)
        {
            if (l1node != l2node)
            {
                stat = FALSE;
            }
            l1node = l1node->next;
            l2node = l2node->prev;
        }
        if (l1node->next == l1->first && l2node->prev != l2->first->prev)
        {
            return -1;
        }
        if (l1node->next != l1->first && l2node->prev == l2->first->prev)
        {
            return 0;
        }
        if (stat == TRUE && l1node == l2node)
        {
            return 1;
        }
    }
    return -2;
}

// Questão 1: Prova 2021.2
/*Escreva um algoritmo para remover o k-ésimo nó de uma lista
circular duplamente encadeada l. */
void *RemoveKEsimo(DLList *l, int k)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            int cont = 1;
            DLNode *spec, *snext, *sprev;
            spec = l->first;
            while (spec->next != l->first && cont != k)
            {
                spec = spec->next;
                cont++;
            }
            if (cont == k)
            {
                if (spec->next == l->first && spec->prev == l->first && spec == l->first)
                {
                    l->first = NULL;
                }
                else
                {
                    snext = spec->next;
                    sprev = spec->prev;
                    sprev->next = snext;
                    snext->prev = sprev;
                    if (spec == l->first)
                    {
                        l->first = snext;
                    }
                }
                free(spec);
            }
        }
    }
}

// Questao 2: Prova 2021.2
/*Escreva um algoritmo NumComuns (L1, L2) , que deve retornar um
valor inteiro igual ao número de valores comuns às duas listas L1 e L2, que
são circulares duplamente encadeadas.*/
int NumComuns(DLList *l1, DLList *l2, int (*cmp)(void *, void *))
{
    if (l1 != NULL && l2 != NULL)
    {
        if (l1->first != NULL && l2->first != NULL)
        {
            int stat = FALSE, cont = 0;
            DLNode *l1node, *l2node;
            l1node = l1->first;
            do
            {
                l2node = l2->first;
                stat = FALSE;
                do
                {
                    stat = cmp(l2node->data, l1node->data);
                    if (stat)
                    {
                        cont++;
                    }
                    l2node = l2node->next;
                } while (l2node != l2->first && stat != TRUE);
                l1node = l1node->next;
            } while (l1node != l1->first);
            return cont;
        }
    }
    return 0;
}