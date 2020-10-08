#define MAX 5

typedef struct {
    int rear;
    int front;
    int *data;
}queue_t;

void init(queue_t *);

void insert(queue_t *);

void delete(queue_t *);

void display(queue_t *);