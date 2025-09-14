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

    printf("\nAfter denqueue (1 time):\n");
    dequeue(&List);
    displayQ(List);

    printf("\nAfter denqueue(3 times):\n");
    dequeue(&List);
    dequeue(&List);
    dequeue(&List);
    displayQ(List);
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