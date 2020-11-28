// código desenvolvido por rafael b. castilhos
// ads - ifrs, 2020. estrutura de dados - listas encadeadas
// compilar: gcc main.c hash.c hash.h -o hash
// executar: ./hash

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
        //entrada da opção do usuário
        menu();
        scanf("%d", &op);

		switch(op){
			case 1:
                // cadastrar produto
                add(&head);
				break;
			case 2:
                // consultar pedido por tipo
                search(head);
				break;
			case 3:
                // verificar quantidade por tipo
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