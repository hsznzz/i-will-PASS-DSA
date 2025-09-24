#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int SET[MAX];

SET * Union(SET A, SET B);

int main(){
    SET A = {1, 0, 0, 1, 1};
    SET B = {0, 0, 1, 1, 1};

    SET *C = Union(A,B);

    int i = 0;
    printf("SET C (A U B): {");
    for(i = 0; i < MAX; i++){
        printf("%i", (*C)[i]);
        if(i < MAX - 1){
            printf(", ");
        }
    }
    printf("}");
}

SET * Union(SET A, SET B){
    int i = 0;
    SET *C = malloc (sizeof(SET));

    for(i = 0; i < MAX; i++){
        (*C)[i] = A[i] | B[i];
    }

    return C;
}