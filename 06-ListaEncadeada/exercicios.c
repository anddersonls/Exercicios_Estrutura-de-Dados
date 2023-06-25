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
// Questao 3: Prova 2017.1
int InSub(SLList *l1, SLList *l2, int i1, int i2, int len);

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

    sllInsertLast(sll2, (void *)3);
    sllInsertLast(sll2, (void *)4);
    sllInsertLast(sll2, (void *)0);
    sllInsertLast(sll2, (void *)6);
    sllInsertLast(sll2, (void *)1);

    int teste;
    teste = InSub(sll, sll2, 2, 1, 4);
    printf("teste: %d", teste);
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

// Questao 3: Prova 2017.1
/*Faça um algoritmo que recebe duas listas lineares simplesmente encadeadas
l1 e l2 e três valores inteiros i1, i2 e len, e insere os nós da lista l2,
começando pelo i2-esimo nó e continuando por len nós, na lista l1, começando
antes do i1-ésimo  nó. Nenhum elemento da lista l1 deverá ser removido ou
substituído; Se i1>length(l1)+1 (onde length indica o número de nós na lista)
ou se i2+len-1>length(l2) ou se i1<1 ou se i2<l1 retorne FALSE. Os nós devem
ser removidos de l2 e incluídos em l1. Não pode alocar novos nós.*/
int InSub(SLList *l1, SLList *l2, int i1, int i2, int len)
{
    if (l1 != NULL && l2 != NULL && i1 > 0 && i2 > 0)
    {
        if (l1->first != NULL && l2->first != NULL)
        {
            int aux1 = 1, aux2 = 1;
            SLNode *l1node, *l2node, *l1prev, *auxnode;
            l1node = l1->first;
            l2node = l2->first;
            while (l1node->next != NULL && aux1 < i1)
            {
                l1prev = l1node;
                l1node = l1node->next;
                aux1++;
            }
            while (l2node->next != NULL && aux2 < i2)
            {
                l2node = l2node->next;
                aux2++;
            }
            if (aux1 == i1 && aux2 == i2)
            {
                auxnode = l1node;
                l1node = l1prev;
                aux2 = 0;
                while (l2node != NULL && aux2 < len)
                {
                    l1node->next = l2node;
                    l2node = l2node->next;
                    l1node = l1node->next;
                    aux2++;
                }
                l1node->next = auxnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}