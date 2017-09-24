/*
 * LISTA CRESCENTE
 * Uma lista é crescente se o conteúdo de cada célula
 * não é maior que o conteúdo da célula seguinte.
 * Escreva uma função que faça uma busca em uma lista
 * crescente. Faça versões para listas com e sem cabeça.
 * Faça uma versão recursiva e outra iterativa
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ccabeca.h"
#include "scabeca.h"

void listaSemCabeca();
void listaComCabeca();
void linha(int tamanho);

int main(void){

    linha(100);
    printf("\nLista encadeada sem cabeça\n");
    listaSemCabeca();
    linha(100);

    printf("\n\n");

    linha(100);
    printf("\nLista encadeada com cabeça\n");
    listaComCabeca();
    linha(100);

    printf("\n\n");

    return 0;
}

void listaSemCabeca(){
    lista* l = (lista*) malloc(sizeof(lista));
    iniciaSC(l);
    for(int i = 33; i > 0; i-- )
        if(inserirSC(l, i));
        else
            return;
    exibirIteSC(l);
    pont exibe = l->inicio;
    exibirRecSC(exibe);
    free(l);
}

void listaComCabeca(){
    listaCC* l = (listaCC*) malloc(sizeof(listaCC));
    iniciaCC(l);
    for (int i = 33; i > 0 ; i--)
        if(inserirCC(l, i));
        else
            return;
    exibirIteCC(l);
    pontCC exibe = l->cabeca;
    exibirRecCC(exibe, l);
    free(l);
}

void linha(int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("=");
}