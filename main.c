#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "worstFit.h" 

int main(int args, char** argv){
    int n_linhas;
    clock_t t; //variável para armazenar tempo
    double time;

    //argv[0] = executável
    //argv[1] = caminho do arquivo de entrada

    FILE* f = fopen(argv[1], "r");

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

    // 1) --------------- WORST FIT ------------
    t = clock();
    worstFit(lista_tam, n_linhas);
    t = clock() - t; //!tempo final - tempo inicial
    time = ((double)t)/((CLOCKS_PER_SEC));
    //printf("%f>>> \n", time);

    // 3) --------------- WORST FIT ORDENADO ------------
    t = clock();
    worstFitOrdenado(lista_tam, n_linhas);
    t = clock() - t; //!tempo final - tempo inicial
    time = ((double)t)/((CLOCKS_PER_SEC));
    //printf("%f>>> \n", time);

    free(lista_tam);
    fclose(f);
    return 0;
    
}