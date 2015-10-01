#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

pilhaNode push(pilhaNode top, pilhaValue value) {
    pilhaNode newNode;
	newNode = (pilhaNode) malloc(sizeof(pilhaNode));
    newNode->top = top;
    newNode->value = value;
    return newNode;
}

pilhaValue pop(pilhaNode * top) {
    if(top == NULL) return NULL;
    pilhaValue value = (*top)->value;
    pilhaNode newTop = (*top)->top;
    free(*top);
    *top = newTop;
    return value;
}

pilhaValue top(pilhaNode top) {
    if(top == NULL) return NULL;
    return top->value;
}
