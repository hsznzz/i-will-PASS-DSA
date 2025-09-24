/*
Linked List Implementation for Queues ౨ৎ

Contents:
    - initializing the queue for use = initQueue() /
    - adding an element to the queue = enqueue() /
    - removing an element from the queue = dequeue() /
    - returning the front element from the queue = frontQ() /
    - displaying the queue = displayQ() /

Created by: Hestia Meizi Tibon
Date created: September 14, 2025
Date modified: September 14, 2025
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} Node, *Queue;

void initQueue(Queue *List);
void enqueue(Queue *List, char X);
void dequeue(Queue *List);
char frontQ(Queue List);
void displayQ(Queue List);

int main(void) {
    Queue List;
    initQueue(&List);

    enqueue(&List, 'A');
    enqueue(&List, 'B');
    enqueue(&List, 'C');

    displayQ(List);
    printf("Front: %c\n", frontQ(List));

    dequeue(&List);
    displayQ(List);
    printf("Front: %c\n", frontQ(List));

    return 0;
}

void initQueue(Queue *List) {
    *List = NULL;
}

void enqueue(Queue *List, char X) {
    Queue temp = (Queue) malloc(sizeof(Node));
    if (temp != NULL){
        temp->elem = X;
        temp->link = NULL;

        if (*List == NULL) {
            *List = temp;
        } else {
            Queue trav = *List;
            while (trav->link != NULL) {
                trav = trav->link;
            }
            trav->link = temp;
        }
    }
}

void dequeue(Queue *List) {
    if (*List != NULL){
        Queue temp = *List;
        *List = temp->link;
        free(temp);
    }
}

char frontQ(Queue List) {
    return (List != NULL) ? List->elem : '\0';
}

void displayQ(Queue List) {
    printf("Queue: ");
    
    while (List != NULL) {
        printf("%c ", List->elem);
        List = List->link;
    }
    printf("\n");
}
