#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "best.h"

int comparador(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("ERRO: Arquivo não foi aberto\n");
        return 0;
    }

    int tam_arq;
    fscanf(fp, "%d\n", &tam_arq);
    int *entrada = (int *)malloc(sizeof(int) * tam_arq);

    clock_t t; // variável para armazenar tempo
    double time;

    for (int i = 0; i < tam_arq; i++)
    {
        fscanf(fp, "%d\n", &entrada[i]);
    }

    t = clock(); //! armazena tempo
    int num = best_fit(entrada, tam_arq);
    t = clock() - t;
    time = ((double)t) / ((CLOCKS_PER_SEC)); //! tempo em segundos
    printf("best fit: %f (s) // discos: %d\n", time, num);

    printf("best fit ");
    qsort(entrada, tam_arq, sizeof(int), comparador);
    t = clock(); //! armazena tempo
    num = best_fit(entrada, tam_arq);
    t = clock() - t;
    time = ((double)t) / ((CLOCKS_PER_SEC)); //! tempo em segundos
    printf("best fit D: %f (s) // discos: %d\n", time, num);

    fclose(fp);
    free(entrada);
    return 0;
}