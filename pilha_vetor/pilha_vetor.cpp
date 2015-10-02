#include <stdio.h>
#include <stdlib.h>

#include "pilha_vetor.h"

pilhaNode push(pilhaNode top, pilhaValue value) {
    if(!top) {
        pilhaNode newNode;
        newNode = (pilhaNode) malloc(sizeof(pilhaNode));
        newNode->size = 0;
        newNode->value = (pilhaValue) malloc(sizeof(pilhaValue) * STACK_MAX);
        (newNode->value + newNode->size)->value = value->value;
        return newNode;
    }
    top->size += 1;
    if(top->size < STACK_MAX) {
        (top->value + top->size)->value = value->value;
        return top;
    }
    else {
        top->size -= 1;
        return NULL;
    }
}

pilhaValue pop(pilhaNode * top) {
    if(!*top || (*top)->size == -1) return NULL;
    pilhaValue value = ((*top)->value + (*top)->size);
    (*top)->size -= 1;
    return value;
}

pilhaValue top(pilhaNode top) {
    if(!top || top->size == -1) return NULL;
    return (top->value + top->size);
}
