#define TIPO_VALOR_PILHA int

typedef struct pilhaType
{
	TIPO_VALOR_PILHA value;
} * pilhaValue;

typedef struct pilhaNodeType
{
	struct pilhaNodeType * top;
	pilhaValue value;

} * pilhaNode;

pilhaNode push(pilhaNode top, pilhaValue value);

pilhaValue pop(pilhaNode * top);

pilhaValue top(pilhaNode top);
