#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "worstFit.h" 
#include "bestFit.h"

int main(int args, char** argv){
    double timeBF[4] = {0,0,0,0}, timeBFO[4] = {0,0,0,0}, timeWF[4] = {0,0,0,0}, timeWFO[4] = {0,0,0,0};
    int discBF[4] = {0,0,0,0}, discBFO[4] = {0,0,0,0}, discWF[4] = {0,0,0,0}, discWFO[4] = {0,0,0,0};
    int n_linhas;
    clock_t t; //variável para armazenar tempo
    double time = 0;
    char *nome_entrada[4] = {"100", "1000", "10000", "100000"};

    //argv[0] = executável
    //argv[1] = caminho do arquivo de entrada

    for (int k = 0; k < 4; k++){

        //char entrada[100]="Entrada/";
        //strcat(entrada, nome_entrada[k]);
        //strcat(entrada, ".txt");

        char entrada[100]="\0";
        strcpy(entrada, argv[1]);
        strcat(entrada, nome_entrada[k]);
        strcat(entrada, ".txt");

        FILE* f = fopen(entrada, "r");
            if (f == NULL){
                printf("ERRO: Arquivo não foi aberto\n");
                return 0;
            }

        fscanf(f, "%d\n", &n_linhas);
        
        int * lista_tam = (int*)malloc(sizeof(int) * n_linhas);
        int i = 0, item = 0;

        //leitura das linhas do arquivo
            while(i < n_linhas){
                fscanf(f, "%d\n", &lista_tam[i]);
                i++;
            }

        //int min = minPacotes(lista_tam, n_linhas);
        //printf("MIN:    %d\n\n", min);

        //! 1) --------------- WORST FIT ------------
            t = clock();
        discWF[k] = worstFit(lista_tam, n_linhas);
            t = clock() - t; //tempo final - tempo inicial
            timeWF[k] = ((double)t)/((CLOCKS_PER_SEC));
        //printf("1   %f>>> %d >>>>\n", timeWF[k], discWF[k]);

        
        //! 2) --------------- BEST FIT ------------
            t = clock();
        discBF[k] = best_fit(lista_tam, n_linhas);
            t = clock() - t;
            timeBF[k] = ((double)t) / ((CLOCKS_PER_SEC)); // tempo em segundos
        //printf("2   %f>>> %d >>>>\n", timeBF[k], discBF[k]);
        
        //! 3) --------------- WORST FIT ORDENADO ------------
            t = clock();
        discWFO[k] = worstFitOrdenado(lista_tam, n_linhas);
            t = clock() - t; //tempo final - tempo inicial
            timeWFO[k] = ((double)t)/((CLOCKS_PER_SEC));
        //printf("3   %f>>> %d >>>>\n", timeWFO[k], discWFO[k]);

        //! 4) --------------- BEST FIT ORDENADO ------------
            t = clock(); //armazena tempo
        discBFO[k] = bestFitOrdenado(lista_tam, n_linhas);
            t = clock() - t;
            timeBFO[k] = ((double)t) / ((CLOCKS_PER_SEC)); //tempo em segundos
        //printf("4   %f>>> %d >>>>\n", timeBFO[k], discBFO[k]);
        
        free(lista_tam);
        fclose(f);
    }
    
    FILE* saida = fopen("saida.txt", "w");
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

    fclose(saida);
    return 0;
    
}