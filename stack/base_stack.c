#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *items;
	int top;
	int stsize;
} stack_t;

int st_init(stack_t *, int);
int st_empty(stack_t *);
int st_full(stack_t *);
int st_push(stack_t *, int );
int st_pop(stack_t *, int *);
void st_destroy(stack_t *);

int main(void){
	stack_t st;
	int i;

	st_init(&st, 5);
	st_push(&st, 10);
	st_push(&st, 20);
	st_push(&st, 30);
	st_push(&st, 40);

	while(!st_empty(&st)){
		st_pop(&st,&i);
		printf("dt: %d\n", i);
	}
	
	st_destroy(&st); 

	return 0;
}

int st_init(stack_t *s, int size){
	s->items = malloc(sizeof(int)*size);
	if(s->items == NULL) {
		return 0;
	}
	s->top = -1;
	s->stsize = size;
	return 1;
}

int st_empty(stack_t *s){
	if(s->top == -1){
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

int st_push(stack_t *s, int data){
	if(st_full(s)){
		return 0;
	}
	else{
		s->top++;
		s->items[s->top] = data;
	}
	return 1;
}

int st_pop(stack_t *s, int *data){
	if(st_empty(s)){
		return 0;
	}
	else{
		(*data) = s->items[s->top];
		s->top--;
	}
	return 1;
}

void st_destroy(stack_t *s){
	free(s->items);
}