/*
Queue Array Version 1 (Variation 2 = Sacrificial Space) ౨ৎ

Created by: Hestia Meizi Tibon
Date created: September 14, 2025
Date modified: September 15, 2025
*/

/*

Components:
    - initialize
    - enqueue
    - dequeue
    - front
    - full
    - empty
    - display

*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int front;
    int rear;
    char elem[MAX];
}QueueArr;

void initQueue(QueueArr *List);
bool isFull(QueueArr *List);
bool isEmpty(QueueArr *List);
void enqueue(QueueArr *List, char X);
char dequeue(QueueArr *List);
char front(QueueArr *List);
void display(QueueArr List);


int main(){
    QueueArr List;
    initQueue(&List);

    enqueue(&List, 'H');
    enqueue(&List, 'E');
    enqueue(&List, 'S');
    enqueue(&List, 'T');
    enqueue(&List, 'I');
    enqueue(&List, 'A');

    display(List);

    char value = dequeue(&List);
    printf("The dequeued value: %c\n", value);
    display(List);

    printf("The front value now is: %c", front(&List));
}

void initQueue(QueueArr *List){
    List->front = 0;
    List->rear = MAX - 1;
}

bool isFull(QueueArr *List){
    return (((List->rear + 2) % MAX) == List->front) ? true : false;
}
bool isEmpty(QueueArr *List){
    return (((List->rear + 1) % MAX) == List->front) ? true : false;
}

void enqueue(QueueArr *List, char X){
    if(!isFull(List)){ //not full
        List->rear = (List->rear + 1) % MAX;
        List->elem[List->rear] = X;
    }
}

char dequeue(QueueArr *List){
    if(!isEmpty(List)){ //not empty
        char value = List->elem[List->front];
        List->front = (List->front + 1) % MAX;
        return value;
    }
}

char front(QueueArr *List){
    return (!isEmpty(List)) ? List->elem[List->front] : '\0';
}

void display(QueueArr List){
    printf("Queue: ");
    if(((List.rear + 1) % MAX) != List.front){   // not empty
        int i = List.front;
        while (i != (List.rear + 1) % MAX){
            printf("%c ", List.elem[i]);
            i = (i + 1) % MAX;
        }
    }
    printf("\n");
}
