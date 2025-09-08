#include <stdio.h>

#define SIZE 10

typedef struct{
    int front;
    int rear;
    char data[SIZE];
} QueueArr;

typedef enum {TRUE, FALSE} Boolean;

void initQueueArr(QueueArr *list);
Boolean isFull(QueueArr list);
Boolean isEmpty(QueueArr list);
void enqueueArr(QueueArr *list, char X);
void dequeueArr(QueueArr *list);
char front(QueueArr list);
void displayArr(QueueArr *list);

int main(){
    QueueArr list;
    initQueueArr(&list);

    enqueueArr(&list, 'H');
    enqueueArr(&list, 'E');
    displayArr(&list);

    dequeueArr(&list);
    displayArr(&list);

    enqueueArr(&list, 'A');
    enqueueArr(&list, 'B');

    displayArr(&list);

    dequeueArr(&list);
    dequeueArr(&list);
    displayArr(&list);
}

void initQueueArr(QueueArr *list){
    list->front = 0;
    list->rear = list->front - 1;
}

Boolean isFull(QueueArr list){
    return((list.rear + 2) % SIZE == list.front) ? TRUE : FALSE;
}

Boolean isEmpty(QueueArr list){
    return((list.rear + 1) % SIZE == list.front) ? TRUE : FALSE;
}

void enqueueArr(QueueArr *list, char X){
    if(isFull((*list))){
        list->rear = (list->rear + 1) % SIZE;
        list->data[list->rear] = X;
    }
    
}

void dequeueArr(QueueArr *list){
    list->front = (list->front + 1) % SIZE;
}

char front(QueueArr list){
    return ((list.rear + 1) % SIZE != list.front) ? list.data[list.front] : '\0';
}

void displayArr(QueueArr *list) {
    if (list->front == -1) {
        printf("Queue is empty.\n");
        return;
    }


    printf("Queue: ");
    for (int i = list->front; i <= list->rear; i++) {
        printf("%c ", list->data[i]);
    }
    printf("\n");
}
