#include <stdio.h>
#include <stdlib.h>
#include "banco_registradores.h"

int main(void){
	pilha_t p;
	pilha_t temp;

	int regs[4] = {0,0,0,0};
	int op, val, i, saida, contador;

	inicia(&p, TAM_P);
	inicia(&temp, TAM_TEMP);

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
				printf("desempilha antiga: ");
				while(!vazia(&p)){
					retira(&p, &saida);
					printf("\n%d ", saida);
					insere(&temp, saida);
				}
				printf("\n");

				for(i = 0; i < TAM_P; i++)
					insere(&p, regs[i]);

				printf("\nsalvo em memoria");

				break;
			case 5:
				printf("desempilha temp: ");
				for(i = 0; i < TAM_P; i++){
					if(!vazia(&temp)){
						retira(&temp, &saida);
						printf("\n%d ", saida);
						regs[i] = saida;
					}

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
