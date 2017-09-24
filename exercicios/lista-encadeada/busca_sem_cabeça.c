/*
 * BUSCA  LISTA  SEM  CABEÇA
 * Escreva  uma  versão  da função Busca para listas sem cabeça
 */

typedef struct no{
    int valor;
    struct no* prox;
}elemento;

typedef elemento* pont;

pont busca(lista *l, int valor){
    pont pos = l->inicio;
    while(pos != NULL){
        if(pos->valor == valor)
            return pos;
        pos = pos->prox;
    }
    return NULL;
}
