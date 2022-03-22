#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "worstFit.h"
#define GB 1000000

int ordena(const void * a, const void *b);

void worstFit(int* lista, int qtd){
    int pacotes = 0;
    int pckg_restante[qtd]; //armazena o espaço sobrando nos pacotes
 
    for (int i = 0; i < qtd; i++) {        
        int j, space = -1, index = 0;
 
        for (j = 0; j < pacotes; j++) {
            //procura na lista de pacotes existentes o melhor para colocar o disco
            if (pckg_restante[j] >= lista[i] && pckg_restante[j] - lista[i] > space) {
                //caso seja maior que o disco a ser armazenado e for o suficiente para armazenar
                index = j;
                space = pckg_restante[j] - lista[i]; //a variável espaço recebe a diferença entre o espaço disponivel e o novo disco
            }
        }
        if(space == -1) {//caso não haja nenhuma posição com espaço suficiente 
        //cria-se um novo pacote e armazena-se e valor que vai sobrar de espaço
            pckg_restante[pacotes] = GB - lista[i];
            pacotes++;
        }
        else{ //caso tenha espaço suficiente
        //diminui naquela posição o tamanho do novo disco
            pckg_restante[index] -= lista[i];
        }
    }
    printf("%d\n", pacotes);
}

void worstFitOrdenado(int* lista, int qtd){    
    qsort(lista, qtd, sizeof(int), ordena);
    
    worstFit(lista, qtd);

}

int ordena(const void * a, const void *b){ // função específica do TAD para ser utilizada no qsort
    int* um = (int*) a;
    int* dois = (int*) b;
    if(*um < *dois){
        return 1;
    }
    else if(*um == *dois){
        return 0;
    }
    else if(*um > *dois){
        return -1;
    }
}

int minPacotes(int* lista, int qtd){
    int soma = 0;
    for(int i = 0; i < qtd; i++){
        soma = soma + lista[i];
    }
    int min = soma/GB;

    return min;
}