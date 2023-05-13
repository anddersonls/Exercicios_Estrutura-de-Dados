/*------------------------------------------------
queue.h
Arquivo com a especificação para o TAD Fila
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct _queue_
{
    int front, rear;
    int maxItens;
    void **item;
} Queue;

Queue *qCreate(int n);              // criar uma fila F vazia
int qEnqueue(Queue *q, void *data); // insere x no fim de F (enqueue)
int qIsEmpty(Queue *q);             // testa se F está vazia
void *qFirst(Queue *q);             // acessa o elemento do início da fila
void *qDequeue(Queue *q);           // remove o elemento do início da fila (dequeue)
int qDestroy(Queue *q);             // destroy uma fila vazia

#endif