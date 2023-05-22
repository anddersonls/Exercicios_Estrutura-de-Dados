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

// pilha dupla
typedef struct _PilhaDupla_
{
    int maxSize;
    int top1; // Topo da primeira pilha
    int top2; // Topo da segunda pilha
    void **item;
} PilhaDupla;

void mostrarPilha(Stack *s);
// lista 2 pilha, exercicio 1
int EX0Y(char *s, int n);
// Prova 2022.1: Questão 3
void RemoveMenoresQueChave(Stack *s, void *key, int *(cmp)(void *, void *));
int *cmp(void *key, void *data);
// Prova 20XX: questão 2
int EX0Y0X(char *s, int n);
// Prova 2017.1: Questão 3
int VerifyString(char *s, int n);
char *ReadChar(char *s, int i);
// Prova 2017.1: Questão 4
// Resolve qualquer problema de string do tipo x0y0x...
int VerificaString(Stack *s, char *str, int n);
// Prova 20XX(3): Questão 3
// Implementação da pilha dupla
PilhaDupla *PilhaDuplaCreate(int maxSize);
int push1(PilhaDupla *s, void *item);
int push2(PilhaDupla *s, void *item);
int pop1(PilhaDupla *s);
int pop2(PilhaDupla *s);

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

    /*Stack *s;
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
    mostrarPilha(s);*/

    int n = 15, teste;
    char *s;
    char string_origem[] = "122022101220221";
    Stack *stk;

    stk = stkCreate(n);
    s = malloc(strlen(string_origem) + 1);
    strcpy(s, string_origem);
    printf("String copiada: %s\n", s);

    // teste = EX0Y0X(s, n);
    // teste = VerifyString(s, n);
    teste = VerificaString(stk, s, n);

    if (teste)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }

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

/*Escreva um algoritmo que recebe um vetor de caracteres com somente
os caracteres 1, 2 e um único caracter 0. e o tamanho do cetor que
tem caracteres preenchidos (válidos). Este algoritmo deve verificar
se a string que está armazenada é da forma x0y0x, onde x é o inverso
de y. (se x="12221122", y ="22112221"). Todas as funções utilizadas
no algoritmo devem estar descritas na prova.*/
int EX0Y0X(char *s, int n)
{
    if (s != NULL && n > 0)
    {
        Stack *stk1, *stk2;
        stk1 = stkCreate(n);
        stk2 = stkCreate(n);
        int i = 0, qtd = 0, aux = 0;
        if (stk1 != NULL && stk2 != NULL)
        {
            while (s[i] != '0' && i < n)
            {
                stkPush(stk1, (void *)&s[i]);
                i++;
            }
            qtd = i;
            aux = qtd;
            i++;
            while (s[i] != '0' && aux > 0)
            {
                if (s[i] != *((char *)stkPop(stk1)))
                {
                    break;
                }
                stkPush(stk2, (void *)&s[i]);
                i++;
                aux--;
            }
            if (aux == 0)
            {
                i++;
                aux = qtd;
                while (s[i] != '0' && aux > 0)
                {
                    if (s[i] != *((char *)stkPop(stk2)))
                    {
                        break;
                    }
                    i++;
                    aux--;
                }
                /*se a pilha acabar e ainda sobrar caracteres no segundo X,
                então a string inicial é diferente da ultima

                se a quantidade de valores na primeira string for maior do
                que a quantidade de valores no segundo X, então a string
                inicial é diferente da ultima*/
                printf("%d", i);
                if (i == n && aux == 0)
                {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Prova 2017.1: Questão 3
/*Escreva um algoritmo para determinar se uma string de caracteres é
formada por um número de letras 'A' seguidos por igual número de letras
B. Em cada ponto você deve somente ler o próximo caractere da string com
a função ReadChar. O algoritmo deve usar pilhas pra resolver o problema
e não pode contar o número de letras 'A'*/
int VerifyString(char *s, int n)
{
    if (s != NULL)
    {
        Stack *stk = stkCreate(n);
        int i = 0;
        char *c = ReadChar(s, i);
        if (stk != NULL)
        {
            while (i < n)
            {
                while (*c == 'A' && i < n)
                {
                    stkPush(stk, (void *)&s[i]);
                    i++;
                    c = ReadChar(s, i);
                }
                while (*c == 'B' && i < n)
                {
                    stkPop(stk);
                    i++;
                    c = ReadChar(s, i);
                }
                if (stk->top == -1 && i == n)
                {
                    return TRUE;
                }
                if (*c != 'A' && *c != 'B')
                {
                    break;
                }
            }
        }
    }
    return FALSE;
}

char *ReadChar(char *s, int i)
{
    return &s[i];
}

// Prova 2017.1: Questão 4
/*Receber um vetor de caracteres com somente os caracteres 1,2 e um
único caracter 0, e o tamanho do vetor que tem caracteres preenchidos
(válidos) e usando o TAD Pilha verificar se a string recebida é da forma
x0y0x0y onde x é o inverso de y. (se x = "12221122", y ="22112221"). Não
pode usar memória auxiliar somente usar as funções do TAD (stkCreate, stkPop,
stkPPush, stkDestroy)*/
// Resolve qualquer problema de string do tipo x0y0x...
int VerificaString(Stack *s, char *str, int n)
{
    if (s != NULL && str != NULL && n > 0)
    {
        int i = 0, aux = i, verifica = TRUE, qtd = 0;
        char *c;
        while (aux < n && verifica == TRUE)
        {
            while (str[i] != '0' && i < n)
            {
                stkPush(s, (void *)&str[i]);
                i++;
                qtd++;
            }
            i++;
            aux = i;
            while (str[aux] != '0' && aux < n && verifica == TRUE && qtd > 0)
            {
                c = (char *)stkPop(s);
                if (str[aux] != *c)
                {
                    verifica = FALSE;
                    break;
                }
                qtd--;
                aux++;
            }
        }
        if (aux == n && stkIsEmpty(s) == TRUE && verifica == TRUE)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// Prova 20XX(3): Questão 3
// Implementação da Pilha Dupla
PilhaDupla *PilhaDuplaCreate(int maxSize)
{
    PilhaDupla *s;
    if (maxSize > 0)
    {
        s = (PilhaDupla *)malloc(sizeof(PilhaDupla));
        if (s != NULL)
        {
            s->item = (void **)malloc(sizeof(void *) * maxSize);
            if (s->item != NULL)
            {
                s->maxSize = maxSize;
                s->top1 = -1;
                s->top2 = maxSize;
                return s;
            }
        }
    }
    return NULL;
}

int push1(PilhaDupla *s, void *item)
{
    if (s != NULL)
    {
        if (s->top1 + 1 < s->top2)
        {
            s->top1++;
            s->item[s->top1] = item;
            return TRUE;
        }
    }
    return FALSE;
}
int push2(PilhaDupla *s, void *item)
{
    if (s != NULL)
    {
        if (s->top2 - 1 > s->top1)
        {
            s->top2--;
            s->item[s->top2] = item;
            return TRUE;
        }
    }
    return FALSE;
}

int pop1(PilhaDupla *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top1 >= 0)
        {
            aux = s->item[s->top1];
            s->top1--;
            return aux;
        }
    }
    return NULL;
}

int pop2(PilhaDupla *s)
{
    void *aux;
    if (s != NULL)
    {
        if (s->top2 < s->maxSize)
        {
            aux = s->item[s->top2];
            s->top2++;
            return aux;
        }
    }
    return NULL;
}