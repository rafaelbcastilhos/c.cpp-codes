#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	pilha_t pilha;
    inicia(&pilha, DIM);

    char palavra[DIM];
    printf("palavra: ");
    scanf(" %s", palavra);
	int tamPalavra = strlen(palavra);

	// empilha enquanto indice menor que o tamanho da palavra
    for (int i = 0; i < tamPalavra; i++)
        empilha(&pilha, palavra[i]);

	char i;
    printf("invertido: ");
	// desempilha enquanto pilha nao estiver vazia
	while(!vazia(&pilha)){
		desempilha(&pilha, &i);
		printf("%c ", i);
	}

	printf("\n");
	libera(&pilha);

	return 0;
}