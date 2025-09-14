/*
Structured Linked List Implementation for Queues

Contents:
    - initializing the queue for use = initQueue()
    - adding an element to the queue = enqueue()
    - removing an element from the queue = dequeue()
    - returning the front element from the queue = frontQ()
    - displaying the queue = displayQ()

Created by: Hestia Meizi Tibon
Date created: September 14, 2025
Date modified: September 14, 2025
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node *link;
} nodetype, *Nodes;

typedef struct{
    Nodes front;
    Nodes rear;
} Queue;

void initQueue(Queue *List);
void enqueue (Queue *List, char X);
void dequeue(Queue *List);
char frontQ(Queue List);
void displayQ(Queue List);

int main(){
    Queue List;
    initQueue(&List);

    enqueue(&List, 'H');
    enqueue(&List, 'I');
    enqueue(&List, 'J');
    enqueue(&List, 'K');
    enqueue(&List, 'L');

    printf("\nAfter enqueue:\n");
    displayQ(List);
    printf("\nFront element: %c", frontQ(List));

    printf("\n\nAfter denqueue (1 time):\n");
    dequeue(&List);
    displayQ(List);
    printf("\nFront element: %c", frontQ(List));

    printf("\n\nAfter denqueue(2 times):\n");
    dequeue(&List);
    dequeue(&List);
    displayQ(List);
    printf("\nFront element: %c", frontQ(List));
}

void initQueue(Queue *List){
    List->front = NULL;
    List->rear = NULL;
}


void enqueue (Queue *List, char X){
    Nodes temp = malloc(sizeof (struct node));

    if(temp != NULL){
        temp->elem = X;
        temp->link = NULL;

        if(List->rear != NULL){
            List->rear->link = temp;
        } else {
            List->front = temp;
        }
        List->rear = temp;
    } else { 
        printf("Memory full");
    }
}

void dequeue(Queue *List){
    if(List->front != NULL){
        if(List->front->link != NULL){
            List->front = List->front->link;
        } else {
            List->front = NULL;
            List->rear = NULL;
        }
    }
}

char frontQ(Queue List){
    /*
    if(List.front != 0){
        return List.front->elem;
    } else {
        return '\0';
    }
    */

    return (List.front != 0) ? List.front->elem : '\0';
    
}

void displayQ(Queue List){
    Queue temp = List;

    printf("Your Queue: ");
    if(temp.front != NULL){
        while(temp.front != NULL){
            printf("%c ", temp.front->elem);
            temp.front = temp.front->link;
        }
    } else {
        printf("Nothing in Queue");
    }
}