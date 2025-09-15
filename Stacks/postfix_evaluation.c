#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *S;
};

void create(struct Stack *st, int size)  {
    st->size = size;
    st->top = -1;
    st->S = (int *)malloc(sizeof(int) * st->size);
}

int isEmpty(struct Stack *st) {
    return st->top == -1;
}

int isFull(struct Stack *st) {
    return st->top == st->size - 1;

}


void push(struct Stack *st, int x) {
    if(isFull(&st)) {
        printf("Stack overflow\n");
        return;     

    }

    else {
        st->top++;
        st->S[st->top++] = x;
    }
}


int pop(struct Stack *st) {
    int x = -1;
    if(isEmpty(&st)) {
        printf("Stack underflow\n");
        return -1;
    }

    else {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}


int evaluatePostfix(struct Stack *st, char *exp) {
    for(int i = 0; exp[i] != '\0'; i++){
        char ch = exp[i];

        if(isdigit(ch)){
            push(&st, ch - '0');
        }

        else {
            int val2 = pop(&st);
            int val1 = pop(&st);

            switch(ch){
                case '+': push(&st, val1 + val2); break;
                case '-': push(&st, val1 - val2); break;
                case '*': push(&st, val1 * val2); break;
                case '/': push(&st, val1 / val2); break;
            }
        }
    }

    return pop(&st);
}