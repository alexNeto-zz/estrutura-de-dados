/*
 * LISTA PARA VETOR
 * Escreva uma função que copie uma lista encadeada para um vetor.
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "ccabeca.h"

#define TAMANHO 33

int main(void){


    listaCC* l = (listaCC*) malloc(sizeof(listaCC));
    iniciaCC(l);
    srand(time(NULL));
    for(int i = 0; i < TAMANHO; i++)
        if(!inserirCC(l, (rand() % 100)))
           i--;
    exibirIteCC(l);


    int vetor[TAMANHO];
    printf("Vetor:");
    pontCC end = l->cabeca->prox;
    for(int i = 0; i < tamanhoCC(l); i++){
        if(end == l->cabeca)
            break;
        vetor[i] = end->valor;
        printf(" %d", vetor[i]);
        end = end->prox;
    }
    printf("\n");

    return 0;
}

