/*------------------------------------------------
exercicios.c
Série de exercícios utilizando o TAD Fila
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

void mostraFila(Queue *q);
// Lista de exercícios de fila 2: questao 1
int qPromoveUltimo(Queue *q, int n);
// Lista de exercícios de fila 2: questao 2
int qPunePrimeiro(Queue *q, int n);

int main()
{
    Queue *q;
    int n = 5, teste;
    void *a;

    q = qCreate(n);
    teste = qEnqueue(q, (void *)2);
    teste = qEnqueue(q, (void *)5);
    teste = qEnqueue(q, (void *)1);
    teste = qEnqueue(q, (void *)3);
    teste = qEnqueue(q, (void *)9);
    a = qDequeue(q);

    // teste = qPromoveUltimo(q, 8);
    teste = qPunePrimeiro(q, 8);
    teste = qEnqueue(q, (void *)4);
    mostraFila(q);
    return 0;
}

void mostraFila(Queue *q)
{
    int numItens = q->rear, *item;
    for (int i = 0; i <= numItens; i++)
    {
        item = (int *)q->item[i];
        printf("\nElemento[%d]: %d", i, item);
    }
}

// Lista de exercícios de fila 2: questao 1
/*Promover um elemento que esta no final da
fila colocando-o n posições pra frente.*/
int qPromoveUltimo(Queue *q, int n)
{
    if (q != NULL)
    {
        if (q->rear > 0)
        {
            void *data = q->item[q->rear];
            int anda;
            if (n >= q->rear)
            {
                anda = q->rear;
            }
            else
            {
                anda = n;
            }
            for (int i = q->rear; i > q->rear - anda; i--)
            {
                q->item[i] = q->item[i - 1];
            }
            q->item[q->rear - anda] = data;
        }
        return TRUE;
    }
    return FALSE;
}

// Lista de exercícios de fila 2: questao 2
/*Punir o primeiro elemento da fila colocando-o
n posições para tras.*/
int qPunePrimeiro(Queue *q, int n)
{
    if (q != NULL)
    {
        if (q->rear > 0)
        {
            void *data = q->item[q->front];
            int movimentos;
            if (n >= q->rear)
            {
                movimentos = q->rear;
            }
            else
            {
                movimentos = n;
            }
            for (int i = 0; i < movimentos; i++)
            {
                q->item[i] = q->item[i + 1];
            }
            q->item[q->rear] = data;
        }
        return TRUE;
    }
    return FALSE;
}