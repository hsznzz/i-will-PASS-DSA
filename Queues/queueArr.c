//to be finalized

#include <stdio.h>
#define SIZE 10

typedef struct{
    int front;
    int rear;
    char data[SIZE];
} QueueArr;


void initQueueArr(QueueArr *q);
void enqueueArr(QueueArr *q, char x);
char dequeueArr(QueueArr *q);
char front(QueueArr q);
void displayArr(QueueArr *q);

int main(void){
    QueueArr list;
    initQueueArr(&list);

    enqueueArr(&list, 'H');
    enqueueArr(&list, 'E');
    displayArr(&list);
    printf("Front element: %c\n\n", front(list));

    dequeueArr(&list);
    displayArr(&list);
    printf("Front element: %c\n\n", front(list));

    enqueueArr(&list, 'A');
    enqueueArr(&list, 'B');
    displayArr(&list);
    printf("Front element: %c\n\n", front(list));

    dequeueArr(&list);
    dequeueArr(&list);
    displayArr(&list);
    printf("Front element: %c\n\n", front(list));

    return 0;
}



void initQueueArr(QueueArr *q){
    q->front = 0;
    q->rear  = SIZE - 1;   
}

void enqueueArr(QueueArr *q, char x){
    if ( ((q->rear + 2) % SIZE) == q->front ){
        printf("Queue is full, cannot enqueue %c.\n", x);
        return;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = x;
}

char dequeueArr(QueueArr *q){
    if ( ((q->rear + 1) % SIZE) == q->front ){
        printf("Queue is empty, cannot dequeue.\n");
        return '\0';
    }
    char val = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    return val;
}

char front(QueueArr q){
    return ( ((q.rear + 1) % SIZE) != q.front ) ? q.data[q.front] : '\0';
}

void displayArr(QueueArr *q){
    if ( ((q->rear + 1) % SIZE) == q->front ){
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while (1){
        printf("%c ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");

}
