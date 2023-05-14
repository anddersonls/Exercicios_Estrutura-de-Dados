/*------------------------------------------------
menu.c
Arquivo com o menu de acesso as funcionalidades do
TAD Fila Circular
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cqueue.h"

#define TRUE 1
#define FALSE 0

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    CQueue *q;
    int n, resultado, opcao = 0, filaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar fila circular\n");
        printf("|| 2. Inserir um item na fila circular\n");
        printf("|| 3. Remover um item da fila circular\n");
        printf("|| 4. Mostrar primeiro item da fila\n");
        printf("|| 5. Mostrar todos os itens na fila\n");
        printf("|| 6. Verificar se a fila circular esta vazia\n");
        printf("|| 7. Destruir a fila circular\n");
        printf("|| 8. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (filaCriada == FALSE)
            {
                printf("\nTamanho da fila circular: ");
                scanf("%d", &n);
                q = qcCreate(n);
                if (q != NULL)
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

                teste = qcEnqueue(q, (void *)a);
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

                a = (Aluno *)qcDequeue(q);
                if (a != NULL)
                {
                    printf("\nElemento %d foi retirado da fila!", a->cod);
                }
                else
                {
                    printf("\nNao foi possivel retirar o primeiro elemento da fila!");
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
                Aluno *a;
                a = (Aluno *)qcFirst(q);
                if (a != NULL)
                {
                    printf("\nElemento do topo: %d", a->cod);
                }
                else
                {
                    printf("\nNao foi possivel mostrar o item no inicio da fila");
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
                if (q->nElms > 0)
                {
                    Aluno *a;
                    a = (Aluno *)qcFirst(q);
                    int elemento, aux = 0;
                    elemento = q->front;
                    while (aux < q->nElms)
                    {
                        aux++;
                        a = (Aluno *)q->elms[elemento];
                        printf("\nElemento %d: %d", aux, a->cod);
                        elemento = incCirc(elemento, q->maxItens);
                    }
                }
                else
                {
                    printf("\nNao ha itens na fila");
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
                teste = qcIsEmpty(q);
                if (teste == TRUE)
                {
                    printf("\nA fila esta vazia!");
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
                teste = qcDestroy(q);
                if (teste == TRUE)
                {
                    printf("\nFila Destruida!");
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
