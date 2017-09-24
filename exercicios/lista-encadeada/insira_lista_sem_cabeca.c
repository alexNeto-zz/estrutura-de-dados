/*
 * INSIRA LISTA SEM CABEÇA
 * Escreva uma função que insira uma nova célula
 * numa dada posição de uma lista encadeada sem
 * cabeça. (Será preciso tomar algumas decisões
 * de projeto antes de começar a programar).
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct aux {
    int valor;
    struct aux *prox;
} elemento;

typedef elemento *pont;

typedef struct {
    pont inicio;
} lista;


int tamanho(lista *l) {
    pont end = l->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

pont buscaSequencialExc(lista *l, int posicao, pont *ant) {
    *ant = NULL;
    pont atual = l->inicio;
    int tam = 0;
    while ((atual != NULL) && (tam < tamanho(l))){
        *ant = atual;
        atual = atual->prox;
        tam++;
    }
    if ((atual != NULL))
        return atual;
    return NULL;
}

void inserirOrdem(lista *l, int posicao, int valor) {
    pont ant, i;
    i = buscaSequencialExc(l, posicao, &ant);
    if (i != NULL) {
        printf("Valor já existe");
        return;
    }
    i = (pont) malloc(sizeof(elemento));
    i->valor = valor;
    if (ant == NULL) {
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
    printf("Valor adicionado com sucesso");
    return;
}