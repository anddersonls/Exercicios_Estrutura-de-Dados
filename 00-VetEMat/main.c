#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Prova 2022.1: Questão 1
int MultiplicaMatrizPelaTRansposta(int *v1, int *v2, int *v3, int n);
// Prova 20XX(1): Questão 2
int MultiplicaV1porV2(int *v1, int *v2, int *v3, int n);

int main()
{
    int n = 3, m = 3;
    int *vet1 = malloc((n * m) * sizeof(int));
    int *vet2 = malloc((n * m) * sizeof(int));
    int *vet3 = malloc((n * m) * sizeof(int));

    for (int i = 0; i < n * m; i++)
    {
        vet1[i] = 1 + rand() % 10;
    }

    for (int i = 0; i < n * m; i++)
    {
        vet2[i] = 1 + rand() % 10;
    }

    for (int i = 0; i < n * m; i++)
    {
        printf("%d ", vet1[i]);
    }
    printf("\n");
    for (int i = 0; i < n * m; i++)
    {
        printf("%d ", vet2[i]);
    }

    // MultiplicaMatrizPelaTRansposta(vet1, vet2, vet3, n);
    MultiplicaV1porV2(vet1, vet2, vet3, n);

    for (int i = 0; i < n * m; i++)
    {
        printf("\n%d ", vet3[i]);
    }
}

// Prova 2022.1: Questão 1
/*Receber duas matrizes nxn armazenadas nos vetores v1 e v2 e , calcule
uma nova matriz a ser armazenada no vetor v3 que corresponde a
multiplicação da matriz v1 pela transposta de v2*/
int MultiplicaMatrizPelaTRansposta(int *v1, int *v2, int *v3, int n)
{
    int aux = 0;
    if (v1 != NULL && v2 != NULL && v3 != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    aux += v1[i * n + k] * v2[j * n + k];
                }
                v3[i * n + j] = aux;
                aux = 0;
            }
        }
        return TRUE;
    }
    return FALSE;
}

// Prova 20XX(1): Questão 2
/*Escreva um algoritmo que recebe duas matrizes A e B nxn
armazenadas nos vetores v1 e v2, e retorna o vetor v3 com
o resultado da multiplicação da matriz A pela matriz B*/
int MultiplicaV1porV2(int *v1, int *v2, int *v3, int n)
{
    if (v1 != NULL && v2 != NULL && v3 != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v3[i * n + j] = 0;
                for (int k = 0; k < n; k++)
                {
                    v3[i * n + j] += v1[i * n + k] * v2[k * n + j];
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}