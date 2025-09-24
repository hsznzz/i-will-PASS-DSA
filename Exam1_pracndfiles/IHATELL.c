#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

typedef struct{
    char FName[24];
    char LName[16];
}Name;

typedef struct{
    Name name;
    int ID;
    char Course[9];
    int Year;
} studInfo;

typedef struct node{
    studInfo student;
    struct node *link;
} *Stack;

void init(Stack *list);
bool isEmpty(Stack *list);
bool isFull(Stack *list);
void push(Stack *list, studInfo);
studInfo pop(Stack *list);
void display(Stack list);

int main(){
    Stack list;
    init(&list);
    
    studInfo addstud = {{"Tibon", "Hestia"}, 111,"BSCS",3};

    push(&list, addstud);
    display(list);

    pop(&list);
    display(list);
}

void init(Stack *list){
    (*list) = NULL;
}

bool isEmpty(Stack *list){
    return((*list) == NULL) ? true: false;
}

void push(Stack *list, studInfo student){
    Stack add = (Stack)malloc(sizeof(struct node));
    if(add != NULL){
        add->student = student;
        add->link = (*list);
        (*list) = add;
    }

}

studInfo pop(Stack *list){
    studInfo popped;

    if(!isEmpty(list)){   
        Stack temp = (*list);       
        popped = (*list)->student;
        (*list) = temp->link;
        free(temp);
    }

    return popped;
}

void display(Stack list){
    while (!isEmpty(&list)) {
        studInfo temp = pop(&list);
        printf("ID: %d\n", temp.ID);
        printf("Name: %s %s\n", temp.name.FName, temp.name.LName);
        printf("Course: %s\n", temp.Course);
        printf("Year: %d\n", temp.Year);
        printf("----------------------\n");
    }
}
