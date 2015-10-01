/*
	Comentar o define abaixo para escolher a Pilha Vetor
	ao inves da Pilha Lista e lembre-se de comentar no Makefile
	pilha_lista.o ou pilha_vetor.o
*/
#define PILHA_LISTA

// Se não for definido a Pilha de Lista, então a Pilha de Vetor é definida
#ifndef PILHA_LISTA
    #define PILHA_VETOR
#endif

// Define o tipo de valor da pilha
#ifndef TIPO_VALOR_PILHA
#define TIPO_VALOR_PILHA int
#endif

typedef struct pilhaType
{
	TIPO_VALOR_PILHA value;
} * pilhaValue;

#ifndef PILHA_VETOR
typedef struct pilhaNodeType
{
	struct pilhaNodeType * top;
	pilhaValue value;

} * pilhaNode;
#endif

#ifndef PILHA_LISTA

#define STACK_MAX 5

typedef struct pilhaNodeType
{
	pilhaValue value[STACK_MAX];
	int size;

} * pilhaNode;
#endif

pilhaNode push(pilhaNode top, pilhaValue value);

pilhaValue pop(pilhaNode * top);

pilhaValue top(pilhaNode top);
