#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int inicia(pilha_t *pilha, int tam){
	// aloca memoria de acordo com o tamanho
	pilha->items = malloc(sizeof(int)* tam);
	if(pilha->items == NULL)
		return 0;

	pilha->topo = -1;
	pilha->tam = tam;
	return 1;
}

char empilha(pilha_t *pilha, char* valor){
	// se pilha nao estiver cheia, empilha
	if(cheia(pilha))
		return 0;
	else{
		pilha->topo++;
		pilha->items[pilha->topo] = valor;
	}
	return 1;
}

char desempilha(pilha_t *pilha, char *valor){
	// se pilha nao estiver vazia, desempilha
	if(vazia(pilha))
		return 0;
	else{
		(*valor) = pilha->items[pilha->topo];
		pilha->topo--;
	}
	return 1;
}

int cheia(pilha_t *pilha){
	// se topo for igual a tamanho, esta cheia
	if(pilha->topo == pilha->tam)
		return 1;
	return 0;
}

int vazia(pilha_t *pilha){
	// se topo for igual a -1, esta vazia
	if(pilha->topo == -1)
		return 1;
	return 0;
}

void libera(pilha_t *pilha){
	// elimina a pilha
	free(pilha->items);
}