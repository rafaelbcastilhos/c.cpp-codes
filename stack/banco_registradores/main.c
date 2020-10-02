#include <stdio.h>
#include <stdlib.h>
#include "banco_registradores.h"

int main(void){
	// declaracao das variaveis das pilhas
	pilha_t p;
	pilha_t temp;

	int regs[4] = {0,0,0,0};
	int op, val, i, saida, contador;

	// inicia pilha principal com tamanho 4
	inicia(&p, TAM_P);
	// inicia pilha temporaria com tamanho 16
	inicia(&temp, TAM_TEMP);

	// empilha regs iniciais
	for(i = 0; i < TAM_P; i++)
		insere(&p, regs[i]);

	do{
		mostraRegs(regs);
		menu();
		printf("digite opcao:");
		scanf("%d",&op);

		switch(op){
			case 0:
			case 1:
			case 2:
			case 3:
				printf("digite o valor para o reg[%d]:",op);
				scanf("%d", &regs[op]);
				printf("\no registrador R[%d] foi alterado para: %d",
					op, regs[op]);

				break;
			case 4:
				// desempilha principal antiga/inicial
				printf("desempilha antiga: ");
				while(!vazia(&p)){
					retira(&p, &saida);
					printf("\n%d ", saida);

					// insere antiga em temporaria
					insere(&temp, saida);
				}
				printf("\n");

				// empilha atual
				for(i = 0; i < TAM_P; i++)
					insere(&p, regs[i]);

				printf("\nsalvo em memoria");

				break;
			case 5:
				// desempilha temp
				printf("desempilha temp: ");
				// a cada entrada no case 5
				// desempilha os 4 elementos do topo da pilha
				for(i = 0; i < TAM_P; i++){
					// enquanto nao estiver vazia
					if(!vazia(&temp)){
						retira(&temp, &saida);
						printf("\n%d ", saida);
						regs[i] = saida;
					}

					// caso pilha temporaria esiver vazia
					// nao e possivel retornar aos registradores
					// entao os registradores voltam a estaca zero
					else
						regs[i] = 0;
				}
				printf("\n\nretornando ao ultimo estado");

				break;
			case -1: break;
			default:
				printf("opcao invalida!\n");
		}
		printf("\n\n");
	}while(op!=-1);	
	return 0;
}