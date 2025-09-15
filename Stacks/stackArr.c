/*
Stacks Array Implementation Version 1 (Variation 1 = from MAX - 1 to 0) ౨ৎ

Components:
    - initialize
    - isEmpty
    - isFull
    - push
    - pop
    - top
    - display

Created by: Hestia Meizi Tibon
Date created: September 14, 2025
Date modified: September 15, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int top;
    char elem[MAX];
}Stack;

void initStack(Stack *list);
bool isEmpty(Stack *list);
bool isFull(Stack *list);
void push(Stack *list, char X);
void pop(Stack *list);
char top(Stack *list);
void display(Stack *list);

int main(){
    Stack list;
    initStack(&list);
    push(&list, 'H');
    push(&list, 'E');
    push(&list, 'S');
    display(&list);
    printf("Top element is: %c", top(&list));
}

void initStack(Stack *list){
    list->top = MAX;
}

bool isEmpty(Stack *list){
    return(list->top == MAX) ? true : false;
}

bool isFull(Stack *list){
    return(list->top == 0) ? true : false;
}

void push(Stack *list, char X){
    if(!isFull(list)){
        list->elem[--list->top] = X;
    }
}

void pop(Stack *list){
    if(!isEmpty(list)){
        list->top++;
    }
}

char top(Stack *list){
    return (!isEmpty(list)) ? list->elem[list->top] : '\0';
}

void display(Stack *list){
    printf("Stack: ");
    if(!isEmpty(list)){
        for(int i = list->top; i < MAX; i++){
            printf("%c ", list->elem[i]);
        }
    }
    printf("\n");
}


