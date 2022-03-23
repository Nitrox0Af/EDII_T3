#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "worstFit.h" 
#include "bestFit.h"

int main(int args, char** argv){
    //? Variaveis para rodar mais de um teste seguido
    //double timeBF[4] = {0,0,0,0}, timeBFO[4] = {0,0,0,0}, timeWF[4] = {0,0,0,0}, timeWFO[4] = {0,0,0,0};
    //int discBF[4] = {0,0,0,0}, discBFO[4] = {0,0,0,0}, discWF[4] = {0,0,0,0}, discWFO[4] = {0,0,0,0};
    //clock_t t; //variável para armazenar tempo
    //double time = 0;
    //char *nome_entrada[4] = {"100", "1000", "10000", "100000"};

    //?Variaveis para rodar apenas 1 teste
    int n_linhas, wf, wfo, bf, bfo;

    //!argv[0] = executável
    //!argv[1] = caminho do arquivo de entrada

    //for (int k = 0; k < 4; k++){

        /*char entrada[100]="Entrada/";
        strcat(entrada, nome_entrada[k]);
        strcat(entrada, ".txt");
        char entrada[100]="\0";
        strcpy(entrada, argv[1]);
        strcat(entrada, nome_entrada[k]);
        strcat(entrada, ".txt");
        FILE* f = fopen(entrada, "r");*/


        FILE* f = fopen(argv[1], "r");
            if (f == NULL){
                printf("ERRO: Arquivo não foi aberto\n");
                return 0;
            }

        fscanf(f, "%d\n", &n_linhas);
        
        int * lista_tam = (int*)malloc(sizeof(int) * n_linhas);
        int i = 0, item = 0;

        //?leitura das linhas do arquivo
            while(i < n_linhas){
                fscanf(f, "%d\n", &lista_tam[i]);
                i++;
            }

        
        //! Calcula o minimo de pacotes necessário
        //int min = minPacotes(lista_tam, n_linhas);
        //printf("MIN:    %d\n\n", min);

        //! 1) --------------- WORST FIT ------------
        /*    t = clock();
        discWF[k] = worstFit(lista_tam, n_linhas);
            t = clock() - t; //tempo final - tempo inicial
            timeWF[k] = ((double)t)/((CLOCKS_PER_SEC));
        //printf("1   %f>>> %d >>>>\n", timeWF[k], discWF[k]);*/
            wf = worstFit(lista_tam, n_linhas);

        
        //! 2) --------------- BEST FIT ------------
            /*t = clock();
        discBF[k] = best_fit(lista_tam, n_linhas);
            t = clock() - t;
            timeBF[k] = ((double)t) / ((CLOCKS_PER_SEC)); // tempo em segundos
        //printf("2   %f>>> %d >>>>\n", timeBF[k], discBF[k]);*/
            bf = best_fit(lista_tam, n_linhas);
        
        //! 3) --------------- WORST FIT ORDENADO ------------
            /*t = clock();
        discWFO[k] = worstFitOrdenado(lista_tam, n_linhas);
            t = clock() - t; //tempo final - tempo inicial
            timeWFO[k] = ((double)t)/((CLOCKS_PER_SEC));
        //printf("3   %f>>> %d >>>>\n", timeWFO[k], discWFO[k]);*/
            wfo = worstFitOrdenado(lista_tam, n_linhas);

        //! 4) --------------- BEST FIT ORDENADO ------------
           /* t = clock(); //armazena tempo
        discBFO[k] = bestFitOrdenado(lista_tam, n_linhas);
            t = clock() - t;
            timeBFO[k] = ((double)t) / ((CLOCKS_PER_SEC)); //tempo em segundos
        //printf("4   %f>>> %d >>>>\n", timeBFO[k], discBFO[k]);*/
            bfo = bestFitOrdenado(lista_tam, n_linhas);

        //!Imprime: WORST FIT -> BEST FIT -> WORST FIT ORDENADO -> BEST FIT ORDENADO
        printf("%d\n%d\n%d\n%d\n", wf, bf, wfo, bfo);
        
        free(lista_tam);
        fclose(f);
    //}

    /*FILE* saida = fopen("saida.txt", "w");
    fprintf(saida,"-------------------------------------------------------------------------------\n");
    fprintf(saida,"                       |    Number of disks\n");
    fprintf(saida,"               | Worst  | Best |   Worst-Fit   |  Best-Fit     |    Running time\n");
    fprintf(saida,"     N         | Fit    | Fit  |   Decreasing  |  Decreasing   |     (seconds)\n");
    fprintf(saida,"---------------|--------|------|---------------|---------------|--------------------\n");
    fprintf(saida,"    100        |%6.d  |%6.d|    %6.d     |    %6.d     |       %.6f       \n", discWF[0], discBF[0], discWFO[0], discBFO[0], (timeWF[0]+timeBF[0]+ timeWFO[0]+timeBFO[0]));
    fprintf(saida,"   1000        |%6.d  |%6.d|    %6.d     |    %6.d     |       %.6f       \n", discWF[1], discBF[1], discWFO[1], discBFO[1], (timeWF[1]+ timeBF[1]+ timeWFO[1]+timeBFO[1]));
    fprintf(saida,"  10000        |%6.d  |%6.d|    %6.d     |    %6.d     |       %.6f       \n", discWF[2], discBF[2], discWFO[2], discBFO[2], (timeWF[2]+ timeBF[2]+ timeWFO[2]+timeBFO[2]));
    fprintf(saida," 100000        |%6.d  |%6.d|    %6.d     |    %6.d     |       %.6f       \n", discWF[3], discBF[3], discWFO[3], discBFO[3], (timeWF[3]+ timeBF[3]+ timeWFO[3]+timeBFO[3]));
    fprintf(saida,"---------------|--------|------|---------------|---------------|--------------------\n");
    fprintf(saida,"(Challenge)    |--------|------|---------------|---------------|--------------------\n");
    fprintf(saida,"1000000        |        |      |               |               |\n");
    fprintf(saida,"---------------|--------|------|---------------|---------------|--------------------");
    fprintf(saida,"\n\ntempo do Worst Fit para 100: %.6f\n",timeWF[0]);
    fprintf(saida,"tempo do Worst Fit para 1000: %.6f\n",timeWF[1]);
    fprintf(saida,"tempo do Worst Fit para 10000: %.6f\n", timeWF[2]);
    fprintf(saida,"tempo do Worst Fit para 100000: %.6f\n", timeWF[3]);
    fprintf(saida,"tempo do Best Fit para 100: %.6f\n",timeBF[0]);
    fprintf(saida,"tempo do Best Fit para 1000: %.6f\n",timeBF[1]);
    fprintf(saida,"tempo do Best Fit para 10000: %.6f\n",timeBF[2]);
    fprintf(saida,"tempo do Best Fit para 100000: %.6f\n",timeBF[3]);
    fprintf(saida,"tempo do Worst Fit Decreasing para 100: %.6f\n", timeWFO[0]);
    fprintf(saida,"tempo do Worst Fit Decreasing para 1000: %.6f\n", timeWFO[1]);
    fprintf(saida,"tempo do Worst Fit Decreasing para 10000: %.6f\n", timeWFO[2]);
    fprintf(saida,"tempo do Worst Fit Decreasing para 100000: %.6f\n", timeWFO[3]);
    fprintf(saida,"tempo do Best Fit Decreasing para 100: %.6f\n", timeBFO[0]);
    fprintf(saida,"tempo do Best Fit Decreasing para 1000: %.6f\n", timeBFO[1]);
    fprintf(saida,"tempo do Best Fit Decreasing para 10000: %.6f\n", timeBFO[2]);
    fprintf(saida,"tempo do Best Fit Decreasing para 100000: %.6f\n", timeBFO[3]);
    fclose(saida);*/
    return 0;
}