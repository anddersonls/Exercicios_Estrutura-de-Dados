/*------------------------------------------------
exercicios.c
Arquivo com exercicios do TAD Pilha
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

void mostrarPilha(Stack *s);
// lista 2 pilha, exercicio 1
int EX0Y(char *s, int n);
// Prova 2022.1: Questão 3
void RemoveMenoresQueChave(Stack *s, void *key, int *(cmp)(void *, void *));
int *cmp(void *key, void *data);

int main()
{
    /*
    int n = 6, teste;
    char *s;
    char string_origem[] = "AB0BAa";

    s = malloc(strlen(string_origem) + 1);
    strcpy(s, string_origem);
    printf("String copiada: %s\n", s);

    teste = EX0Y(s, n);
    if (teste)
    {
        printf("X=Y: TRUE");
    }
    else
    {
        printf("X=Y: FALSE");
    } */

    Stack *s;
    s = stkCreate(8);
    stkPush(s, (void *)10);
    stkPush(s, (void *)3);
    stkPush(s, (void *)6);
    stkPush(s, (void *)7);
    stkPush(s, (void *)8);
    stkPush(s, (void *)5);
    mostrarPilha(s);
    RemoveMenoresQueChave(s, (void *)4, cmp);
    printf("\n");
    mostrarPilha(s);

    return 0;
}

void mostrarPilha(Stack *s)
{
    if (s->top >= 0)
    {
        int aux = 0, *item;
        for (int i = s->top; i >= 0; i--)
        {
            aux++;
            item = (int *)s->item[i];
            printf("\nElemento %d: %d", aux, item);
        }
    }
}

/*Faca um algoritmo que recebe uma string s, de tamanho n e
verifica se ela esta no formato X0Y. Esta string tem um único
caracter 0. e a string X tem os caracteres na ordem inversa da
string Y */
int EX0Y(char *s, int n)
{
    if (s != NULL && n % 2 == 1)
    {
        if (s[n / 2] == '0')
        {
            Stack *stk;
            stk = stkCreate(n / 2);
            int verifica = TRUE;
            for (int i = 0; i < (n / 2); i++)
            {
                verifica = stkPush(stk, (void *)&s[i]);
                if (verifica == FALSE)
                {
                    break;
                }
            }
            if (verifica == TRUE)
            {
                char *c;
                int aux = TRUE;
                for (int i = (n / 2) + 1; i < strlen(s); i++)
                {
                    strcpy(c, (char *)stkPop(stk));
                    if (*c != s[i])
                    {
                        aux = FALSE;
                        break;
                    }
                }
                if (aux == TRUE)
                {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

/*Receber uma pilha armazenada em um vetor e uma chave,
e romover todos os elementos até encontrar um com chave menor
que o valor da chave recebida; não pode usar pops e pushs e
deve obedecer a disciplina de acesso da pilha*/
void RemoveMenoresQueChave(Stack *s, void *key, int *(cmp)(void *, void *))
{
    if (s != NULL)
    {
        if (s->top >= 0)
        {
            void *data;
            int *verifica;
            while (s->top >= 0)
            {
                data = s->item[s->top];
                s->top--;
                verifica = cmp(key, data);
                if (*verifica)
                {
                    s->top++;
                    s->item[s->top] = data;
                    break;
                }
            }
        }
    }
}

int *cmp(void *key, void *data)
{
    static int resultado = FALSE;
    if (data < key)
    {
        resultado = TRUE;
        return &resultado;
    }
    return &resultado;
}