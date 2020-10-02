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

int inicia(pilha_t *p, int qtd){
	p->items = malloc(sizeof(int)*qtd);

	if(p->items == NULL) {
		return 0;
	}

	p->topo = -1;
	p->tamanho = qtd;
	return 1;
}


int vazia(pilha_t *p){
	if(p->topo == -1)
		return 1;

	return 0;
}

int cheia(pilha_t *p){
	if(p->topo == p->tamanho)
		return 1;
	return 0;
}

int insere(pilha_t *p, int elem){
	if(cheia(p))
		return 0;

	else{
		p->topo++;
		p->items[p->topo] = elem;
	}
	return 1;
}

int retira(pilha_t *p, int *elem){
	if(cheia(p))
		return 0;
	else{
		(*elem) = p->items[p->topo];
		p->topo--;
	}
	return 1;
}
