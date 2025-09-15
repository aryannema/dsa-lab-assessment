#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size) {
    printf("Enter the size of the queue: \n");
    scanf("%d", &q->size);

    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int ele) {
    if(q->rear == q->size - 1) {
        printf("Queue is full\n");
    }

    else {
        q->rear++;
        q->Q[q->rear] = ele;
    }
}


int dequeue(struct Queue *q) {
    int x = -1;
    if(q->rear == q->front) {
        printf("Queue is empty\n");
    }

    else {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue q) {

    for(int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}


int isEmpty(struct Queue q) {
    if(q.rear == q.front) {
        return 1;
    }

    return 0;
}

int isFull(struct Queue q) {
    if(q.rear == q.size - 1) {
        return 1;
    }

    return 0;
}


int first(struct Queue q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q.Q[q.front + 1];
}


int last(struct Queue q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q.Q[q.rear];
}


int main() {
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    dequeue(&q);
    dequeue(&q);

    display(q);

    printf("The first element of the queue is: %d\n", first(q));
    printf("The last element of the queue is: %d\n", last(q));

    
    return 0;
}