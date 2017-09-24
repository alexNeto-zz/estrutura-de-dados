#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
    // outros campos
} registro;

typedef struct aux {
    registro reg;
    struct aux *prox;
} elemento;

typedef elemento *pont;

typedef struct {
    pont inicio;
} lista;


void inicializaLista(lista *l);
int tamanho(lista *l);
void exibirLista(lista *l);
pont buscaSequencial(lista *l, int ch);
pont buscaSequencialOrd(lista *l, int ch);
pont buscaSequencialExc(lista *l, int ch, pont *ant);
bool inserirOrdem(lista *l, registro reg);
bool excluiElementoLista(lista *l, int ch);
void reinicializaLista(lista* l);

int main(void){
    lista* l = (lista*) malloc(sizeof(lista));
    inicializaLista(l);
    for (int i = 0; i < 20; ++i) {
        registro reg;
        reg.chave = i;
        inserirOrdem(l, reg);
    }
    exibirLista(l);
    
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
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

pont buscaSequencial(lista *l, int ch) {
    pont pos = l->inicio;
    while (pos != NULL) {
        if (pos->reg.chave == ch)
            return pos;
        pos = pos->prox;
    }
    return NULL;
}

pont buscaSequencialOrd(lista *l, int ch) {
    pont pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch)
        pos = pos->prox;
    if (pos != NULL && pos->reg.chave == ch)
        return pos;
    return NULL;
}

pont buscaSequencialExc(lista *l, int ch, pont *ant) {
    *ant = NULL;
    pont atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave < ch)) {
        *ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.chave == ch))
        return atual;
    return NULL;
}

bool inserirOrdem(lista *l, registro reg) {
    int ch = reg.chave;
    pont ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i != NULL)
        return false;
    i = (pont) malloc(sizeof(elemento));
    i->reg = reg;
    if (ant == NULL) {
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

bool excluiElementoLista(lista *l, int ch) {
    pont ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i == NULL)
        return false;
    if (ant == NULL)
        l->inicio = i->prox;
    else
        ant->prox = i->prox;
    free(i);
    return true;
}

void reinicializaLista(lista* l){
    pont end = l->inicio;
    while(end != NULL){
        pont apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}
