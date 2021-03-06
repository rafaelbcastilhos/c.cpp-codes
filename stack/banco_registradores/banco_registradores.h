#define TAM_P 4
#define TAM_TEMP 16

typedef struct {
	int *items;
	int topo;
	int tamanho;
} pilha_t;

void mostraRegs(int r[]);

void menu(void);

int inicia(pilha_t *p, int qtd);

int vazia(pilha_t *p);

int cheia(pilha_t *p);

int insere(pilha_t *p, int elem);

int retira(pilha_t *p, int *elem);
