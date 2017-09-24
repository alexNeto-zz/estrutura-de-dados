/*
 * VETOR PARA LISTA
 * Escreva uma função que copie um vetor para uma lista encadeada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "ccabeca.h"

#define TAMANHO 33

int main(void){

    int vetor[TAMANHO];
    srand(time(NULL));
    printf("Vetor:");
    for(int i = 0; i < TAMANHO; i++){
        vetor[i] = rand() % 100;
        printf(" %d", vetor[i]);
    }
    printf("\n");
    listaCC* l = (listaCC*) malloc(sizeof(listaCC));
    iniciaCC(l);
     for(int i = 0; i < TAMANHO; i++)
       if(!inserirCC(l, vetor[i]))
           printf("Valor repetido %d\n", vetor[i]);
    exibirIteCC(l);

    return 0;
}

