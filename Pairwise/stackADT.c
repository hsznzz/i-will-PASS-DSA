/*
Pairwise Activity

Created by: Hestia Meizi Tibon
Date created: September 11, 2025
Date modified: September 11, 2025
*/


#include "stackArray.h"

int main() {
    Stack S;
    initStack(&S);

    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');
    push(&S, 'E');
    push(&S, 'F');
    push(&S, 'G');
    push(&S, 'H');
    push(&S, 'I');
    push(&S, 'J');
    push(&S, 'K');
    push(&S, 'L');


    displayStack(&S);

    printf("Top element: %c\n", top(&S));

    pop(&S);
    displayStack(&S);

    printf("Top element: %c\n", top(&S));

    return 0;
}
