/*------------------------------------------------
stack.h
Arquivo com a especificação para o TAD Pilha,
tipo de dado com disciplina de acesso LIFO, último
que entra é o primeiro que sai
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#ifndef __STACK_H
#define __STACK_H

typedef struct _stack_ Stack;
Stack *stkCreate(int max);
int stkPush(Stack *s, void *elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int stkIsEmpty(Stack *s);
int stkDestroy(Stack *s);

#endif