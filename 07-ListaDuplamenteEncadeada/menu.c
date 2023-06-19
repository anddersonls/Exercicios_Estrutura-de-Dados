/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Lista Duplamente Encadeada (Doubly Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dllist.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);
int myfree(void *data);

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    DLList *dll;
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
        printf("|| 5. Inserir um item antes de elemento especificado da lista\n");
        printf("|| 6. Remover item especificado da lista\n");
        printf("|| 7. Mostrar todos os elementos da lista\n");
        printf("|| 8. Destruir lista vazia\n");
        printf("|| 9. Destruir lista nao vazia\n");
        printf("|| 10. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (listaCriada == FALSE)
            {
                dll = dllCreate();
                if (dll != NULL)
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

                teste = dllInsertAsFirst(dll, (void *)a);
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

                teste = dllInsertAsLast(dll, (void *)a);
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

                teste = dllInsertAfterSpec(dll, (void *)&spec->cod, (void *)a, cmp);
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
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione item na lista: ");
                scanf("%d", &a->cod);
                printf("\nAntes qual item voce deseja inserir esse elemento: ");
                scanf("%d", &spec->cod);

                teste = dllInsertBeforeSpec(dll, (void *)&spec->cod, (void *)a, cmp);
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
        case 6:
            if (listaCriada)
            {
                Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                Aluno *a;
                printf("\nDigite o elemento voce deseja retirar: ");
                scanf("%d", &spec->cod);
                a = dllRemoveSpec(dll, (void *)&spec->cod, cmp);

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
        case 7:
            if (listaCriada)
            {
                if (dll->first != NULL)
                {
                    int aux = 0;
                    Aluno *a;
                    DLNode *node;
                    node = dll->first;
                    while (node != NULL)
                    {
                        aux++;
                        a = (Aluno *)node->data;
                        printf("\nElemento %d: %d", aux, a->cod);
                        node = node->next;
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
        case 8:
            if (listaCriada)
            {
                teste = dllDestroy(dll);
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
        case 9:
            if (listaCriada)
            {
                teste = dllDestroyNotEmpty(dll, myfree);
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
        case 10:
            if (listaCriada)
            {
                printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            }
            break;
        default:
            printf("\n\nDigite uma opcao valida!\n\n");
        }

    } while (opcao != 10);

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

int myfree(void *data)
{
    return FALSE;
}