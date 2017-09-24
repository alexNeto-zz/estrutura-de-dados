/*
 * REMOVA  LISTA  SEM  CABEÇA
 * Escreva uma função que remova uma determinada célula
 * de uma lista encadeada sem cabeça.
 * (Será preciso tomar algumas decisões de projeto
 * antes de começar a programar).
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no* prox;
}elemento;

typedef elemento* pont;

typedef struct {
    pont inicio;
} lista;

void excluiElementoLista(lista *l, int valor) {
    pont ant, i;
    ant = NULL;
    pont atual = l->inicio;
    while ((atual != NULL) && (atual->valor < valor)) {
        ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->valor == valor))
        i = atual;
    if (i == NULL)
       printf("Não há nada a se deletar");
    if (ant == NULL)
        l->inicio = i->prox;
    else
        ant->prox = i->prox;
    free(i);
    printf("Item deletado com sucesso");
}