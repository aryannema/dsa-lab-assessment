#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// struct Stack {
//     int size;
//     int top;
//     char *S;
// };


// void createStack(struct Stack *st) {
//     printf("Enter the size of the character array: \n");
//     scanf("%d", &st->size);

//     st->top = -1;
//     st->S = (char *)malloc(sizeof(char) * st->size);
// }

// int isEmpty(struct Stack *st) {
//     return st->top == -1;
// }

// int isFull(struct Stack *st) {
//     return st->top == st->size -1;
// }

// void push(struct Stack *st, char ele) {
//     if(isFull(st)) {
//         printf("Stack overflow");
//         return;
//     }

//     else {
//         st->top++;
//         st->S[st->top] = ele;
//     }
// }

// char pop(struct Stack *st) {
//     char x = -1;

//     if(isEmpty(st)) {
//         printf("Stack is empty\n");
//         return;
//     }

//     else {
//         x = st->S[st->top];
//         st->top--;
//     }

//     return x;
// }


// int precedence(char x) {
//     if(x == '^') return 3;
//     if(x == '*' || x == '/' || x == '%') return 2;
//     if(x == '-' || x == '+') return 1;
//     return 0;
// }

// char stackTop(struct Stack *st) {
//     if(isEmpty(st)) return (char) -1;
//     return st->S[st->top];
// }


// void infixToPostfix(char *infix, char *postfix) {
//     struct Stack st;
//     createStack(&st);
//     int i = 0, k = 0;
//     char ch;

//     while((ch = infix[i++]) != '\0') {
//         if(isalnum(ch)) {
//             postfix[k++] = ch;
//         }

//         else if(ch == '(') push(&st, ch);

//         else if(ch == ')') {
//             while(!isEmpty(&st) && stackTop(&st) != '(') {
//                 postfix[k++] = pop(&st);
//             }

//             pop(&st);
//         }

//         else {
//             while(!isEmpty(&st) && precedence(stackTop(&st) >= precedence(ch))) {
//                 postfix[k++] = pop(&st);
//             }

//             push(&st, ch);
//         }
//     }

//     while(!isEmpty(&st)) {
//         postfix[k++] = pop(&st);
//     }

//     postfix[k] = '\0';
// }

// int main() {
//     char infix[100], postfix[100];
//     printf("Enter the infix expression:\n");
//     scanf("%s", infix);

//     infixToPostfix(infix, postfix);
//     printf("The postfix expression: %s\n", postfix);

//     return 0;
// }




struct Stack {
    int size;
    int top;
    char *S;
};

void createStack(struct Stack *st) {
    st->top = -1;
    printf("Enter the stack size: \n");
    scanf("%d", &st->size);

    st->S = (char *)malloc(sizeof(char) * st->size);
}

int isFull(struct Stack *st) {
    return st->top == st->size - 1;

}

int isEmpty(struct Stack *st) {
    return st->top == -1;
}


void push(struct Stack *st, char x) {
    if(isFull(&st)) {
        printf("Stack Overflow\n");
        return;
    }

    else {
        st->top++;
        st->S[st->top] = x;
    }
}

char pop(struct Stack *st) {
    char x = -1;

    if(isEmpty(&st)) {
        printf("Stack underflow\n");
        return;
    }

    else {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}


int precedence(char x) {
    if(x == "^") return 3;
    if(x == '/' || x == '*' || x == '%' ) return 2;
    if(x == '-' || x == '+') return 1;
    return 0;
}

char stackTop(struct Stack *st) {
    if(isEmpty(&st)) return(char) -1;

    return st->S[st->top];
}

char infixToPostfix(char *infix, char *postfix) {
    struct Stack *st;
    createStack(&st);

    int i = 0, k = 0;
    char ch;

    while((ch = infix[i++]) != '\0') {
        if(isalnum(ch)) {
            postfix[k++] = ch;
        }

        else if(ch == '(') {
            push(&st, ch);
        }

        else if(ch == ')') {
            while(!isEmpty(&st) && stackTop(&st) != '(') {
                postfix[k++] = pop(&st);
            }

            pop(&st);
        }

        else {
            while(!isEmpty(&st) && precedence(stackTop(&st)) >= precedence(ch)) {
                postfix[k++] = pop(&st);
            }

            push(&st,ch);
        }
    }

    while(!isEmpty(&st)) {
        postfix[k++] = pop(&st);
    }

    postfix[k] = '\0';
}

