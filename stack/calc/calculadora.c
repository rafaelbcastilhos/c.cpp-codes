#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int st_init(stack_t *s, int size){
	s->items = malloc(sizeof(int)*size);
	if(s->items == NULL) {
		return 0;
	}
	s->top = -1;
	s->stsize = size;
	return 1;
}

int st_menu(){
    int opc;
    printf(" [1] - somar\n [2] - empilhar resultado atual\n [3] - retornar resultado anterior\n [4] - desempilhar\n [5] - sair\n-->");
    scanf("%d", &opc);

    return opc;
}

int st_calculadora(stack_t *s){
    int num1, num2;
    printf("entre com num1: ");
    scanf("%d", &num1);

    printf("entre com num2: ");
    scanf("%d", &num2);

    return num1 + num2;
}

int st_empty(stack_t *s){
	if(s->top == 0){
		return 1;
	}
	else {
		return 0;
	}
}

int st_full(stack_t *s){
	if(s->top == s->stsize){
		return 1;
	}
	else {
		return 0;
	}
}

int st_push(stack_t *s, int aux){
	if(st_full(s)){
		return 0;
	}
	else{
		s->top++;
		s->items[s->top] = aux;
	}
	return 1;
}

int st_pop(stack_t *s, int data){
	if(st_empty(s)){
		return 0;
	}
	else{
		data = s->items[s->top-1];
		s->top--;
	}
	return 1;
}

int st_peek(stack_t *s){
    if(s->items[s->top] == NULL)
        return 0;
    else
        return s->items[s->top];
}

void st_destroy(stack_t *s){
	free(s->items);
}
