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
    int aux = 10;
    char num[7];
    int timeBest[4], timeBest_d[4], timeWrost[4], timeWrost_d[4];
    int discBest[4], discBest_d[4], discWrost[4], discWrost_d[4];
    for (int k = 0; k < 5; k++)
    {
        timeWrost[k]=0;
        timeWrost_d[k]=0;
        discWrost[k]=0;
        discWrost_d[k]=0;

        aux*=10;
        char entrada[100]="Entrada/";
        strcat(entrada, itoa(aux));
        strcat(entrada, ".txt");
        FILE *fp = fopen(entrada, "r");
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
    }
printf("
-------------------------------------------------------------------------------\n
                       |    Number of disks\n
               | Worst  | Best |   Worst-Fit   |  Best-Fit     |    Running time\n
     N         | Fit    | Fit  |   Decreasing  |  Decreasing   |     (seconds)\n
---------------|--------|------|---------------|---------------|--------------------\n
    100        |%06d  |%06d|%06d         |%06d         |%.06f/%.06f/%.06f/%.06f\n
   1000        |%06d  |%06d|%06d         |%06d         |%.06f/%.06f/%.06f/%.06f\n
  10000        |%06d  |%06d|%06d         |%06d         |%.06f/%.06f/%.06f/%.06f\n
 100000        |%06d  |%06d|%06d         |%06d         |%.06f/%.06f/%.06f/%.06f\n
---------------|--------|------|---------------|---------------|--------------------
(Challenge)    |%08d|%08d|%08d|%08d|%.06f/%.06f/%.06f/%.06f\n
1000000        |        |      |               |               |
---------------|--------|------|---------------|---------------|--------------------
");
    fclose(fp);
    free(entrada);
    return 0;
}