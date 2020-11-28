#include "hash.h"
#include <string.h>

int add(struct Hash **head){
    struct Hash *temp = (struct Hash *) malloc(sizeof(struct Hash));
    char type;
    char description[50];

    printf("A - Alimentacao\n");
    printf("H - Higiene\n");
    printf("L - Limpeza\n");
    printf("V - Vestuario\n");
    printf("--> ");
    scanf(" %c", &type);

    if(type != 'A' && type != 'H' && type != 'L' && type != 'V'){
        printf("Tipo invalido!\n");
        return 0;
    }

    printf("Descricao: ");
    scanf(" %s", description);

	if(temp == NULL)
		return 0;

	temp->produto.type = type;
    strcpy(temp->produto.description, description);
	temp->next = (*head);
	(*head) = temp;

    return 1;	
}

void search(struct Hash *head){
	struct Hash *temp = head;
    char type;
    int aux = 0;

    printf("Tipo: ");
    scanf(" %c", &type);

    for(temp = head; temp != NULL; temp = temp->next){
        if(temp->produto.type == type){
            aux = 1;
            printf("%s\n", temp->produto.description);
        }
    }

    if(aux == 0)
        printf("\nNao existem produtos do tipo %c!\n", type);
}

void count(struct Hash *head){
	struct Hash *temp = head;
    int countA = 0, countH = 0, countL = 0, countV = 0;
	
    printf("Quantidade:\n");
    while (temp != NULL) {
        if(temp->produto.type == 'A')
            countA++;
        if(temp->produto.type == 'H')
            countH++;
        if(temp->produto.type == 'L')
            countL++;
        if(temp->produto.type == 'V')
            countV++;

        temp = temp->next;
	}

    printf("Alimentacao - %d produtos\n", countA);
    printf("Higiene - %d produtos\n", countH);
    printf("Limpeza - %d produtos\n", countL);
    printf("Vestuario - %d produtos\n", countV);
}
