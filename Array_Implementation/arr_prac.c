/*
First ever practice in C for dsa after a YEAR AAAAHH ౨ৎ

Created by: Hestia Meizi Tibon
Date created: September 3, 2025
Date modified: September 5, 2025
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
int deleteAllOccuranceByCourse(LIST *students, const char *course);
void display(LIST students);




//MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
int main() {
    //list with 3 elements
    LIST L = {
        {
            {{"Tibon", "Hestia Meizi", 'L'}, 2926, "BSCS", 3,},
            {{"Pepito", "John Cedrick", 'E'}, 2110, "BSBIO", 3},
            {{"Lumban", "Sebastian", 'K'}, 2134, "BSMRE", 3},
        }
        , 3
    };

    //Practice 1: basics
    printf("\nPractice 1: Basics\n\n");
        //print the # of elements in the list
        printf("The number of elements in the list: %d\n", L.count);

        //set the course of the 2nd student in the list to "BSBS"
        strcpy(L.Elements[1].Course, "BSBS");
        printf("The course of the 2nd student is now: %s\n", L.Elements[1].Course);

        //initialize a variable with the datatype nametype and add the information of your fav. artist's name
        nametype N = {"Caesar", "Daniel",' '};
        printf("My favorite artist is: %s, %s %c.\n", N.LName, N.FName, N.Mi);

        //print the first letter of the last name of the third student
        printf("The first letter of the last name of the 3rd student is: %c\n", L.Elements[2].name.LName[0]);



    printf("\n=====================================\n");
    //Practice 2: initList()
    printf("\nPractice 2: initList()\n\n");

        LIST students;                 // (minor safety init) keep API style below
        students = initList(students);
        printf("Your list now has an %d number of elements", students.count);



    printf("\n=====================================\n");
    //Practice 3: insertFirst()
    printf("\nPractice 3: insertFirst()\n\n");
        
        studtype addstud1 = {{"Ramas", "Ron", 'P'}, 2133, "BSCS", 3};
        studtype addstud2 = {{"Ortega", "Axel", 'S'}, 2135, "BSBIO", 3};

        insertFirst(&students, addstud1);
        insertFirst(&students, addstud2);
        insertFirst(&students, L.Elements[0]);
        //display(students);


    printf("\n=====================================\n");
    //Practice 4: insertLast()
    printf("\nPractice 4: insertLast()\n\n");

        insertLast(&students, L.Elements[1]);
        insertLast(&students, L.Elements[2]);
        //display(students);

        

    printf("\n=====================================\n");
    //Practice 5: insertLastUnique()
    printf("\nPractice 5: insertLastUnique()\n\n");

        insertLastUnique(&students, L.Elements[0]);
        insertLastUnique(&students, L.Elements[1]);
        
        studtype addstud3 = {{"Ladrera", "Raiken", 'D'}, 3333, "BSCS", 3};
        insertLastUnique(&students, addstud3);
        //display(students);


    printf("\n=====================================\n");
    //Practice 6: arrSort()
    printf("\nPractice 6: arrSort()\n\n");

        arrSortID(&students);
        //display(students);


    printf("\n=====================================\n");
    //Practice 7: insertSorted()
    printf("\nPractice 7: insertSorted()\n\n");

        studtype addstud4 = {{"de Paz", "Jade Shaira", 'I'}, 3332, "BSCS", 3};
        insertSorted(&students, addstud4);
        display(students);


    printf("\n=====================================\n");
    //Practice 8: insertAtPos()
    printf("\nPractice 8: insertAtPos()\n\n");

        insertAtPos(&students, L.Elements[0], 3);
        insertAtPos(&students, L.Elements[1], 3);
        display(students);

    
    printf("\n=====================================\n");
    //Practice 9: deleteAtPos()
    printf("\nPractice 9: deleteAtPos()\n\n");

        deleteAtPos(&students, 0);
        deleteAtPos(&students, 0);
        display(students);


    printf("\n=====================================\n");
    //Practice 10: locateID()
    printf("\nPractice 10: locateID()\n\n");

        int located;
        located = locateID(students, 2926);

        printf("Location: Student %d", located);

    printf("\n=====================================\n");
    // Practice 11: deleteAllOccuranceByCourse()
    printf("\nPractice 11: deleteAllOccuranceByCourse()\n\n");

        int removed = deleteAllOccuranceByCourse(&students, "BSBIO");
        printf("Removed %d student(s) taking BSBIO.\n", removed);
        display(students);

}


//FUNCTION DEFINITION = = = = = = = = = = = = = = = = = = = = = = = = =

//prac2
LIST initList(LIST students){
    students.count = 0;
    return students;
}

//prac3
void insertFirst(LIST *students, studtype addstud){
    int i;
    
    if(students->count < MAX){
        for(i = students->count; i > 0; i--){
            students->Elements[i] = students->Elements[i - 1];
        }
        students->Elements[0] = addstud;
        students->count++;
    }
}

//prac4
void insertLast(LIST *students, studtype addstud){
    if(students->count < MAX){
        students->Elements[students->count] = addstud;
        students->count++;
    }
}

//prac5
void insertLastUnique(LIST *students, studtype addstud){
    if (students->count >= MAX) {
        printf("List is full. Cannot insert.\n");
        return;
    }

    int i = 0;
    for (i = 0; i < students->count && students->Elements[i].ID != addstud.ID; i++) {}
    if (i == students->count) {    
        students->Elements[students->count] = addstud;
        students->count++;
    } else {
        printf("Student ID is not unique.\n");
        return;
    }
}

//prac6
void arrSortID(LIST *students){
    int i = 0, j;
    studtype temp;
    for(i = 0; i < students->count; i++){
        for(j = 0; j < students->count; j++){
            if(students->Elements[j].ID > students->Elements[i].ID){
                temp = students->Elements[i];
                students->Elements[i] = students->Elements[j];
                students->Elements[j] = temp;
            }
        }
    }
}

//prac7
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

//prac8
void insertAtPos(LIST *students, studtype addstud, int pos){
    int i = 0;

    if (students->count != MAX){
        if(pos >= 0 && pos <= students->count){                    
            for(i = students->count; i > pos; i--){
                students->Elements[i] = students->Elements[i - 1]; // FIX: shift right from i-1
            }
            students->Elements[pos] = addstud;
            students->count++;
        }
    }       
}

//prac9
void deleteAtPos(LIST *students, int pos){
    int i = 0;

    if(pos >= 0 && pos < students->count){
        for(i = pos; i < students->count - 1; i++){               // FIX: start at pos, pull from i+1
            students->Elements[i] = students->Elements[i + 1];
        }
        students->count--;
    }
}

//prac10
int locateID(LIST students, int ID){
    int i;
    for(i = 0; i < students.count && students.Elements[i].ID != ID; i++){}
    if (i == students.count){
        return -1;                                                // FIX: not found
    }
    return i + 1;                                                     // found
}

//prac11
int deleteAllOccuranceByCourse(LIST *students, const char *course){
    
    if (students == NULL || course == NULL) return 0;

    int write = 0;
    int removed = 0;
    int i = 0;

    for (i = 0; i < students->count; i++){
        if (strcmp(students->Elements[i].Course, course) != 0){
            students->Elements[write] = students->Elements[i];
            write++;
        } else {
            removed++;
        }
    }

    students->count = write;  // shrink logical size
    return removed;
}


//DISPLAY 
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
