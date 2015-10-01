#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main() {

    #ifdef PILHA_LISTA
        printf("\n\nPilha de Lista Encadeada\n");
    #else
        printf("\n\nPilha de Vetor\n");
    #endif

    // Cria o no inicial da pilha
    pilhaNode pilha = NULL;
    pilhaValue pv = NULL;
    int opcao, valor;
    float fvalor;

    do {
    	printf("Digite uma opcao:\n\n");
    	printf("1. PUSH\n");
    	printf("2. POP\n");
    	printf("3. TOP\n");
    	printf("4. SAIR\n");
    	printf("Opcao desejada: ");

    	scanf("%d", &opcao);

    	switch (opcao) {
    		case 1:
    			printf("Digite o valor para PUSH: ");
                pv = (pilhaValue) malloc(sizeof(pilhaValue));
                if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                    scanf("%d", &valor);
                    pv->value = valor;
                }
                pilhaNode new = push(pilha, pv);
                if(new == NULL)
                    printf("Impossível inserir, pilha cheia!\n");
                else
                    pilha = new;
    		break;
    		case 2:
                pv = NULL;

                if(pilha != NULL)
                    pv = pop(&pilha);

                if(pv != NULL) {
                    if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                        printf("Valor POP: %d\n", pv->value);
                    }
                }
    			else
    				printf("Pilha vazia!\n");
    		break;
    		case 3:
                pv = top(pilha);
                if(pilha != NULL && pv != NULL) {
                    if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                        printf("Valor TOP: %d\n", pv->value);
                    }
                }
    			else
    				printf("Pilha vazia!\n");
    		break;
    		case 4:
    			exit(1);
    		break;
    		default:
    		break;
    	}

    } while (1);

    return 0;
}
