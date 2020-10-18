#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
	struct node *head;

	init_ll(&head, 10);

	printf("Inicializando lista:\n");
	print_ll(head);

	printf("Alocando 20:\n");
	insert_front_ll(&head, 20);
	print_ll(head);

	printf("Removendo 10:\n");
	remove_item_ll(head, 10);
	print_ll(head);

	return 0;
}
