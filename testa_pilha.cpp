#include <stdio.h>
#include <stdlib.h>

#include "pilha_vetor.h"
#include "gtest/gtest.h"

pilhaNode pilha = NULL;
pilhaValue pv = NULL;

//int manual();

/**
* Assertiva de entrada
* Remoção de elemento de pilha vazia
*/

TEST(Pilha, PopVazio) {
    pv = NULL;
    pv = pop(&pilha);
    // Verifica se o valor retornado é um ponteiro inválido
    ASSERT_TRUE(pv == NULL);
    ASSERT_TRUE(!pv);
    ASSERT_FALSE(pv != NULL);
}

/**
* Assertiva de entrada
* Criação de nova pilha com a insercao de 1 elemento
*/

TEST(Pilha, Criacao) {
    pv = (pilhaValue) malloc(sizeof(pilhaValue));
    pv->value = 0;
    pilha = push(pilha, pv);
    ASSERT_FALSE(pilha == NULL);
    ASSERT_FALSE(!pilha);
    // TOP = NULL, no caso do primeiro elemento
    ASSERT_TRUE(pilha != NULL);
    ASSERT_TRUE(pilha);
}

/**
* Assertiva de entrada
* Insercao de 3 elementos
*/

TEST(Pilha, InsercaoElem3) {
    int i;
    for(i = 1; i <= 3; i++) {
      pv = (pilhaValue) malloc(sizeof(pilhaValue));
      pv->value = i;
      pilha = push(pilha, pv);
      // Confere se cada elemento foi inserido conforme a ordem
      //ASSERT_TRUE(pilha->value->value == i);
    }
}

/**
* Assertiva de entrada
* Verifica se o topo é o ultimo elemento inserido
*/

TEST(Pilha, TopoElem3) {
    // Confere se o ultimo elemento inserido e o topo da pilha = 3
    pv = top(pilha);
    ASSERT_EQ(pv->value, 3);
}

/**
* Assertiva de entrada
* Verifica se o pop retorna o ultimo elemento inserido
*/

TEST(Pilha, PopElem3) {
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 3);
}

/**
* Assertiva de entrada
* Verifica se o topo é o penultimo elemento inserido
*/

TEST(Pilha, TopoElem2) {
    // Confere se o penultimo elemento inserido e o topo da pilha = 2
    pv = top(pilha);
    ASSERT_EQ(pv->value, 2);
}

/**
* Assertiva de entrada
* Verifica se o pop retorna o penultimo elemento inserido
*/

TEST(Pilha, PopElem2) {
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 2);
}

/**
* Assertiva de entrada
* Verifica se o topo é o antepenultimo elemento inserido
*/

TEST(Pilha, TopoElem1) {
    // Confere se o antepenultimo elemento inserido e o topo da pilha = 1
    pv = top(pilha);
    ASSERT_EQ(pv->value, 1);
}

/**
* Assertiva de entrada
* Verifica se o pop retorna o antepenultimo elemento inserido
*/

TEST(Pilha, PopElem1) {
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 1);
}

/**
* Assertiva de entrada
* Verifica se o topo é o primeiro elemento inserido
*/

TEST(Pilha, TopoElem0) {
    // Confere se o primeiro elemento inserido e o topo da pilha = 0
    pv = top(pilha);
    ASSERT_EQ(pv->value, 0);
}

/**
* Assertiva de entrada
* Verifica se o pop retorna o primeiro elemento inserido, na criacao
*/

TEST(Pilha, PopElem0) {
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 0);
}

/**
* Assertiva de entrada
* Remoção de elemento de pilha vazia
*/

TEST(Pilha, PopElemVazio) {
    pv = NULL;
    pv = pop(&pilha);
    // Verifica se o valor retornado é um ponteiro inválido
    ASSERT_TRUE(pv == NULL);
    ASSERT_TRUE(!pv);
    ASSERT_FALSE(pv != NULL);
}

/**
* Assertiva de entrada
* Verifica o topo de pilha vazia
*/

TEST(Pilha, TopoPilhaVazia) {
    pv = top(pilha);
    ASSERT_TRUE(pv == NULL);
    ASSERT_FALSE(pv != NULL);
}

/**
* Assertiva de entrada
* Cria novamente uma pilha com a insercao de 1 elemento
* - Pilha: [0]
*/

TEST(Pilha, Criacao2) {
    pv = (pilhaValue) malloc(sizeof(pilhaValue));
    pilha = push(pilha, pv);
    pv->value = 0;
    ASSERT_FALSE(pilha == NULL);
    ASSERT_FALSE(!pilha);
    // TOP = NULL, no caso do primeiro elemento
    //ASSERT_FALSE(pilha->top);
    ASSERT_TRUE(pilha != NULL);
    ASSERT_TRUE(pilha);
    // TOP = NULL, no caso do primeiro elemento
  //  ASSERT_TRUE(!pilha->top);
    // Confere se o elemento foi inserido na pilha
    //ASSERT_TRUE(pilha->value->value == 0);
}

/**
* Assertiva de entrada
* Insere 3 elementos na nova pilha - Pilha: [0,1,2,3]
*/

TEST(Pilha, InsercaoNovo3Elem) {
    int i;
    for(i = 1; i <= 3; i++) {
      pv = (pilhaValue) malloc(sizeof(pilhaValue));
      pv->value = i;
      pilha = push(pilha, pv);
      // Confere se cada elemento foi inserido conforme a ordem
      //ASSERT_TRUE(pilha->value->value == i);
    }
    // Confere se o ultimo elemento inserido e o topo da pilha
    //ASSERT_TRUE(pilha->value->value == 3);
}

/**
* Assertiva de entrada
* Verifica se o topo é o ultimo elemento inserido
*/

TEST(Pilha, TopoNovo3Elem) {
    // Confere se o ultimo elemento inserido e o topo da pilha = 3
    pv = top(pilha);
    ASSERT_EQ(pv->value, 3);
}

/**
* Assertiva de entrada
* Verifica se o pop retorna o ultimo elemento inserido
* - Pilha: [0,1,2]
*/

TEST(Pilha, PopNovoElem3) {
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 3);
}

/**
* Assertiva de entrada
* Insere um elemento intermediario na pilha e verifica se
* o elemento foi inserido corretamente - Pilha: [0,1,2,4]
*/

TEST(Pilha, InsercaoNovoElemIntermediario) {
    pv = (pilhaValue) malloc(sizeof(pilhaValue));
    pv->value = 4;
    pilha = push(pilha, pv);
    ASSERT_EQ(pv->value, 4);
}

/**
* Assertiva de entrada
* Remove 2 elementos da pilha [2,4] - Pilha: [0,1]
*/

TEST(Pilha, Pop2Elem) {
    int i;
    // Remove elemento 4
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 4);
    // Remove elemento 2
    pv = pop(&pilha);
    ASSERT_EQ(pv->value, 2);
}

/**
* Assertiva de entrada
* Verifica se o topo é = 1 - Pilha: [0,1]
*/

TEST(Pilha, TopoPosPop2Elem) {
    pv = top(pilha);
    ASSERT_EQ(pv->value, 1);
}

/**
* Assertiva de entrada
* Remove 10 elementos da pilha, sendo que so tem 2
* - Pilha: []
*/

TEST(Pilha, Pop10Elem) {
    int i;
    for(i = 1; i <= 10; i++)
      pv = pop(&pilha);
    ASSERT_TRUE(pv == NULL);
    ASSERT_FALSE(pv != NULL);
}

/**
* Assertiva de entrada
* Verifica o topo de pilha vazia - Pilha: []
*/

TEST(Pilha, TopoNovaPilhaVazia) {
    pv = top(pilha);
    ASSERT_TRUE(pv == NULL);
    ASSERT_FALSE(pv != NULL);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    //manual();
    return RUN_ALL_TESTS();
}

/*
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
    		case 1: {
    			printf("Digite o valor para PUSH: ");
                pv = (pilhaValue) malloc(sizeof(pilhaValue));
                if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                    scanf("%d", &valor);
                    pv->value = valor;
                }
                pilhaNode nova = push(pilha, pv);
                if(nova == NULL)
                    printf("Impossível inserir, pilha cheia!\n");
                else
                    pilha = nova;
    		    break;
        }
    		case 2: {
                pv = NULL;
                printf("&pilha %p\n", &pilha);
                printf("&pilha == NULL? %s\n", !&pilha ? "true": "false");
                printf("pilha == NULL? %s\n", !pilha ? "true": "false");
                printf("*(&pilha) == NULL? %s\n", !*(&pilha) ? "true": "false");
                pv = pop(&pilha);

                if(pv != NULL) {
                    if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                        printf("Valor POP: %d\n", pv->value);
                    }
                }
    			else
    				printf("Pilha vazia!\n");
    		break;
      }
    		case 3: {
                pv = top(pilha);
                if(pilha != NULL && pv != NULL) {
                    if(sizeof(TIPO_VALOR_PILHA) == sizeof(int)) {
                        printf("Valor TOP: %d\n", pv->value);
                    }
                }
    			else
    				printf("Pilha vazia!\n");
    		break;
      }
    		case 4: {
    			exit(1);
    		break;
      }
    		default:
        {
    		break;
        }
    	}

    } while (1);

    return 0;
}
*/
