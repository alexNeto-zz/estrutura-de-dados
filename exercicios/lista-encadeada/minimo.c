/*
 * MÍNIMO
 * Escreva uma função que encontre uma célula de conteúdo mínimo.
 * Faça duas versões:uma iterativa e outra recursiva.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct aux {
    int valor;
    struct aux *prox;
} elemento;

typedef elemento *pont;

typedef struct {
    pont inicio;
} lista;


void inicializaLista(lista *l);

int tamanho(lista *l);

void exibirLista(lista *l);

void mostrarMinimo(lista *l);

int mostraMinimoRecursivo(pont end);

void inseriInicio(lista *l, int valor);

int main(void) {
    lista *l = (lista *) malloc(sizeof(lista));
    inicializaLista(l);
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        inseriInicio(l, rand() % 100);
    }
    exibirLista(l);
    mostraMinimo(l);
    pont end = l->inicio;
    int minimo = mostraMinimoRecursivo(end);
    printf("Minimo: %d\n", minimo);

    return 0;
}


void inicializaLista(lista *l) {
    l->inicio = NULL;
}

int tamanho(lista *l) {
    pont end = l->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(lista *l) {
    pont end = l->inicio;
    printf("Lista: \"");
    while (end != NULL) {
        printf("%d ", end->valor);
        end = end->prox;
    }
    printf("\"\n");
}

void mostraMinimo(lista *l) {
    pont end = l->inicio;
    int minimo = end->valor;
    while (end != NULL) {
        if (end->valor < minimo)
            minimo = end->valor;
        end = end->prox;
    }
    printf("Minimo: %d\n", minimo);
}

int  mostraMinimoRecursivo(pont end){
    if (end->prox == NULL) return end->valor;
    else {
        int x;
        x = mostraMinimoRecursivo(end->prox);
        if (x < end->valor) return x;
        else return end->valor;
    }
}

void inseriInicio(lista *l, int valor) {
    pont i;
    i = (pont) malloc(sizeof(elemento));
    i->prox = l->inicio;
    l->inicio = i;
    i->valor = valor;
}
