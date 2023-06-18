/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Lista Simplesmente Encadeada (Single Linked List)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sllist.h"

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
    SLList *sll;
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
        printf("|| 6. Remover primeiro item da lista\n");
        printf("|| 7. Remover ultimo item da lista\n");
        printf("|| 8. Remover item especificado da lista\n");
        printf("|| 9. Mostrar todos os elementos da lista\n");
        printf("|| 10. Verificar se a lista esta vazia\n");
        printf("|| 11. Destruir a lista\n");
        printf("|| 12. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (listaCriada == FALSE)
            {
                sll = sllCreate();
                if (sll != NULL)
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

                teste = sllInsertFirst(sll, (void *)a);
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

                teste = sllInsertLast(sll, (void *)a);
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

                teste = sllInserftAfterSpecQuery(sll, (void *)&spec->cod, (void *)a, cmp);
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

                teste = sllInsertBefSpec(sll, (void *)&spec->cod, (void *)a, cmp);
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
                Aluno *a;
                a = (Aluno *)sllRemoveFirst(sll);
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
                Aluno *a;
                a = (Aluno *)sllRemoveLast(sll);
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
        case 8:
            if (listaCriada)
            {
                Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                Aluno *a;
                printf("\nDigite o elemento voce deseja retirar: ");
                scanf("%d", &spec->cod);
                a = sllRemoveSpec(sll, (void *)&spec->cod, cmp);

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
        case 9:
            if (listaCriada)
            {
                if (sll->first != NULL)
                {
                    int aux = 0;
                    Aluno *a;
                    SLNode *node;
                    node = sll->first;
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
        case 10:
            if (listaCriada)
            {
                teste = sllIsEmpty(sll);
                if (teste == TRUE)
                {
                    printf("\nLista vazia!");
                }
                else
                {
                    printf("\nA lista nao esta vazia!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma lista!");
            }
            break;
        case 11:
            if (listaCriada)
            {
                teste = sllDestroy(sll);
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
        case 12:
            if (listaCriada)
            {
                printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            }
            break;

        default:
            printf("\n\nDigite uma opcao valida!\n\n");
        }

    } while (opcao != 12);

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
