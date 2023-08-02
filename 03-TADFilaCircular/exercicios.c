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
// Lista de exercícios de fila 1 questao 1
int cqPromoveUltimo(CQueue *q, int n);
// Lista de exercícios de fila circular 1: questao 2
int cqPunePrimeiro(CQueue *q, int n);
// Prova 2022.1: Questão 2
int PunePrimeiro(CQueue *q, int n);
// Prova 20XX(1): Questão 1
int RemoverImpares(CQueue *F);
// Prova 2017.1: Questão 1
int qEnqueueN(CQueue *q, int n, void **elms);
// Prova 2011.2: Questão 2
void PuneFuraFila(CQueue *f);

int main()
{
    CQueue *cq;
    int n = 10;

    cq = qcCreate(n);

    qcEnqueue(cq, (void *)3);
    qcEnqueue(cq, (void *)1);
    qcEnqueue(cq, (void *)7);
    qcEnqueue(cq, (void *)9);
    qcEnqueue(cq, (void *)4);
    mostrarFila(cq);
    printf("\n");

    mostrarFila(cq);
    printf("\n");

    qcEnqueue(cq, (void *)3);
    qcEnqueue(cq, (void *)11);
    mostrarFila(cq);
    printf("\n");

    // cqPromoveUltimo(cq, 5);
    PunePrimeiro(cq, 0);
    // RemoverImpares(cq);

    /*
    void **elms;
    elms = (void **)malloc(3 * sizeof(void *));
    elms[0] = (void *)11;
    elms[1] = (void *)13;
    elms[2] = (void *)19;
    qEnqueueN(cq, 3, elms);*/

    // PuneFuraFila(cq);

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

// Lista de exercícios de fila 1: questao 1
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
            return TRUE;
        }
    }
    return FALSE;
}

// Lista de exercícios de fila circular 1: questão 2
/*Punir o primeiro elemento da fila colocando-o n
posições para tras.*/
int cqPunePrimeiro(CQueue *q, int n)
{
    if (q != NULL)
    {
        if (q->rear > 0)
        {
            void *data = q->elms[q->front];
            int movimentos;
            if (n >= q->nElms)
            {
                movimentos = q->nElms - 1;
            }
            else
            {
                movimentos = n;
            }
            int aux = q->front;
            for (int i = 0; i < movimentos; i++)
            {
                q->elms[aux] = q->elms[incCirc(aux, q->maxItens)];
                aux = incCirc(aux, q->maxItens);
            }
            q->elms[q->rear] = data;
        }
        return TRUE;
    }
    return FALSE;
}

// Prova 2022.1: Questão 2
/*Receber uma fila implementada como um vetor circular e punir o
primeiro elemento da fila colocando-o n posições para trás se a fila
tiver mais que n elementos ou coloca-lo no final da fila de se a fila
tiver menos que n elementos. (30 pontos)*/
int PunePrimeiro(CQueue *q, int n)
{
    if (q != NULL)
    {
        int movimentos;
        void *data = q->elms[q->front];
        if (n > q->nElms - 1)
        {
            q->rear = incCirc(q->rear, q->maxItens);
            q->elms[q->rear] = data;
            q->front = incCirc(q->front, q->maxItens);
        }
        else
        {
            movimentos = n;
            int aux = q->front, i;
            while (i < movimentos)
            {
                q->elms[aux] = q->elms[incCirc(aux, q->maxItens)];
                aux = incCirc(aux, q->maxItens);
                i++;
            }
            q->elms[aux] = data;
        }
        return TRUE;
    }
    return FALSE;
}

// Prova 20XX(1): Questão 1
/*Remover todos os elementos de ordem ímpar (primeiro, terceiro, quinto..)
de uma fila armazenada em um vetor circular*/
int RemoverImpares(CQueue *F)
{
    if (F != NULL && F->nElms > 0)
    {
        int moves;
        int i = F->front, aux = incCirc(F->front, F->maxItens), cont = 0;
        while (cont < F->nElms / 2)
        {
            F->elms[i] = F->elms[aux];
            i = incCirc(i, F->maxItens);
            aux = incCirc(aux, F->maxItens);
            aux = incCirc(aux, F->maxItens);
            cont++;
        }
        F->rear = decCirc(i, F->maxItens);
        F->nElms = cont;
        return TRUE;
    }
    return FALSE;
}

// Prova 2017.1: Questão 1
/*Implemente uma função que recebe, uma fila armazenada em um vetor
circular, e um vetor com n elementos, e insere os n elementos na fila.
Não pode usar memória adicional (vetores auxiliares) nem chamar outras
funções do TAD Queue.*/
int qEnqueueN(CQueue *q, int n, void **elms)
{
    if (q != NULL && n > 0 && elms != NULL && q->maxItens - q->nElms >= n)
    {
        int aux = incCirc(q->rear, q->maxItens);
        for (int i = 0; i < n; i++)
        {
            q->elms[aux] = elms[i];
            aux = incCirc(aux, q->maxItens);
        }
        q->rear = decCirc(aux, q->maxItens);
        q->nElms += n;
        return TRUE;
    }
    return FALSE;
}

// Prova 2011.2 - Questão 2
/*Escreva um algoritmo que promove o último elemento de uma fila
representada em um vetor circular, retirando-o da ultima posição
e colocando-o no meio da fila. Não pode realizar chamadas a função
Insere e Retira da fila, o algoritmo deve realizar a operação
somente com manipulação do cetor que representa a fila*/
void PuneFuraFila(CQueue *f)
{
    if (f != NULL)
    {
        if (f->nElms > 2)
        {
            int movimentos = f->nElms / 2, i = 0, aux = f->rear;
            void *item = f->elms[f->rear];
            while (i < movimentos)
            {
                f->elms[aux] = f->elms[decCirc(aux, f->maxItens)];
                aux = decCirc(aux, f->maxItens);
                i++;
            }
            f->elms[aux] = item;
        }
    }
}