/*------------------------------------------------
queue.c
Arquivo com a definição das funções do TAD Fila
Circular
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct _queue_ CQueue;
CQueue *qcCreate(int max);
int qcEnqueue(CQueue *q, void *elm);
void *qcDequeue(CQueue *q);
void *qcFirst(CQueue *q);
int qcDestroy(CQueue *q);
int qcIsEmpty(CQueue *q);
int incCirc(int i, int max);
int decCirc(int i, int max);

#endif