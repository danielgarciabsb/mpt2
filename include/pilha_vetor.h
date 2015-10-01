#ifndef TIPO_VALOR_PILHA
#define TIPO_VALOR_PILHA int
#endif

typedef struct pilhaType
{
	TIPO_VALOR_PILHA value;
} * pilhaValue;

#define STACK_MAX 5

typedef struct pilhaNodeType
{
	pilhaValue value[STACK_MAX];
	int size;

} * pilhaNode;

pilhaNode push(pilhaNode top, pilhaValue value);

pilhaValue pop(pilhaNode * top);

pilhaValue top(pilhaNode top);
