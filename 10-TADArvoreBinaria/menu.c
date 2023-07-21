/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Árvore Binária de Pesquisa (Binary Search Tree)
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

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    TNode *raiz = NULL;
    Aluno *a;
    int n, resultado, opcao = 0, listaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Inserir item na Arvore Binaria de Busca\n");
        printf("|| 2. Remover item especificado na Arvore Binaria de Busca\n");
        printf("|| 3. Mostrar todos os elementos da na Arvore Binaria de Busca\n");
        printf("|| 4. Destruir a Arvore Binaria de Busca\n");
        printf("|| 5. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            a = (Aluno *)malloc(sizeof(Aluno));
            printf("\nAdicione item na arvore: ");
            scanf("%d", &a->cod);

            raiz = abpInsert(raiz, (void *)a, cmp);
            if (raiz != NULL)
            {
                printf("\nElemento inserido!");
            }
            else
            {
                printf("\nNao foi possivel inserir o elemento!");
            }
            break;
        case 2:
            if (raiz != NULL)
            {
                Aluno *chave = (Aluno *)malloc(sizeof(Aluno));
                printf("\nDigite o elemento voce deseja retirar: ");
                scanf("%d", &chave->cod);
                void *data;
                raiz = abpRemove(raiz, (void *)&chave->cod, cmp, &data);
                printf("kkkkkkk\n");
                printf("\nElemento %d foi retirado da lista!", chave->cod);
            }
            break;
        case 3:
            if (raiz != NULL)
            {
                simetrico(raiz, visit);
            }
            else
            {
                printf("Primeiro insira algum elemento na árvore!");
            }
        case 4:
            break;
        case 5:
            printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            break;
        default:
            printf("\n\nDigite uma opcao valida!\n\n");
        }
    } while (opcao != 5);

    return 0;
}

int cmp(void *data, void *key)
{
    int *newdata = (int *)data;
    int *node = (int *)key;

    if (*newdata > *node)
    {
        return 1;
    }
    else if (*newdata < *node)
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
    int *dado = (int *)data;
    printf("\nDado: %d", *dado);
}