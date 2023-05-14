/*------------------------------------------------
exercicios.c
Arquivo com o menu de acesso as funcionalidades do
TAD Fila Circular
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/
#include "cqueue.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void mostrarFila(CQueue *cq);
// Lista de exercícios de fila 2: questao 1
int cqPromoveUltimo(CQueue *q, int n);

int main()
{
    CQueue *cq;
    int n = 5, teste;
    void *a;

    cq = qcCreate(n);
    teste = qcEnqueue(cq, (void *)3);
    teste = qcEnqueue(cq, (void *)1);
    teste = qcEnqueue(cq, (void *)7);
    teste = qcEnqueue(cq, (void *)9);
    teste = qcEnqueue(cq, (void *)4);
    mostrarFila(cq);
    printf("\n");
    a = qcDequeue(cq);
    a = qcDequeue(cq);
    mostrarFila(cq);
    printf("\n");
    teste = qcEnqueue(cq, (void *)3);
    a = qcDequeue(cq);
    teste = qcEnqueue(cq, (void *)19);
    teste = qcEnqueue(cq, (void *)21);

    mostrarFila(cq);
    printf("\n");
    teste = cqPromoveUltimo(cq, 5);
    mostrarFila(cq);
    return 0;
}

void mostrarFila(CQueue *cq)
{
    if (cq->nElms > 0)
    {
        int *item = (int *)qcFirst(cq);
        int elemento, aux = 0;
        elemento = cq->front;
        while (aux < cq->nElms)
        {
            aux++;
            item = (int *)cq->elms[elemento];
            printf("\nElemento %d: %d", aux, item);
            elemento = incCirc(elemento, cq->maxItens);
        }
    }
}

// Lista de exercícios de fila 2: questao 1
int cqPromoveUltimo(CQueue *q, int n)
{
    if (q != NULL)
    {
        if (q->nElms > 0)
        {
            int *data = (int *)q->elms[q->rear];
            int anda;
            if (n >= q->nElms)
            {
                anda = q->nElms - 1;
            }
            else
            {
                anda = n;
            }
            int aux = q->rear;
            for (int i = 0; i < anda; i++)
            {
                q->elms[aux] = q->elms[decCirc(aux, q->maxItens)];
                aux = decCirc(aux, q->maxItens);
            }
            q->elms[aux] = data;
        }
        return TRUE;
    }
    return FALSE;
}