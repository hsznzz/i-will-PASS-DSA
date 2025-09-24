#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 3
#define SIZE 3

typedef struct{
    int elem[CAP];
    int top;
}Stack;

void init(Stack *);
bool isEmpty(Stack *);
bool isFull(Stack *);
void push(Stack *, int);
int pop(Stack *);
int peek(Stack *);
void display(Stack *);

int main(){
    Stack cont[SIZE];

    init(&cont[0]);
    init(&cont[1]);
    init(&cont[2]);

    int choice = 0;
    int x = 0;
    do{
        printf("--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter element to push: ");
                int value = 0;
                scanf("%d", &value);
                int flag = 0;

                for(x = 0; x < SIZE; x++){
                    if(!isFull(&cont[x])){
                    push(&cont[x], value);
                    flag = 1;
                    break;
                    }
                }

                if(flag == 1){
                    printf("Successfully pushed %d\n\n", value);
                } else {
                    printf("Error: couldn't push element (Stack full)\n\n");
                }
                break;
            }

            case 2:{
                int flag = 0;
                int popped = 0;
                for(x = SIZE - 1; x >= 0; x--){
                    if(!isEmpty(&cont[x])){
                    popped = pop(&cont[x]);
                    flag = 1;
                    break;
                    }
                }
                if(flag == 1){
                    printf("Element popped was %d\n\n", popped);
                } else {
                    printf("Error: there's nothing to pop (Stack empty)\n\n");
                }
                
                break;
            }

            case 3: {
                printf("Enter an element to check: ");
                int check = 0;
                scanf("%d", &check);

                int found_any = 0;

                for (x = 0; x < SIZE; x++) {
                    int found_in_stack = 0;

                    if (!isEmpty(&cont[x])) {
                        for (int y = 0; y <= cont[x].top; y++) {   // only valid indices
                            if (cont[x].elem[y] == check) {
                                found_in_stack = 1;
                                break;                              // report once per stack
                            }
                        }
                    }

                    if (found_in_stack) {
                        printf("%d found in Stack %d\n", check, x + 1);
                        found_any = 1;
                    }
                }

                if (!found_any) {
                    printf("%d does not exist on any stack.\n", check);
                }
                printf("\n");
                break;
            }


            case 4: {
                for(x = 0; x < SIZE; x++){
                    printf("--- Stack %d ---\n", x + 1);
                    display(&cont[x]);
                }

                printf("\n\n");
                break;
            }

            case 5:{
                printf("Exited the program");
                break;
            }
        }
    }while (choice != 5);
}

void init(Stack *cont){
    cont->top = -1;
}

bool isEmpty(Stack *cont){
    return(cont->top == -1) ? true : false;
}

bool isFull(Stack *cont){
    return(cont->top == CAP - 1) ? true : false;
}

void push(Stack *cont, int num){
    if(!isFull(cont)){
        cont->elem[++cont->top] = num;
    } else {
        printf("Error: couldn't push element (Stack full)\n\n");
    }
}

int pop(Stack *cont){
    if(!isEmpty(cont)){
        int x = cont->elem[cont->top];
        --cont->top;
        return x;
    } 
}

int peek(Stack *cont){
    return(!isEmpty(cont)) ? cont->elem[cont->top] : 0;
}

void display(Stack *cont){
    if(!isEmpty(cont)){
        int x = 0;
        for(x = 0; x <= cont->top; x++){
            printf("%d\n", cont->elem[x]);
        }
    } else { 
        printf("Stack is empty\n");
    }
}