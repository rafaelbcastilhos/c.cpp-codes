#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct {
	int *items;
	int top;
	int stsize;
} stack_t;

int st_init(stack_t *, int);

int st_menu();

int st_calculadora(stack_t *);

int st_empty(stack_t *);

int st_full(stack_t *);

int st_push(stack_t *, int );

int st_pop(stack_t *, int);

int st_peek(stack_t*);

void st_destroy(stack_t *);


#endif // STACK_H_INCLUDED
