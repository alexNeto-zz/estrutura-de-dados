#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
}registro;

typedef struct tempRegistro{
    registro reg;
    struct tempRegistro* prox;
}elemento;

typedef elemento* pont;

typedef struct {
    pont cabeca;
}lista;

void inicializaLista(lista* l){
    l->cabeca = (pont) malloc(sizeof(elemento));
    l->cabeca->prox = l->cabeca;
}

int tamanho(lista* l){
    pont end = l->cabeca->prox;
    int tam = 0;
    while(end != l->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibiLista(lista* l){
    pont end = l->cabeca->prox;
    printf("Lista: \" ");
    while(end != l->cabeca){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

pont buscaSentinela(lista* l, int ch){
    pont pos = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (pos->reg.chave != ch)
        pos = pos->prox;
    if(pos != l->cabeca)
        return pos;
    return NULL;
}

pont buscaSeqExc(lista* l, int ch, pont* ant){
    *ant = l->cabeca;
    pont atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != l->cabeca && atual->reg.chave == ch)
        return atual;
    return NULL;
}

bool inserirElemento(lista* l, registro reg){
    pont ant, i;
    i = buscaSeqExc(l, reg.chave, &ant);
    if(i != NULL)
        return false;
    i = (pont) malloc(sizeof(elemento));
    i->reg = reg;
    i->prox = ant->prox;
    ant->prox = i;
    return true;
}

bool excluirElemento(lista* l, int ch){
    pont ant, i;
    i = buscaSeqExc(l, ch, &ant);
    if(i == NULL)
        return false;
    ant->prox = i->prox;
    free(i);
    return true;
}

void reiniciarLista(lista* l){
    pont end = l->cabeca->prox;
    while(end != l->cabeca){
        pont apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->cabeca->prox = l->cabeca;
}