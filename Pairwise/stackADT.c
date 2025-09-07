#include "stackADT.h"

int main() {
    Stack S;
    initStack(&S);

    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');

    displayStack(&S);

    printf("Top element: %c\n", top(&S));

    pop(&S);
    displayStack(&S);

    return 0;
}
