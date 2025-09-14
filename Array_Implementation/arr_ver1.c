/*
Array version 1

Created by: Hestia Meizi Tibon
Date created: September 3, 2025
Date modified: September 6, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    char LName[16];
    char FName[24];
    char Mi;
}nametype;

typedef struct{
    nametype name;
    int ID;
    char Course[8];
    int Year;
}studtype;

typedef struct{
    studtype Elements[MAX];
    int count;
}LIST;

//FUNCTION HEADER = = = = = = = = = = = = = = = = = = = = = = = = = 
LIST initList(LIST students);
void insertFirst(LIST *students, studtype addstud);
void insertLast(LIST *students, studtype addstud);
void insertLastUnique(LIST *students, studtype addstud);
void arrSortID(LIST *students);
void insertSorted(LIST *students, studtype addstud);
void insertAtPos(LIST *students, studtype addstud, int);
void deleteAtPos(LIST *students, int);
int locateID(LIST students, int);
void display(LIST students);

int main(){
    LIST students = initList(students);
    printf("\ncount is %d", students.count);

    studtype addstud1 = {{"Bocado", "Denise", 'L'}, 1111, "BSIT", 2};
    studtype addstud2 = {{"Lima", "Vince", 'M'}, 2222, "CHEM", 3};
    studtype addstud3 = {{"Marbella", "Jasper", 'S'}, 3333, "BSIT", 3};
    
    printf("\n\ninsertfirst = = = = = = = = = =\n");
    insertFirst(&students, addstud1);
    display(students);

    printf("\n\ninsertlast = = = = = = = = = = =\n");
    insertLast(&students, addstud3);
    display(students);

    printf("\n\ninsertlastUnique = = = = = = = =\n");
    insertLastUnique(&students, addstud2);
    display(students);

    printf("\n\narrSortID = = = = = = = = = = =\n");
    arrSortID(&students);
    display(students);
}


//FUNCTION DEFINITION = = = = = = = = = = = = = = = = = = = = = = =
LIST initList(LIST students){
    students.count = 0;
    return students;
}

void insertFirst(LIST *students, studtype addstud){
    int i;
    if(students->count < MAX){
        for(i = students->count; i < 0; i--){
            students->Elements[i] = students->Elements[i - 1];
        }
        students->Elements[0] = addstud;
        students->count++;
    }
}

void insertLast(LIST *students, studtype addstud){
    int i;
    if(students->count != MAX){
        students->Elements[students->count] = addstud;
        students->count++;
    }
}

void insertLastUnique(LIST *students, studtype addstud){
    int i;
    if(students->count != MAX){
        for(i = 0; i < students->count && students->Elements[i].ID != addstud.ID; i++){}
        if(i == students->count){
            students->Elements[students->count] = addstud;
            students->count++;
        }
    }
}

void arrSortID(LIST *students){
    int i, j;
    studtype temp;
    for(i = 0; i < students->count; i++){
        for(j = 0; j < students->count; j++){
            if(students->Elements[j].ID > students->Elements[i].ID){
                temp = students->Elements[j];
                students->Elements[j] = students->Elements[i];
                students->Elements[i] = temp;
            }
        }
    }
}

void insertSorted(LIST *students, studtype addstud){
    int i = students->count;

    if(students->count < MAX){  
        for (i = students->count; i > 0 && students->Elements[i - 1].ID > addstud.ID; i--) {
            students->Elements[i] = students->Elements[i - 1];    
        }

        students->Elements[i] = addstud;
        students->count++;
    }
}


void insertAtPos(LIST *students, studtype addstud, int pos){
    int i = 0;

    if (students->count != MAX){
        if(pos >= 0 && pos <= students->count){                    
            for(i = students->count; i > pos; i--){
                students->Elements[i] = students->Elements[i - 1];
            }
            students->Elements[pos] = addstud;
            students->count++;
        }
    }       
}

void deleteAtPos(LIST *students, int pos){
    int i = 0;

    if(pos >= 0 && pos < students->count){
        for(i = pos; i < students->count - 1; i++){              
            students->Elements[i] = students->Elements[i + 1];
        }
        students->count--;
    }
}

int locateID(LIST students, int ID){
    int i;
    for(i = 0; i < students.count && students.Elements[i].ID != ID; i++){}
    if (i == students.count){
        return -1;                                                
    }
    return i + 1;                                                     
}



//DISPLAY = = = = = = = = = = = = = = = = = = = = = ==  
void display(LIST students){
    int i = 0;

    printf("\nSTUDENT LIST:\n");

    for(i = 0; i < students.count; i++){
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s, %s %c.\n", students.Elements[i].name.LName, students.Elements[i].name.FName, students.Elements[i].name.Mi);
        printf("ID: %d\n", students.Elements[i].ID);
        printf("Course: %s\n", students.Elements[i].Course);
        printf("Year: %d\n", students.Elements[i].Year);
    }
}