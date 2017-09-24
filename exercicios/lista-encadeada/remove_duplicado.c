/*
 * REMOVE DUPLICADOS
 * Escreva um código que remova elementos duplicados
 * em um a lista encadeada não ordenada.
 * Suponha a lista com cabeça.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tempRegistro {
    int valor;
    struct tempRegistro *prox;
} elemento;

typedef elemento *pont;

typedef struct {
    pont cabeca;
} lista;


void inicializaLista(lista *l);

void inseriInicio(lista *l, int valor);

void exibiLista(lista *l);

void excluirElemento(lista *l, int valor);

void achaDuplicado(lista *l);

pont buscaSeqExc(lista *l, int valor, pont *ant);

int main(void) {
    lista *l = (lista *) malloc(sizeof(lista));
    inicializaLista(l);
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        inseriInicio(l, rand() % 20);
    }
    exibiLista(l);
    achaDuplicado(l);
    exibiLista(l);

    return 0;
}

void inicializaLista(lista *l) {
    l->cabeca = (pont) malloc(sizeof(elemento));
    l->cabeca->prox = l->cabeca;
}

void inseriInicio(lista *l, int valor) {
    pont novo = (pont) malloc(sizeof(elemento));
    novo->prox = l->cabeca->prox;
    l->cabeca->prox = novo;
    novo->valor = valor;
}

void exibiLista(lista *l) {
    pont end = l->cabeca->prox;
    printf("Lista: \" ");
    while (end != l->cabeca) {
        printf("%d ", end->valor);
        end = end->prox;
    }
    printf("\"\n");
}

pont buscaSeqExc(lista *l, int valor, pont *ant) {
    *ant = l->cabeca;
    pont atual = l->cabeca->prox;
    l->cabeca->valor = valor;
    while (atual->valor != valor) {
        *ant = atual;
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->valor == valor)
        return atual;
    return NULL;
}

void excluirElemento(lista *l, int valor) {
    pont ant, i;
    i = buscaSeqExc(l, valor, &ant);
    if (i == NULL)
        return;
    ant->prox = i->prox;
    free(i);
    return;
}

void achaDuplicado(lista *l) {

    pont out = l->cabeca->prox;
    while (out != l->cabeca) {
        pont in = l->cabeca->prox;
        while (in != l->cabeca) {
            if (out->valor == in->valor && out != in) {
                printf("in: %d\n", in->valor);
                excluirElemento(l, in->valor);
                in = in->prox;
            } else {
                in = in->prox;
            }
        }
        out = out->prox;
    }
}