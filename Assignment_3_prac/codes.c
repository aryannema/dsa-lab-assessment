#include <stdio.h>
#include <stdlib.h>

// 1) Stack and its operations:
struct Stack {

    int size;
    int top;
    int *S;
};

void createStack(struct Stack *st) {
    printf("Enter the size of the stack:\n");
    scanf("%d", &st->size);

    st->top = -1;
    st->S = (int *)malloc(sizeof(int) * st->size);

}

void push(struct Stack *st, int ele) {
    if(st->top == st->size - 1) {
        printf("Stack Overflow\n");
    }

    else {
        st->top++;
        st->S[st->top] = ele;
    }

}

int pop(struct Stack *st) {
    int x = -1;

    if(st->top == -1) {
        printf("Stack Underflow\n");
    }

    else {
        x = st->S[st->top];
        st->top--;
    }

    return x;

}


int peekStack(struct Stack st, int pos) {
    int x = -1;
    
    if(st.top - pos + 1 < 0) {
        printf("Invalid position\n");
    }

    else {
        x = st.S[st.top - pos + 1];
    }

    return x;

}


int stackTop(struct Stack st) {
    if(st.top == -1) {
        return -1;
    }

    else return st.S[st.top];

}


int isEmpty(struct Stack st) {
    if(st.top == -1) {
        return 1;
    }

    return 0;
}

int isFull(struct Stack st) {
    if(st.top == st.size - 1) {
        return 1;
    }

    return 0;
}

// ###############################################################################


// 2) Queue and its operations:
struct Queue {

    int size;
    int front;
    int rear;
    int *Q;

};


void createQueue(struct Queue *q) {
    printf("Enter the size of the queue: \n");
    scanf("%d", &q->size);

    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(int) * q->size);

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

int isEmptyQueue(struct Queue q) {
    if(q.rear == q.front) {
        return 1;
    }

    return 0;
}

int isFullQueue(struct Queue q) {
    if(q.rear == q.size - 1) {
        return 1;
    }

    return 0;

}

int peekQueue(struct Queue *q, int pos) {
    int x = -1;
    if(isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int index = q->front - pos + 1;
    if(index <= 0 || index > q->rear) {
        printf("Invalid position\n");
        return -1;
    }

    return q->Q[index];
}



// #################################################################################
// 3) Circular Queue:

struct CircularQueue {

    int size;
    int front;
    int rear;
    int *Q;

};

void createCircularQueue(struct CircularQueue *cq) {
    printf("Enter the size of the circular Queue: \n");
    scanf("%d", &cq->size);

    cq->front = cq->rear = 0;
    cq->Q = (int *)malloc(sizeof(int) * cq->size);

}


void enqueueCircularQueue(struct CircularQueue *cq, int ele) {
    if((cq->rear + 1) % cq->size == cq->front) {
        printf("Queue is full\n");
        return;
    }

    else {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->Q[cq->rear] = ele;
    }
}


int dequeueCircularQueue(struct CircularQueue *cq) {
    int x = -1;
    if(cq->front == cq->rear) {
        printf("The queue is empty\n");
        return;
    }

    else {
        cq->front = (cq->front + 1) % cq->size;
        x = cq->Q[cq->front];
    }

    return x;
}

int main() {

}