#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};


void create(struct Queue *q) {
    printf("Enter the size of the circular queue: \n");
    scanf("%d", &q->size);

    q->front = q->rear = 0;
    q->Q = (int *)malloc(sizeof(int) * (q->size + 1));

}

void enqueue(struct Queue *q, int ele) {
    if((q->rear + 1) % (q->size + 1) == q->front) {
        printf("Circular Queue is full\n");
    }

    else {
        q->rear = (q->rear + 1) % (q->size + 1);
        q->Q[q->rear] = ele;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;

    if(q->rear == q->front) {
        printf("Circular Queue is empty\n");
    }

    else {
        q->front = (q->front + 1) % (q->size + 1);
        x = q->Q[q->front];
    }

    return x;
}


void display(struct Queue q) {
    if(q.rear == q.front) {
        printf("Circular queue is empty\n");
        return;
    }


    int i = (q.front + 1) % q.size + 1;
    while(i != (q.rear + 1) % q.size + 1) {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size + 1;
    }
    printf("\n");

    
}

int main() {
    struct Queue q;
    create(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    printf("The element popped: %d\n", dequeue(&q));
    printf("The element popped: %d\n", dequeue(&q));
    

    display(q);

    return 0;
}