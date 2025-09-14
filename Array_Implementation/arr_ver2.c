/*
Array version 2

Created by: Hestia Meizi Tibon
Date created: September 8, 2025
Date modified: September 14, 2025
*/

#include <stdio.h>

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

int main(){
    LIST students;
    
}

void initArr(LIST *students){

}
