#include "best.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct best_fit Best_fit;

struct best_fit
{
    int tamanho;
    Best_fit *prox;
    Best_fit *ant;
};

Best *cria_lista();
Best *insere_bloco(Best_fit *bloco, Best *lista);
Best *ordena_bloco_lista(Best_fit *bloco, Best *lista);
void deleta_lista(Best *lista);

Best_fit *cria_bloco(int num);
Best_fit *escolhe_maior(Best_fit *bloco, int numero, int qtd_disco);
Best_fit *deleta_bloco(Best_fit *bloco);

int best_fit(int *vetor, int tmn_vetor)
{
    Best *lista = NULL;
    Best_fit *aux = NULL;
    if (tmn_vetor <= 0)
        return 0;

    lista = cria_lista();
    Best_fit *bloco = cria_bloco(0);
    insere_bloco(bloco, lista);
    int qtd_discos = 1;
    int numero;
    Best_fit *test = NULL;

    for (int i = 0; i < tmn_vetor; i++)
    {
        numero = vetor[i];
        aux = escolhe_maior((Best_fit *)lista->prim, numero, lista->qtd_disco);
        if (aux == NULL)
        {
            aux = cria_bloco(numero);

            lista = insere_bloco(aux, lista);

            //lista = ordena_bloco_lista(aux, lista);
            qtd_discos += 1;
        }
        else
        {
            aux->tamanho += numero;
            //lista = ordena_bloco_lista(aux, lista);
        }
    }
    deleta_lista(lista);
    return qtd_discos;
}

Best *cria_lista()
{
    Best *aux = (Best *)malloc(sizeof(Best));
    aux->prim = NULL;
    aux->ult = NULL;
    aux->qtd_disco=0;
    return aux;
}

Best_fit *cria_bloco(int num)
{
    Best_fit *aux = (Best_fit *)malloc(sizeof(Best_fit));
    aux->tamanho = num;
    aux->prox = NULL;
    aux->ant = NULL;
}

Best *insere_bloco(Best_fit *bloco, Best *lista)
{
    Best_fit *aux = NULL;
    if (lista->prim == NULL)
    {
        lista->prim = bloco;
        lista->ult = bloco;
    }
    else
    {
        aux = (Best_fit *)lista->ult;
        aux->prox = bloco;
        bloco->ant = aux;
        lista->ult = bloco;
    }
    lista->qtd_disco+=1;
    return lista;
}

Best_fit *escolhe_maior(Best_fit *bloco, int numero, int qtd_disco)
{
    Best_fit *aux = bloco, *retorno = NULL;
    int soma = 0;
    while (aux != NULL)
    {
        if (aux->tamanho + numero <= 1000000 && aux->tamanho + numero > soma)
        {
            retorno = aux;
            soma = aux->tamanho + numero;
            aux = aux->prox;
        }
        else
            aux=aux->prox;
    }
    return retorno;
}

void deleta_lista(Best *lista)
{
    Best_fit *aux = (Best_fit *)lista->prim;
    while (aux != NULL)
    {
        aux = deleta_bloco(aux);
    }
    free(lista);
}

Best_fit *deleta_bloco(Best_fit *bloco)
{
    Best_fit *aux = bloco->prox;
    free(bloco);
    return aux;
}

/*Best *ordena_bloco_lista(Best_fit *bloco, Best *lista)
{
    Best_fit *ant = bloco->ant, *aux = bloco;
    if (ant == NULL)
        return lista;
    while (ant->tamanho < bloco->tamanho)
    {
        aux = ant;
        ant = ant->ant;
        if (ant == NULL)
            break;
    }
    if (aux == bloco)
        return lista;
    if (aux->ant == NULL)
    {
        if (bloco->prox == NULL)
        {
            bloco->ant->prox = NULL;
            lista->ult = bloco->ant;

            bloco->ant = NULL;
            aux->ant = bloco;
            bloco->prox = aux;
            lista->prim = bloco;
        }
        else
        {

            bloco->ant->prox = bloco->prox;
            bloco->prox->ant = bloco->ant;
            bloco->ant = NULL;
            bloco->prox = aux;
            aux->ant = bloco;
            lista->prim = bloco;
        }
    }
    else
    {
        if (bloco->prox == NULL)
        {
            lista->ult = bloco->ant;
            bloco->ant->prox = NULL;
            bloco->ant = aux->ant;
            bloco->prox = aux;
            aux->ant->prox = bloco;
            aux->ant = bloco;
        }
        else
        {
            bloco->ant->prox = bloco->prox;
            bloco->prox->ant = bloco->ant;
            bloco->prox = aux;
            bloco->ant = aux->ant;
            aux->ant->prox = bloco;
            aux->ant = bloco;
        }
    }
    return lista;
}*/
