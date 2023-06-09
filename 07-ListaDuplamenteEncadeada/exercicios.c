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
// Questão 2: Prova 2017.1
int DllCulmulativeSum(DLList *l1, int i, int j);
// Questão 2: Prova 20XX(1)
int inverteDLList(DLList *l1, DLList *l2);

int main(void)
{
    DLList *dll;
    dll = dllCreate();
    dllInsertAsFirst(dll, (void *)7);
    dllInsertAsFirst(dll, (void *)2);
    dllInsertAsFirst(dll, (void *)1);
    dllInsertAsFirst(dll, (void *)6);
    dllInsertAsFirst(dll, (void *)5);
    DLList *dll2;
    dll2 = dllCreate();
    /*dllInsertAsLast(dll2, (void *)5);
    dllInsertAsLast(dll2, (void *)2);
    dllInsertAsLast(dll2, (void *)9);
    dllInsertAsLast(dll2, (void *)6);
    dllInsertAsLast(dll2, (void *)8);*/

    mostrarlista(dll);
    // DllCulmulativeSum(dll, 1, 5);
    inverteDLList(dll, dll2);
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
        printf("\n\n");
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

// Questão 2: Prova 2017.1
/* Faça um algoritmo que recebe uma lista linear duplamente encadeada
e dois numeros inteiros i e j. O algoritmo deve trocar a posicao do
i-esimo nó da lista com o j-esimo nó da lista. Não pode alocar novos nós.*/
int DllCulmulativeSum(DLList *l1, int i, int j)
{
    if (l1 != NULL)
    {
        if (l1->first != NULL)
        {
            int aux = 1;
            DLNode *node, *inode, *jnode, *auxnode;
            inode = NULL;
            jnode = NULL;
            node = l1->first;
            while (node != NULL)
            {
                if (aux == i)
                {
                    inode = node;
                }
                if (aux == j)
                {
                    jnode = node;
                }
                aux++;
                node = node->next;
            }
            if (inode != NULL && jnode != NULL)
            {
                // setando os nos anteriores e posteriores dos que serão trocados
                if (inode->prev != NULL)
                {
                    inode->prev->next = jnode;
                }
                else
                {
                    l1->first = jnode;
                }
                if (jnode->prev != NULL)
                {
                    jnode->prev->next = inode;
                }
                else
                {
                    l1->first = inode;
                }
                if (inode->next != NULL)
                {
                    inode->next->prev = jnode;
                }
                if (jnode->next != NULL)
                {
                    jnode->next->prev = inode;
                }

                // setando os next
                auxnode = inode->next;
                inode->next = jnode->next;
                jnode->next = auxnode;
                // setando os prev
                auxnode = inode->prev;
                inode->prev = jnode->prev;
                jnode->prev = auxnode;

                return TRUE;
            }
        }
    }
    return FALSE;
}

// Questao 2: Prova 20XX(1)
/* Escreva um algoritmo Inverte(l1, l2) que retornte na lista L2
todos os nós da lista l1 na ordem inversa em que estavam (ambas
duplamente encadeada linear). não pode alocar novos nós nem usar
uma outra estrutura de dados auxiliar*/
int inverteDLList(DLList *l1, DLList *l2)
{
    if (l1 != NULL && l2 != NULL)
    {
        if (l1->first != NULL)
        {
            DLNode *cur, *last;
            cur = l1->first;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            last = cur;
            cur = l2->first;
            while (last != NULL)
            {
                if (cur == l2->first)
                {
                    l2->first = last;
                    cur = l2->first;
                    cur->prev = NULL;
                    cur->next = NULL;
                }
                else
                {
                    cur->next = last;
                    cur->prev = last->next;
                    cur = cur->next;
                }

                last = last->prev;
            }
            return TRUE;
        }
    }
    return FALSE;
}