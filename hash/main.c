#include <stdio.h>
#include "hash.h"

void menu(void){
    printf("\n### Tabela Hash de Produtos ###\n");
    printf("\nOpções:");
    printf("\n1 - Cadastrar produto");
    printf("\n2 - Consultar produto por tipo");
    printf("\n3 - Verificar quantidade de produtos por tipo");
    printf("\n4 - Sair");
    printf("\n--> ");
}

int main(void){
	struct Hash *head = NULL;
    int op = 0, value = 0;

    do{
        menu();
        scanf("%d", &op);

		switch(op){
			case 1:
                add(&head);
				break;
			case 2:
                search(head);
				break;
			case 3:
                count(head);
                break;
            case 4:
				printf("Finalizando...\n");
				break;
			default:
				printf("Opcao invalida...\n");
        }
	}while(op != 4);

    return 0;
}
