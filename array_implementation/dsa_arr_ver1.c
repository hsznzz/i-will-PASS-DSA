//first ever practice in C for dsa
//created by: Hestia Meizi Tibon
//date created: September 3, 2025
//date modified: September 5, 2025

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

}