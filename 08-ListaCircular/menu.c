/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Lista Circular Encadeada (Circular Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "csllist.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    SLList *csll;
    int n, resultado, opcao = 0, listaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar lista\n");
        printf("|| 2. Inserir primeiro item da lista\n");
        printf("|| 3. Inserir ultimo item da lista\n");
        printf("|| 4. Inserir um item depois de elemento especificado da lista\n");
        printf("|| 5. Remover item especificado da lista\n");
        printf("|| 6. Mostrar todos os elementos da lista\n");
        printf("|| 7. Destruir lista vazia\n");
        printf("|| 8. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (listaCriada == FALSE)
            {
                csll = csllCreate();
                if (csll != NULL)
                {
                    listaCriada = TRUE;
                }
            }
            else
            {
                printf("\nVoce ja possui uma lista criada!");
            }
            break;

        case 2:
            if (listaCriada)
            {
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione item como primeiro elemento da lista: ");
                scanf("%d", &a->cod);

                teste = csllInsertFirst(csll, (void *)a);
                if (teste == TRUE)
                {
                    printf("\nElemento inserido!");
                }
                else
                {
                    printf("\nNao foi possivel inserir o elemento!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 3:
            if (listaCriada)
            {
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione item como ultimo elemento da lista: ");
                scanf("%d", &a->cod);

                teste = csllInsertLast(csll, (void *)a);
                if (teste == TRUE)
                {
                    printf("\nElemento inserido!");
                }
                else
                {
                    printf("\nNao foi possivel inserir o elemento!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 4:
            if (listaCriada)
            {
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione item na lista: ");
                scanf("%d", &a->cod);
                printf("\nApos qual item voce deseja inserir esse elemento: ");
                scanf("%d", &spec->cod);

                teste = csllInsertAfterSpec(csll, (void *)&spec->cod, (void *)a, cmp);
                if (teste == TRUE)
                {
                    printf("\nElemento inserido!");
                }
                else
                {
                    printf("\nNao foi possivel inserir o elemento!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 5:
            if (listaCriada)
            {
                Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                Aluno *a;
                printf("\nDigite o elemento voce deseja retirar: ");
                scanf("%d", &spec->cod);
                a = csllRemoveSpec(csll, (void *)&spec->cod, cmp);

                if (a != NULL)
                {
                    printf("\nElemento %d foi retirado da lista!", a->cod);
                }
                else
                {
                    printf("\nNao foi possivel retirar o elemento da lista!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 6:
            if (listaCriada)
            {
                if (csll->first != NULL)
                {
                    int aux = 1;
                    Aluno *a;
                    SLNode *node;
                    node = csll->first;
                    a = (Aluno *)node->data;
                    printf("\nElemento %d: %d", aux, a->cod);
                    while (node->next != csll->first)
                    {
                        aux++;
                        node = node->next;
                        a = (Aluno *)node->data;
                        printf("\nElemento %d: %d", aux, a->cod);
                    }
                }
                else
                {
                    printf("\nNao ha elementos na lista!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 7:
            if (listaCriada)
            {
                teste = csllDestroy(csll);
                if (teste == TRUE)
                {
                    printf("\nLista Destruida!");
                    listaCriada = FALSE;
                }
                else
                {
                    printf("\nNao foi possivel destruir a lista!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 8:
            if (listaCriada)
            {
                printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            }
            break;
        default:
            printf("\n\nDigite uma opcao valida!\n\n");
        }

    } while (opcao != 8);

    return 0;
}

int cmp(void *data, void *key)
{
    int *id = (int *)data;
    int *chave = (int *)key;

    if (*id == *chave)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
