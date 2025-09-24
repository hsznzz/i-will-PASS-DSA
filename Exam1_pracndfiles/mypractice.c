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

typedef struct{
    studInfo student[MAX];
    int top;
} Stack;


void init(Stack *);
bool isEmpty(Stack *studList);
bool isFull(Stack *studList);
void push(Stack *studList, studInfo);
studInfo pop(Stack *studList);
void display(Stack *studList);

int main(){
    Stack studList;
    init(&studList);

    studInfo addstud1 = {{"Hestia", "Tibon"}, 1111,"BSCS", 3};
    studInfo addstud2 = {{"Lara", "Tibon"}, 2222,"BSED", 2};
    studInfo addstud3 = {{"Akiro", "Tibon"}, 3333,"JHS", 9};
    studInfo addstud4 = {{"Adam", "Tibon"}, 4444,"Elem", 4};
    
    push(&studList, addstud1);
    push(&studList, addstud2);
    push(&studList, addstud3);
    push(&studList, addstud4);

    int choice = 0;
    do{
        printf("--- Student Stack ---\n");
        printf("1. Add Student Info\n");
        printf("2. Remove Student by ID\n");
        printf("3. Find student by Course\n");
        printf("4. Display Student Stack\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: { 
                studInfo addnewStud;
                printf("Add FIRST name of new student: ");
                scanf("%23s", addnewStud.name.FName);
                printf("Add LAST name of new student: ");
                scanf("%15s", addnewStud.name.LName);
                printf("Add ID of new student: ");
                scanf("%d", &addnewStud.ID);
                printf("Add Course of new student: ");
                scanf("%8s", addnewStud.Course);
                printf("Add Year of new student: ");
                scanf("%d", &addnewStud.Year);

                push(&studList, addnewStud);
                break;
            }

            case 2: { 
                Stack temp;
                init(&temp);
                int remove;
                int flag = 0;
                printf("ID to be removed: ");
                scanf("%d", &remove);

                while(!isEmpty(&studList)){
                    studInfo front = pop(&studList);
                    if(!flag && front.ID == remove){
                        flag = 1;
                    } else {
                        push(&temp, front);
                    }
                }
                    
                while(!isEmpty(&temp)){
                    push(&studList, pop(&temp));
                }

                if(flag == 1){
                    printf("Successfully removed student with ID of %d\n", remove);
                }

                break;
            }

            case 3: { 
                Stack temp;
                Stack buffer;
                init(&buffer);
                init(&temp);
                studInfo find;
                printf("Find students with Course: ");
                scanf("%8s", find.Course);

                while(!isEmpty(&studList)){
                    studInfo front = pop(&studList);
                    if(strcmp(front.Course, find.Course) == 0){
                        push(&temp, front);
                    } 
                    push(&buffer, front);
                }
                
                while(!isEmpty(&buffer)){
                    push(&studList, pop(&buffer));
                }
                printf("Students with Course: %s\n", find.Course);
                display(&temp);
                break;
            }

            case 4: { 
                printf("== Students in the Stack ==\n");
                display(&studList);
                break;
            }

            case 5:
                printf("Exited the program");
                break;
        }
    } while (choice != 5);



}

void init(Stack *studList){
    studList->top = -1;
}

bool isEmpty(Stack *studList){
    return(studList->top == -1) ? true : false;
}

bool isFull(Stack *studList){
    return(studList->top == MAX - 1) ? true : false;
}

void push(Stack *studList, studInfo X){
    if(!isFull(studList)){
        ++(studList->top);
        studList->student[studList->top] = X;
    } else {
        printf("\nCan't push. Stack is full\n");
    }
}

studInfo pop(Stack *studList){
    if(!isEmpty(studList)){
        studInfo popStack;
        popStack = studList->student[studList->top];
        studList->top--;
        return popStack;
    } else {
        studInfo nil = {{"",""}, 0, "", 0};   // sentinel
        printf("\nNothing to pop. Stack is empty\n");
        return nil;
    }
}

void display(Stack *studList){
    if(!isEmpty(studList)){
        int x = 0;
        for(x = 0; x <= studList->top; x++){
            printf("Name: %s, %s\n", studList->student[x].name.LName, studList->student[x].name.FName);
            printf("ID #: %d\n", studList->student[x].ID);
            printf("Course: %s\n", studList->student[x].Course);
            printf("Year: %d\n", studList->student[x].Year);
        }
    } else {
        printf("\nStack is empty\n");
    }
    printf("\n");
}