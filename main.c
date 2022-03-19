#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char** argv){
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("ERRO: Arquivo não foi aberto\n");
        return 0;
    }

    int tam_arq;
    fscanf(fp, "%d\n", &tam_arq);
    int* entrada = (int*)malloc(sizeof(int) * tam_arq);

    for(int i = 0; i<tam_arq; i++){
        fscanf(fp, "%d\n", &entrada[i]);
    }

    return 0;
}