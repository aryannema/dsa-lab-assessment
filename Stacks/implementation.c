#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};


void create(struct Stack *st) {
    printf("Enter the stack size\n");
    scanf("%d", &st->size);

    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st) {
    for(int i = st.top; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}


void push(struct Stack *st, int ele) {
    if(st->top == st->size - 1) {
        printf("Stack overflow\n");
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


int peek(struct Stack st, int pos) {
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

    else {
        return st.S[st.top];
    }
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


int main() {
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    printf("The element that got popped: %d\n", pop(&st));
    printf("The element that got popped: %d\n", pop(&st));
    
    display(st);
    return 0;
}