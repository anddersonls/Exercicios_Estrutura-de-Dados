/*------------------------------------------------
exercicios.c
Arquivo com exercícios do TAD Árvore Binária de
Pesquisa (Binary Search Tree)
---------------------------------------------------
Autor: Anderson Lopes Silva
July/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "abp.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);
void visit(void *data);
// PROVA 2017_1: QUESTÃO 3
int abpCalculaDiferencaMaiorParaMenor(TNode *t, int (*getvalue)(void *));
int abpMaiorValor(TNode *t);
int abpMenorValor(TNode *t);
int getvalue(void *data);
// PROVA 2017_1: QUESTÃO 2
int abNumNosNaAlturaH(TNode *t, int h);
// PROVA 2021_2: QUESTÃO 3
int abCalcNumNosFolha(TNode *t);
// PROVA 2022_1: QUESTÃO 3
int NumNosAlturaMaiorH(TNode *t, int h);
// PROVA 2023_1(versão 1): QUESTÃO 3
int abNumNosMenorQueH(TNode *t, int h);
// Questão 7: Lista de exercícios
int abpGetAltura(TNode *t);
// Quantidade de nós no nível n
int abNumNosNoNivelN(TNode *t, int n);

int main(void)
{
    TNode *raiz = NULL;

    // 100, 50, 20, 10, 25, 80, 150, 110, 105, 170, 200
    raiz = abpInsert(raiz, (void *)100, cmp);
    raiz = abpInsert(raiz, (void *)50, cmp);
    raiz = abpInsert(raiz, (void *)20, cmp);
    raiz = abpInsert(raiz, (void *)10, cmp);
    raiz = abpInsert(raiz, (void *)25, cmp);
    raiz = abpInsert(raiz, (void *)80, cmp);
    raiz = abpInsert(raiz, (void *)150, cmp);
    raiz = abpInsert(raiz, (void *)110, cmp);
    raiz = abpInsert(raiz, (void *)105, cmp);
    raiz = abpInsert(raiz, (void *)170, cmp);
    raiz = abpInsert(raiz, (void *)200, cmp);
    simetrico(raiz, visit);
    printf("\n");
    posOrdem(raiz, visit);
    printf("\n");
    preOrdem(raiz, visit);

    int teste;
    teste = abpCalculaDiferencaMaiorParaMenor(raiz, getvalue);
    printf("\nDiferenca: %d", teste);

    teste = abNumNosNaAlturaH(raiz, 2);
    printf("\nNos na altura h: %d", teste);

    teste = abCalcNumNosFolha(raiz);
    printf("\nNumero de folhas: %d", teste);

    teste = NumNosAlturaMaiorH(raiz, 2);
    printf("\nNos na arvore maior que altura h: %d", teste);

    teste = abNumNosMenorQueH(raiz, 2);
    printf("\nNos na arvore menor que altura h: %d", teste);

    teste = abpGetAltura(raiz);
    printf("\nAltura: %d", teste);

    teste = abNumNosNoNivelN(raiz, 3);
    printf("\nNumero de nos no nivel n: %d", teste);
}

int cmp(void *data, void *key)
{
    int *newdata = (int *)data;
    int *node = (int *)key;

    if (newdata > node)
    {
        return 1;
    }
    else if (newdata < node)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void visit(void *data)
{
    int *item = (int *)data;
    printf("\nItem: %d", item);
}

// PROVA 2017_1: QUESTÃO 3
/*Escreva um algoritmo que calcula a diferença entre o maior e o menor valor existente
em uma árvore binária de pesquisa, use obrigatoriamente o protótipo do algoritmo abaixo.*/
int abpCalculaDiferencaMaiorParaMenor(TNode *t, int (*getvalue)(void *))
{
    int maior, menor;
    if (t != NULL)
    {
        menor = abpMenorValor(t);
        maior = abpMaiorValor(t);
        return maior - menor;
    }
}

int abpMenorValor(TNode *t)
{
    if (t != NULL)
    {
        if (t->left != NULL)
        {
            return abpMenorValor(t->left);
        }
        else
        {
            return getvalue(t->data);
        }
    }
}

int abpMaiorValor(TNode *t)
{
    if (t != NULL)
    {
        if (t->right != NULL)
        {
            return abpMaiorValor(t->right);
        }
        else
        {
            return getvalue(t->data);
        }
    }
}

int getvalue(void *data)
{
    int *item = (int *)data;
    int aux = item;
    return aux;
}

// PROVA 2017_1: QUESTÃO 2
/*Escreva um algoritmo que recebe a raiz de uma árvore binária e um número h
e retorna o número de nós de uma árvore binária que tem uma altura h*/
int abNumNosNaAlturaH(TNode *t, int h)
{
    if (t != NULL)
    {
        if (h == 0)
        {
            return 1;
        }
        else
        {
            int esq, dir;
            esq = abNumNosNaAlturaH(t->left, h - 1);
            dir = abNumNosNaAlturaH(t->right, h - 1);
            return esq + dir + 1;
        }
    }
    else
    {
        return 0;
    }
}

// PROVA 2021_2: QUESTÃO 3
/*Implemente um algoritmo que recebe uma arvore binária e retorna o
numero de nós de grau 0 (folhas) na arvore.*/
int abCalcNumNosFolha(TNode *t)
{
    if (t != NULL)
    {
        int soma = 0;
        if (t->left == NULL && t->right == NULL)
        {
            return 1;
        }
        else
        {
            soma += abCalcNumNosFolha(t->left);
            soma += abCalcNumNosFolha(t->right);
            return soma;
        }
    }
    else
    {
        return 0;
    }
}

// PROVA 2022_1: QUESTÃO 3
/*Escreva um algoritmo que recebe a raiz de uma arvore binária e um número h e
retorna o número de nós de uma árvore binária que tem altura maior que h.*/
int NumNosAlturaMaiorH(TNode *t, int h)
{
    if (t != NULL)
    {
        int esq, dir, nnos = 0;
        esq = NumNosAlturaMaiorH(t->left, h - 1);
        dir = NumNosAlturaMaiorH(t->right, h - 1);
        if (h < 0)
        {
            nnos = 1;
        }
        return esq + dir + nnos;
    }
    else
    {
        return 0;
    }
}

// PROVA 2023_1(versão 1): QUESTÃO 3
/*Escreva um algoritmo para calcular o número de nós de uma árvore binária que
possui altura menor que h.*/
int abNumNosMenorQueH(TNode *t, int h)
{
    if (t != NULL)
    {
        int esq, dir, num_nos = 0;
        esq = abNumNosMenorQueH(t->left, h - 1);
        dir = abNumNosMenorQueH(t->right, h - 1);
        if (h > 0)
        {
            num_nos = 1;
        }
        return esq + dir + num_nos;
    }
    else
    {
        return 0;
    }
}

// Questão 7: Lista de Exercícios
/*Altura de uma árvore binária*/
int abpGetAltura(TNode *t)
{
    if (t == NULL)
    {
        return -1;
    }

    int altEsq = abpGetAltura(t->left);
    int altDir = abpGetAltura(t->right);

    if (altEsq > altDir)
    {
        return altEsq + 1;
    }
    else
    {
        return altDir + 1;
    }
}

// Quantidade de nós no nível n
int abNumNosNoNivelN(TNode *t, int n)
{
    if (t != NULL)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            int esq, dir;
            esq = abNumNosNoNivelN(t->left, n - 1);
            dir = abNumNosNoNivelN(t->right, n - 1);
            return esq + dir;
        }
    }
    else
    {
        return 0;
    }
}