/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Fila Encadeada (Linked Stack)
---------------------------------------------------
Autor: Anderson Lopes Silva
June/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lqueue.h"

#define TRUE 1
#define FALSE 0

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    LLQueue *llq;
    int n, resultado, opcao = 0, filaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar fila\n");
        printf("|| 2. Inserir um item na fila\n");
        printf("|| 3. Remover um item da fila\n");
        printf("|| 4. Mostrar primeiro elemento da fila\n");
        printf("|| 5. Mostrar todos os elementos da fila\n");
        printf("|| 6. Verificar se a fila esta vazia\n");
        printf("|| 7. Destruir a fila\n");
        printf("|| 8. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (filaCriada == FALSE)
            {
                llq = llqCreate();
                if (llq != NULL)
                {
                    filaCriada = TRUE;
                }
            }
            else
            {
                printf("\nVoce ja possui uma fila criada!");
            }
            break;

        case 2:
            if (filaCriada)
            {
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione um elemento na fila: ");
                scanf("%d", &a->cod);

                teste = llqEnqueue(llq, (void *)a);
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
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;
        case 3:
            if (filaCriada)
            {
                Aluno *a;

                a = (Aluno *)llqDequeue(llq);
                if (a != NULL)
                {
                    printf("\nElemento %d foi retirado da fila!", a->cod);
                }
                else
                {
                    printf("\nNao foi possivel retirar o elemento do topo da fila!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;
        case 4:
            if (filaCriada)
            {
                if (llq->front != NULL)
                {
                    Aluno *a;
                    a = (Aluno *)llqFirst(llq);
                    printf("\nElemento do topo: %d", a->cod);
                }
                else
                {
                    printf("\nNao ha elementos na fila!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;
        case 5:
            if (filaCriada)
            {
                if (llq->front != NULL)
                {
                    int aux = 0;
                    Aluno *a;
                    SLNode *node;
                    node = llq->front;
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
                    printf("\nNao ha elementos na fila!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;
        case 6:
            if (filaCriada)
            {
                teste = llqIsEmpty(llq);
                if (teste == TRUE)
                {
                    printf("\nFila vazia!");
                }
                else
                {
                    printf("\nA fila nao esta vazia!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;
        case 7:
            if (filaCriada)
            {
                teste = llqDestroy(llq);
                if (teste == TRUE)
                {
                    printf("\nfila Destruida!");
                    filaCriada = FALSE;
                }
                else
                {
                    printf("\nNao foi possivel destruir a fila!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma fila!");
            }
            break;

        case 8:
            if (filaCriada)
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
