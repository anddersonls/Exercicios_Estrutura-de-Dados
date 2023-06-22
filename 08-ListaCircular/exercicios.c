/*------------------------------------------------
exercicios.c
Arquivo com exercícios do TAD Lista Simplesmente
Encadeada (Single Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "csllist.h"

#define TRUE 1
#define FALSE 0

// compara chaves
int cmp(void *data, void *key);
// mostra os itens na lista
void mostrarlista(SLList *sll);
// Questao 1: 20XX(6).pdf
int lcseGetNumberOfOcurrences(SLList *l, void *key, int (*cmp)(void *, void *));
// Questao 2: 20XX(6).pdf
void lcesAppendList(SLList *l1, SLList *l2);

int main(void)
{
    SLList *csll;
    csll = csllCreate();
    csllInsertLast(csll, (void *)8);
    csllInsertLast(csll, (void *)2);
    csllInsertLast(csll, (void *)8);
    csllInsertLast(csll, (void *)7);
    csllInsertLast(csll, (void *)8);
    SLList *csll2;
    csll2 = csllCreate();
    csllInsertLast(csll2, (void *)1);
    csllInsertLast(csll2, (void *)5);
    csllInsertLast(csll2, (void *)8);
    csllInsertLast(csll2, (void *)4);
    csllInsertLast(csll2, (void *)3);

    mostrarlista(csll);
    printf("\n\n");
    // mostrarlista(csll2);
    // printf("\n\n");

    int teste;
    // teste = leseGetNumberOfOcurrences(csll, (void *)8, cmp);
    // printf("\n\nNumero de repeticoes do elemento: %d", teste);
    lcesAppendList(csll, csll2);
}

void mostrarlista(SLList *csll)
{
    if (csll->first != NULL)
    {
        int aux = 0;
        SLNode *node;
        int *item;
        node = csll->first;
        item = (int *)node->data;
        printf("\nElemento %d: %d", aux, item);
        aux++;
        while (node->next != csll->first)
        {
            node = node->next;
            item = (int *)node->data;
            printf("\nElemento %d: %d", aux, item);
            aux++;
        }
    }
    else
    {
        printf("\nNao ha elementos na lista!");
    }
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

// Questao 1: 20XX(6).pdf
/*Escreva um algoritmo que receba uma lista circular simplesmente encadeada e conta
o número de vezes que um determinado dado identificado por key se encontra na lista*/
int lcseGetNumberOfOcurrences(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL && l->first != NULL)
    {
        int cont = 0, stat;
        SLNode *node;
        node = l->first;
        while (node->next != l->first)
        {
            stat = cmp(node->data, key);
            if (stat)
            {
                cont++;
            }
            node = node->next;
        }
        if (cmp(node->data, key))
        {
            cont++;
            node = node->next;
        }
        return cont;
    }
    return -1;
}

// Questao 2: 20XX(6).pdf
/*Faça um algoritmo que recebe uma lista circular simplesmente encadeada (L1)
e uma lista linear simplesmente encadeada (L2) e modifica a lista L1 de modo que
ela seja uma lista circular simplesmente encadeada com os elementos de L2 adicionados
ao final dos seus elementos originais. OBS: Não pode alocar novos nós*/
void lcesAppendList(SLList *l1, SLList *l2)
{
    if (l1 != NULL && l2 != NULL && l1->first != NULL && l2->first != NULL)
    {
        SLNode *l1_node, *l2_node;
        l1_node = l1->first;
        l2_node = l2->first;
        while (l1_node->next != l1->first)
        {
            l1_node = l1_node->next;
        }
        l1_node->next = l2_node;
        // Para l2 como lista simplesmente encadeada bastaria trocar a condição para l2_node->next != NULL
        while (l2_node->next != l2->first)
        {
            l2_node = l2_node->next;
        }
        l2_node->next = l1->first;
        mostrarlista(l1);
    }
}