#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
	int valor;
}registro;

typedef struct{
	registro A[MAX];
	int numeroElemento;
}lista;

void iniciaLista(lista* l){
	l->numeroElemento = 0;
}

int numeroElemento(lista* l){
	return l->numeroElemento;
}

void exibeLista(lista* l){
	printf("Lista: \" ");
	for(int i = 0; i < l->numeroElemento; i++)
		printf("%d ", l->numeroElemento);
	printf("\"\n");
}

int buscaSequencial(lista* l, int valor){
	int i = 0;
	while(i < l->numeroElemento){
		if(valor == l->A[i].valor)
			return i;
		else
			i++;
	}
	return -1;
}

bool inserirElemento(lista* l, registro regm int i){
	if((l->numeroElemento == MAX) || (i < 0) || (i > l->numeroElemento))
		return false;
	for(int j = l->numeroElemento; j > i; j--)
		l->A[j] = l->A[j - 1];
	l->A[i] = reg;
	l->numeroElemento++;
	return true;
}
	
bool excluiElemento(int valor, lista* l){
	int pos, j;
	pos = buscaSequencial(l, valor);
	if(pos == -1)
		return false;
	for(j = pos; j < l->numeroElemento - 1; j++)
		l->A[j] = l->A[j + 1];
	l->numeroElemento--;
	return true;
}

void reiniciaLista(lista* l){
	l->numeroElemento = 0;
}
