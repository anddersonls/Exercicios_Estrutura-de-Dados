/*------------------------------------------------
main.c
Arquivo com o menu de acesso as funcionalidades do
TAD Pilha
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

typedef struct _aluno_
{
    int cod;
} Aluno;

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Stack *s;
    int n, resultado, opcao = 0, pilhaCriada = 0, teste;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar pilha\n");
        printf("|| 2. Inserir um item na pilha\n");
        printf("|| 3. Remover um item da pilha\n");
        printf("|| 4. Mostrar elemento do topo da pilha\n");
        printf("|| 5. Mostrar todos os elementos da pilha\n");
        printf("|| 6. Verificar se a pilha esta vazia\n");
        printf("|| 7. Destruir a pilha\n");
        printf("|| 8. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (pilhaCriada == FALSE)
            {
                printf("\nTamanho da pilha: ");
                scanf("%d", &n);
                s = stkCreate(n);
                if (s != NULL)
                {
                    pilhaCriada = TRUE;
                }
            }
            else
            {
                printf("\nVoce ja possui uma pilha criada!");
            }
            break;

        case 2:
            if (pilhaCriada)
            {
                Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                printf("\nAdicione um elemento na pilha: ");
                scanf("%d", &a->cod);

                teste = stkPush(s, (void *)a);
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
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;
        case 3:
            if (pilhaCriada)
            {
                Aluno *a;

                a = (Aluno *)stkPop(s);
                if (a != NULL)
                {
                    printf("\nElemento %d foi retirado da pilha!", a->cod);
                }
                else
                {
                    printf("\nNao foi possivel retirar o elemento do topo da pilha!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;
        case 4:
            if (pilhaCriada)
            {
                if (s->top >= 0)
                {
                    Aluno *a;
                    a = (Aluno *)stkTop(s);
                    printf("\nElemento do topo: %d", a->cod);
                }
                else
                {
                    printf("\nNao ha elementos na pilha!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;
        case 5:
            if (pilhaCriada)
            {
                if (s->top >= 0)
                {
                    int aux = 0;
                    Aluno *a;
                    for (int i = s->top; i >= 0; i--)
                    {
                        aux++;
                        a = (Aluno *)s->item[i];
                        printf("\nElemento %d: %d", aux, a->cod);
                    }
                }
                else
                {
                    printf("\nNao ha elementos na pilha!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;
        case 6:
            if (pilhaCriada)
            {
                teste = stkIsEmpty(s);
                if (teste == TRUE)
                {
                    printf("\nPilha vazia!");
                }
                else
                {
                    printf("\nA pilha nao esta vazia!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;

        case 7:
            if (pilhaCriada)
            {
                teste = stkDestroy(s);
                if (teste == TRUE)
                {
                    printf("\nPilha Destruida!");
                    pilhaCriada = FALSE;
                }
                else
                {
                    printf("\nNao foi possivel destruir a pilha!");
                }
            }
            else
            {
                printf("\nATENCAO: antes de utilizar as operacoes voce deve primeireiramente criar uma pilha!");
            }
            break;

        case 8:
            if (pilhaCriada)
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
