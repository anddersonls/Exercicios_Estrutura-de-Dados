/*------------------------------------------------
main.c
Arquivo com o menu de acesso as funcionalidades do
TAD Fila
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Queue *q;
    int n, resultado, opcao = 0, filaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar fila\n");
        printf("|| 2. Inserir um item na fila\n");
        printf("|| 3. Remover um item da fila\n");
        printf("|| 4. Mostrar itens da fila\n");
        printf("|| 5. Verificar se a fila esta vazia\n");
        printf("|| 6. Destruir a fila\n");
        printf("|| 7. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (filaCriada == FALSE)
            {
                printf("\nTamanho da fila: ");
                scanf("%d", &n);
                q = qCreate(n);
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

                teste = qEnqueue(q, (void *)a);
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

                a = (Aluno *)qDequeue(q);
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
                int numItens = q->rear;
                for (int i = 0; i <= numItens; i++)
                {
                    Aluno *a;
                    a = q->item[i];
                    printf("\nElemento[%d]: %d", i, a->cod);
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
                teste = qIsEmpty(q);
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

        case 6:
            if (filaCriada)
            {
                teste = qDestroy(q);
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

        case 7:
            if (filaCriada)
            {
                printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            }
            break;

        default:
            printf("\n\nDigite uma opcao valida!\n\n");
        }

    } while (opcao != 7);

    return 0;
}
