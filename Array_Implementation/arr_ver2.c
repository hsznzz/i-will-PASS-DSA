/*
Array version 2 ౨ৎ

Contents:
    - initializing the list for use = initList(); /
    - inserting at the first index of the arr = insertFirst(); /
    - inserting at the last index of the arr = insertLast(); /
    - inserting an element if it isnt repeated = insertLastUnique(); /
    - sorting the elements = arrSortID();
    - inserting an element, sorted = insertSorted();
    - inserting an element at a specific index = insertAtPos();
    - deleting an element at a specific index = deleteAtPos();
    - locating the element at its index = locateID();
    - displaying the elements = display(); /

Created by: Hestia Meizi Tibon
Date created: September 8, 2025
Date modified: September 14, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    char FName[24];
    char LName[16];
    char Mi;
}nametype;

typedef struct {
    nametype name;
    int ID;
    char Course[8];
    int Year;
}studtype;

typedef struct{
    studtype studs[MAX];
    int count;
}nodetype, *LIST;

void initArr(LIST *students);
void insertFirst(LIST *students, studtype addstud);
void insertLast(LIST *students, studtype addstud);
void insertLastUnique(LIST *students, studtype addstud);
void display(LIST students);

int main(){
    LIST students = malloc(sizeof(nodetype));
    initArr(&students);

    studtype addstud1 = {{"Hestia Meizi", "Tibon", 'L'}, 111, "BSCS", 3};
    studtype addstud2 = {{"John Cedrick", "Pepito", 'E'}, 112, "BSBIO", 3};
    studtype addstud3 = {{"Vincent", "Lima", 'C'}, 113, "CHEM", 3};


    insertFirst(&students, addstud1);
    insertLast(&students, addstud2);
    display(students);

    insertLastUnique(&students, addstud3);
    insertLastUnique(&students, addstud3);
    display(students);


}

void initArr(LIST *students){
    (*students)->count = 0;
}

void insertFirst(LIST *students, studtype addstud){
    int i = 0;

    if((*students)->count != MAX){
        for(i = (*students)->count; i > 0; i--){
            (*students)->studs[i] = (*students)->studs[i - 1];
        }
        (*students)->studs[0] = addstud;
        (*students)->count++;
    } else {
        printf("No mo space");
    }
}

void insertLast(LIST *students, studtype addstud){
    if((*students)->count != MAX){
        (*students)->studs[(*students)->count] = addstud;
        (*students)->count++;
    }
}

void insertLastUnique(LIST *students, studtype addstud){
    int i = 0;

    if((*students)->count != MAX){
        for(i = 0; i < (*students)->count && (*students)->studs[i].ID != addstud.ID; i++){}
        if(i == (*students)->count){
            (*students)->studs[(*students)->count] = addstud;
            (*students)->count++;
        } 
    }
}

void display(LIST students){
    int i = 0;

    printf("\nSTUDENT LIST:\n");

    for(i = 0; i < (*students).count; i++){
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s, %s %c.\n", (*students).studs[i].name.LName, (*students).studs[i].name.FName, (*students).studs[i].name.Mi);
        printf("ID: %d\n", (*students).studs[i].ID);
        printf("Course: %s\n", (*students).studs[i].Course);
        printf("Year: %d\n", (*students).studs[i].Year);
    }
}
