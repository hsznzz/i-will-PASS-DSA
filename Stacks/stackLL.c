/*
Stacks Linked List Implementation (Variation 1 = from MAX - 1 to 0) ౨ৎ

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

typedef struct node{
    char elem;
    struct node *link;
}*topLL;

void initStack(topLL*);
bool isEmpty(topLL*);
bool isFull(topLL*);
void push(topLL*, char);
void pop(topLL*);
char top(topLL*);
void display(topLL*);

int main(){
    topLL list;
    initStack(&list);

    bool x = true;
    bool y = false;

    printf("true = %i, false = %i\n", x, y);
    printf("is the list empty? %i\n\n", isEmpty(&list));
    
    push(&list, 'H');
    display(&list);
    printf("is the list empty? %i\n\n", isEmpty(&list));

    pop(&list);
    display(&list);
    printf("is the list empty? %i\n\n", isEmpty(&list));

    pop(&list);

}

void initStack(topLL *list){
    *list = NULL;
}

bool isEmpty(topLL *list){
    return((*list) == NULL) ? true : false;
}


bool isFull(topLL *list){
    topLL temp = (topLL)malloc(sizeof(struct node));
    if (temp == NULL) {
        return true;  // out of memory
    }
    free(temp);       // no leak
    return false;
}


void push(topLL *list, char X){
    if(!isFull(list)){
        topLL temp = malloc(sizeof(struct node));

        if(temp != NULL){
            temp->elem = X;
            temp->link = *list;
            *list = temp;
        }
    }
}

void pop(topLL *list){
    if(!isEmpty(list)){
        if((*list)->link != NULL){
            (*list) = (*list)->link;
        } else { 
            (*list) = NULL;
        }
    } else {
        printf("Nothing to pop");
    }
}

char top(topLL *list){
    return (!isEmpty(list)) ? (*list)->elem : '\0';
}

void display(topLL *list){
    printf("Stack list: ");
    if(!isEmpty(list)){
        topLL trav = (*list);
        while(trav != NULL){
            printf("%c ", trav->elem);
            trav = trav->link;
        }
    }
    printf("\n");
}
