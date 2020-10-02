#define DIM 100

typedef struct {
	char *items;
	int topo;
	int tam;
} pilha_t;

int inicia(pilha_t *, int);

char empilha(pilha_t *, char *);

char desempilha(pilha_t *, char *);

int cheia(pilha_t *);

int vazia(pilha_t *);

void libera(pilha_t *);