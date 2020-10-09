#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int maxsz;
    int *data;
    int front;
    int rear;
} Queue_t;

int q_init(Queue_t *q, int sz);

int q_empty(Queue_t *q);

int q_full(Queue_t *q);

int q_enqueue(Queue_t *q, int value);

int q_dequeue(Queue_t *q, int *value);

int q_size(Queue_t *q);

void q_show(Queue_t *q);

void q_destroy(Queue_t *q);

void gerar_senha_normal(Queue_t *n);

void gerar_senha_prioritaria(Queue_t *p);

void chamar_proximo(Queue_t *n, Queue_t *p, int contador);