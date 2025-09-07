#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 50

// stack definition
typedef struct {
    char elem[MAX];
    int top;   // -1 means empty
} Stack;

// function definitions
void initStack(Stack *S) {
    S->top = -1;
}

bool isEmpty(const Stack *S) {
    return S->top < 0;
}

bool isFull(const Stack *S) {
    return S->top >= (MAX - 1);
}

void push(Stack *S, char X) {
    if (isFull(S)) {
        printf("Stack overflow! '%c' not pushed.\n", X);
        return;
    }
    S->elem[++(S->top)] = X;
}

void pop(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack underflow! Nothing to pop.\n");
        return;
    }
    S->top--;
}

char top(const Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty. Returning '\\0'.\n");
        return '\0';
    }
    return S->elem[S->top];
}

void displayStack(const Stack *S) {
    if (isEmpty(S)) {
        printf("[ ] (empty)\n");
        return;
    }
    printf("[Top] ");
    for (int i = S->top; i >= 0; --i) {
        printf("%c", S->elem[i]);
        if (i > 0) printf(" -> ");
    }
    printf(" [Bottom]\n");
}

#endif 
