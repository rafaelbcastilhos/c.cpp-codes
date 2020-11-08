#include <stdio.h>
#include "abb.h"

void menu(void){
    printf("\n\n<---- arvore de busca binaria ---->");
    printf("\nopções:");
    printf("\n1 - inserir");
    printf("\n2 - remover");
    printf("\n3 - imprimir nos");
    printf("\n4 - buscar");
    printf("\n5 - quantidade de nos");
    printf("\n6 - maior valor");
    printf("\n7 - menor valor");
    printf("\n0 - sair");
}

void submenu(void){
    printf("\ncomo deseja imprimir?");
    printf("\n1 - pre ordem");
    printf("\n2 - ordem simetrica (infixa)");
    printf("\n3 - pos ordem");
}

int main(void){
    struct BstNode *raiz = NULL;
    int op = 0, valor = 0;
    do{
        printf("\narvore em pre ordem:\n");
        print_preordem(raiz);

        menu();
        printf("\n-> ");
        scanf("%d", &op);

		switch(op){
			case 1:
                printf("\ninforme valor a ser inserido: ");
                scanf("%d", &valor);
                if(buscar(raiz, valor) == 0){
                    raiz = add_no(raiz, valor);
                    printf("\nvalor %d inserido com sucesso!", valor);
                }
                else
                    printf("\nvalor %d ja esta na arvore!", valor);
				break;

			case 2:
                printf("\ninforme valor a ser removido: ");
                scanf("%d", &valor);
                if(buscar(raiz, valor) != 0){
                    raiz = remove_no(raiz, valor);
                    printf("\nvalor %d removido com sucesso!", valor);
                }
                else
                    printf("valor %d nao encontrado na arvore...", valor);
				break;

			case 3:
                submenu();
                printf("\n-> ");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        printf("\narvore em pre ordem:\n");
                        print_preordem(raiz);
                        break;
                    case 2:
                        printf("\narvore em ordem infixa:\n");
                        print_infixa(raiz);
                        break;
                    case 3:
                        printf("\narvore em pos ordem:\n");
                        print_posordem(raiz);
                        break;
                }
                break;

			case 4:
                printf("\ninforme valor a ser buscado: ");
                scanf("%d", &valor);
                if(buscar(raiz, valor) == 0)
                    printf("valor %d nao encontrado na arvore...", valor);
                else
                    printf("valor %d encontrado na arvore!", valor);
                break;

			case 5:
                printf("quantidade de nos e: %d", qtde_nos(raiz));
                break;

			case 6:
                printf("maior valor e: %d", maior(raiz));
                break;

			case 7:
                printf("menor valor e: %d", menor(raiz));
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
