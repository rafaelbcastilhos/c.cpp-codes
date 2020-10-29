// código desenvolvido por rafael b. castilhos
// ads - ifrs, 2020. estrutura de dados - listas encadeadas
// compilar: gcc main.c linkedlist.c linkedlist.h -o linkedlist
// executar: ./linkedlist

#include <stdio.h>
#include "linkedlist.h"

void menu(void){
    printf("\n<---- lista encadeada ---->\n");
    printf("\nopções:");
    printf("\n1 - imprimir lista");
    printf("\n2 - inserir no inicio");
    printf("\n3 - inserir no final");
    printf("\n4 - remover primeiro nodo");
    printf("\n5 - remover ultimo nodo");
    printf("\n6 - buscar elemento");
    printf("\n7 - tamanho da lista");
    printf("\n8 - imprimir 'n' primeiros elementos");
    printf("\n0 - sair");
}

int main(void){
	struct Node *head = NULL;
    int op = 0, value = 0;
    do{
        //imprimir lista
        print(head);

        //entrada da opção do usuário
        menu();
        printf("\n-> ");
        scanf("%d", &op);

		switch(op){
			case 1:
                //imprimir lista
                print(head);
				break;
			case 2:
                //inserir no inicio
                printf("\ninforme elemento a ser inserido no começo: ");
                scanf("%d", &value);
                add_first(&head, value);
				break;
			case 3:
                //inserir no final
                printf("\ninforme elemento a ser inserido no final: ");
                scanf("%d", &value);
                add_last(&head, value);
                break;
			case 4:
                //remover no começo
                remove_first(&head);
                break;
			case 5:
                //remover no final
                remove_last(&head);
                break;
			case 6:
                //buscar elemento
                printf("\ninforme elemento a ser pesquisado: ");
                scanf("%d", &value);
                search(head, value);
                break;
			case 7:
                //mostrar tamanho da lista
                printf("\ntamanho: %d\n", length(head));
                break;
			case 8:
                //imprimir 'n' primeiros elementos
                printf("\ninforme quantos elementos deseja mostrar: ");
                scanf("%d", &value);
                print_nth_elements(head, value);
                break;
            case 0:
				printf("finalizando...\n");
				break;
			default:
				printf("opção inválida...\n");
        }
	}while(op!=0);

    return 0;
}