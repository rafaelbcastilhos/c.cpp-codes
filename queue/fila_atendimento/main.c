#include <stdio.h>
#include "queue.h"

#define QSZ 50

int main(void){
    int contador = 0;
    char op;
	Queue_t n, p;

    q_init(&n, QSZ);
    q_init(&p, QSZ);

    do{
        printf("\nfila normal:\n");
        q_show(&n);
        printf("\nfila prioritaria:\n");
        q_show(&p);

        printf("\nopcoes:\n");
        printf("\tn: atendimento normal\n\tp: atendimento prioritario\n\tc: proximo da fila\n\tq: sair\n");
        printf("->");
        scanf(" %c", &op);

		switch(op){
			case 'n':
				gerar_senha_normal(&n);
				break;
			case 'p':
				gerar_senha_prioritaria(&p);
				break;
			case 'c':
                if(!q_empty(&p) || !q_empty(&n)){
                    chamar_proximo(&n, &p, contador);
                    contador++;
                }
                else{
                    contador = 0;
                    printf("nao ha senhas para serem chamadas...\n");
                }
                break;
            case 'q':
				printf("finalizando...\n");
				break;
			default:
				printf("opcao invalida...\n");
        }
	}while(op!='q');

	q_destroy(&n);
	q_destroy(&p);
    return 0;
}