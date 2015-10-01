#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

pilhaNode push(pilhaNode top, pilhaValue value) {
    if(top == NULL) {
        pilhaNode newNode;
        newNode = (pilhaNode) malloc(sizeof(pilhaNode));
        newNode->size = 0;
        newNode->value[newNode->size] = value;
        return newNode;
    }
    top->size += 1;
    if(top->size < STACK_MAX) {
        printf("Elemento inserido na posicao: %d\n", top->size);
        top->value[top->size] = value;
    }
    else {
        top->size -= 1;
        printf("Top size: %d\n", top->size );
        return NULL;
    }
}

pilhaValue pop(pilhaNode * top) {
    if(top == NULL || (*top)->size == -1) return NULL;
    pilhaValue value = (*top)->value[(*top)->size];
    (*top)->size -= 1;
    return value;
}

pilhaValue top(pilhaNode top) {
    if(top == NULL || top->size == -1) return NULL;
    return top->value[top->size];
}
