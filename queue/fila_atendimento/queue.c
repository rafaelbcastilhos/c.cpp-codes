#include "queue.h"

int q_init(Queue_t *q, int sz) {
    q->maxsz = sz;
    q->data = malloc(sizeof(int) * sz);
    q->front = -1;
    q->rear = -1;

    return (q->data == NULL);
}

int q_empty(Queue_t *q) {
    return (q->front == - 1);
}

int q_full(Queue_t *q) {
    return (q->rear == q->maxsz - 1);
}

int q_enqueue(Queue_t *q, int value) {
    if (q->front == -1) q->front = 0;

    if (q_full(q)) return 0;

    q->rear++;
    q->data[q->rear] = value;

    return 1;
}

int q_dequeue(Queue_t *q, int *value) {
    (*value) = q->data[q->front];

    if (q_empty(q)) return 0;

    for (int i = 0; i < q->rear; i++) q->data[i] = q->data[i + 1];

    q->rear--;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }

    return 1;
}

int q_size(Queue_t *q) {
    return q->rear + 1;
}

void q_show(Queue_t *q) {
    for (int i = 0; i<q_size(q); i++) {
        printf("%d; ", q->data[i]);
    }
}

void q_destroy(Queue_t *q) {
    free(q->data);
}

void gerar_senha_normal(Queue_t *n) {
    int senha_normal;
    printf("gerando senha normal...\n");

    if(q_size(n) == 0) senha_normal = 100;

    else{
        senha_normal = n->data[n->rear];
        senha_normal++;
    }

    q_enqueue(n, senha_normal);
    printf("a senha normal e: %d\n", senha_normal);
}

void gerar_senha_prioritaria(Queue_t *p) {
    int senha_prioritaria;
    printf("gerando senha prioritaria...\n");

    if(q_size(p) == 0) senha_prioritaria = 200;

    else{
        senha_prioritaria = p->data[p->rear];
        senha_prioritaria++;
    }

    q_enqueue(p, senha_prioritaria);
    printf("a senha prioritaria e: %d\n", senha_prioritaria);
}

void chamar_proximo(Queue_t *n, Queue_t *p, int contador) {
    int v;
    printf("chamando o proximo da fila...\n");

    if(!q_empty(p) && contador %2 == 0)
        q_dequeue(p, &v);

    else if(!q_empty(n) && contador %2 == 1)
        q_dequeue(n, &v);

    else if(!q_empty(p) && q_empty(n))
        q_dequeue(p, &v);

    else if(q_empty(p) && !q_empty(n))
        q_dequeue(n, &v);

    printf("senha removida: %d\n", v);
}