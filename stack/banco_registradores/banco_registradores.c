#include <stdio.h>
#include <stdlib.h>
#include "banco_registradores.h"

void mostraRegs(int r[]){
	printf("R[0]=%d\tR[1]=%d\tR[2]=%d\tR[3]=%d\n",r[0],r[1],r[2],r[3]);
}

void menu(void){
	printf("0-3 : modifica o registrador\n");
	printf("4   : salva em memoria\n");
	printf("5   : retorna ao ultimo ponto salvo\n");
	printf("-1  : sair\n");
}

// inicia a pilha
int inicia(pilha_t *p, int qtd){
	// alocacao de memoria
	p->items = malloc(sizeof(int)*qtd);

	if(p->items == NULL) {
		return 0;
	}
	// define topooo = -1
	p->topo = -1;
	// define tamanho = parametro
	p->tamanho = qtd;
	return 1;
}

// verifica se a pilha esta vazia
int vazia(pilha_t *p){
	// se o topo for = -1, esta vazia
	if(p->topo == -1){
		return 1;
	}
	else {
		return 0;
	}
}

// verifica se a pilha esta cheia
int cheia(pilha_t *p){
	// se o topoo for = tamanho, esta cheia
	if(p->topo == p->tamanho){
		return 1;
	}
	else {
		return 0;
	}
}

// insere elemento na pilha
int insere(pilha_t *p, int elem){
	// verifica se a pilha esta cheia
	if(cheia(p)){
		return 0;
	}
	// caso contrario, o topo e incrementado
	// o item no indice do topo recebe valor
	else{
		p->topo++;
		p->items[p->topo] = elem;
	}
	return 1;
}

// remove elemento da pilha
int retira(pilha_t *p, int *elem){
	// verifica se a pilha esta vazia
	if(cheia(p)){
		return 0;
	}
	// caso contrario, parametro recebe o item no indice do topo
	// o topo e decrementado
	else{
		(*elem) = p->items[p->topo];
		p->topo--;
	}
	return 1;
}