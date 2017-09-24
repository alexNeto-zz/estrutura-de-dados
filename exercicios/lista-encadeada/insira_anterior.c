/*
 * INSIRA  ANTERIOR
 * Escreva uma função que insira uma nova célula entre
 * a célula cujo endereço é p e a anterior.
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

pont buscaSequencialExc(lista *l, int valor, pont *ant) {
    *ant = NULL;
    pont atual = l->inicio;
    while ((atual != NULL) && (atual->valor < valor)) {
        *ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->valor == valor))
        return atual;
    return NULL;
}

void inserirOrdem(lista *l, int valor) {
    pont ant, i;
    i = buscaSequencialExc(l, valor, &ant);
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