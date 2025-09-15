#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {

    int size;
    int top;
    char *S;

};

void createStack(struct Stack *st) {
    st->top = -1;
    printf("Enter the size of the character array: \n");
    scanf("%d", &st->size);
    st->S = (char *)malloc(sizeof(char) * st->size);

}

int isEmpty(struct Stack *st) {
    return st->top == -1;
}

int isFull(struct Stack *st) {
    return st->top == st->size - 1;
}

void push(struct Stack *st, char ch) {
    if(isFull(st)) {
        printf("Stack overflow\n");
        return;
    }

    else {
        st->top++;
        st->S[st->top] = ch;
    }
}

char pop(struct Stack *st) {
    char x = -1;

    if(isEmpty(st)) {
        printf("The stack is empty\n");
        return (char) -1;
    }

    else {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}



int precedence(char x) {
    if(x == '^') return 3;
    if(x == '*' || x == '/' || x == '%') return 2;
    if(x == '+' || x == '-') return 1;
    return 0;
}

char stackTop(struct Stack *st) {
    if(isEmpty(st)) return (char) -1;
    return st->S[st->top];

}

void reverse(char *str) {
    int n = strlen(str);

    for(int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    char rev[100], post[100];
    strcpy(rev, infix);
    reverse(rev);

    for(int i = 0; rev[i]; i++) {
        if(rev[i] == '(') rev[i] = ')';
        else if(rev[i] == ')') rev[i] = '(';
    }

    struct Stack st;
    createStack(&st);

    int i = 0, k = 0;
    char ch;

    while((ch = rev[i++]) != '\0') {
        if(isalnum(ch)) post[k++] = ch;
        else if(ch == '(') push(&st, ch);
        else if(ch == ')') {
            while(!isEmpty(&st) && stackTop(&st) != '(') {
                post[k++] = pop(&st);
            }

            pop(&st);
        }

        else {
            while(!isEmpty(&st) && precedence(stackTop(&st)) >= precedence(ch)) {
                post[k++] = pop(&st);
            }
            push(&st, ch);
        }
    }

    while(!isEmpty(&st)) post[k++] = pop(&st);
    post[k] = '\0';

    reverse(post);
    strcpy(prefix, post);

}




int main() {
    char infix[100], prefix[100];
    printf("Enter the infix expression: \n");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    return 0;
}