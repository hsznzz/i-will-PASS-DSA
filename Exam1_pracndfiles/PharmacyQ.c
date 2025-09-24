#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 6

typedef struct{
    int number[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *list);
bool isEmpty(Queue *list);
bool isFull(Queue *list);
void enqueue(Queue *list, int);
int  dequeue(Queue *list);
int  frontQ(Queue *list);
void display(Queue *list);

int main(void){
    Queue regular, priority, numQs;

    init(&regular);
    init(&priority);
    init(&numQs);

    for (int i = 0; i < SIZE; i++){
        enqueue(&numQs, i);
    }

    int choice = 0;
    do{
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: { 
                if (isEmpty(&numQs)) {
                    printf("No more queue numbers\n\n");
                } else if (isFull(&regular)) {
                    printf("Regular queue is full.\n\n");
                } else {
                    int n = dequeue(&numQs);          
                    enqueue(&regular, n);
                    printf("You entered REGULAR Queue. Your number is %d\n\n", n + 1);
                }
                break;
            }

            case 2: { 
                if (isEmpty(&numQs)) {
                    printf("No more queue numbers\n\n");
                } else if (isFull(&priority)) {
                    printf("Priority queue is full.\n\n");
                } else {
                    int n = dequeue(&numQs);
                    enqueue(&priority, n);
                    printf("You entered PRIORITY Queue. Your number is %d\n\n", n + 1);
                }
                break;
            }

            case 3: { 
                if (!isEmpty(&priority)) {
                    int n = dequeue(&priority);
                    printf("Calling the next customer from the PRIORITY QUEUE. Number %d\n\n", n + 1);
                } else if (!isEmpty(&regular)) {
                    int n = dequeue(&regular);
                    printf("Calling the next customer from the REGULAR QUEUE. Number %d\n\n", n + 1);
                } else {
                    printf("No more customers in the Queue\n\n");
                }
                break;
            }

            case 4: { 
                printf("\n--- DISPLAY ---\n");
                printf("PRIORITY QUEUE:\n");
                display(&priority);

                printf("REGULAR QUEUE:\n");
                display(&regular);

                printf("AVAILABLE NUMBERS:\n");
                display(&numQs);

                printf("\n");
                break;
            }

            case 5:
                printf("Exited the program\n");
                break;

            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}


void init(Queue *list){
    list->front = 0;
    list->rear  = SIZE - 1;
}

bool isEmpty(Queue *list){
    return ((list->rear + 1) % SIZE) == list->front;
}

bool isFull(Queue *list){
    return ((list->rear + 2) % SIZE) == list->front;
}

void enqueue(Queue *list, int elem){
    if (!isFull(list)){
        list->rear = (list->rear + 1) % SIZE;
        list->number[list->rear] = elem;
    }
}

int dequeue(Queue *list){
    if (!isEmpty(list)){
        int turn = list->number[list->front];
        list->front = (list->front + 1) % SIZE;
        return turn;                     
    }
    return -1;                           
}

int frontQ(Queue *list){
    return !isEmpty(list) ? list->number[list->front] : -1;
}

void display(Queue *q){
    if (isEmpty(q)) {
        printf("[empty]\n");
        return;
    }
    int i = q->front;
    while (i != (q->rear + 1) % SIZE) {
        printf("%d ", q->number[i] + 1); 
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
