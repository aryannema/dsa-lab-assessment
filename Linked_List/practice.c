#include <stdio.h>
#include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *next;
// }*first = NULL, *last = NULL;


// void createLinkedList(int A[], int n) {
//     struct Node *t, *last;

//     first = (struct Node *)malloc(sizeof(struct Node));
//     first->data = A[0];
//     first->next = NULL;
//     last = first;

//     for(int i = 1; i < n; i++) {
//         t = (struct Node *)malloc(sizeof(struct Node));
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }


// void display(struct Node *p) {
//     while(p) {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }

// int count(struct Node *p) {
//     int c = 0;
//     while(p) {
//         c++;
//         p = p->next;
//     }

//     return c;
// }

// int insert(struct Node *p, int pos, int x) {
//     struct Node *t;

//     if(pos < 0 || pos > count(p)) return;

//     t = (struct Node *)malloc(sizeof(struct Node));
//     t->data = x;

//     if(pos == 0) {
//         t->next = first;
//         first = t;
//     }

//     else {
//         for(int i = 0; i < pos - 1; i++) {
//             p = p->next;
//         }

//         t->next = p->next;
//         p->next = t;
//     }

// }


// int insertLast(struct Node *p, int x) {
//     struct Node *t;
//     t = (struct Node *)malloc(sizeof(struct Node));
//     t->data = x;

//     if(first == NULL) {
//         last = first = t;
//     }

//     else {
//         last->next = t;
//         last = t;
//     }
// }


// int Delete(struct Node *p, int index) {
//     int x = -1;

//     struct Node *q = NULL;

//     if(index < 1 || index > count(p)) {
//         return -1;
//     }


//     if(index == 1) {
//         q = first;
//         x = first->data;
//         first = first->next;
//         free(q);
//         return x;
//     }

//     else {
//         for(int i = 0; i < index - 1; i++) {
//             q = p;
//             p = p->next;
//         }

//         q->next = p->next;
//         x = p->data;
//         return x;
//     }
// }



// doubly linked List:
struct Node {

    struct Node *prev;
    int data;
    struct Node *next;

}*first = NULL;


void create(int A[], int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;


    for(int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}


void display(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int length(struct Node *p) {
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }

    return len;
}

void insert(struct Node *p, int index, int x) {
    struct Node *t;

    if(index < 0 || index > length(p)) return;

    if(index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }

    else {
        for(int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next) {
            p->next->prev = t;
        }

        p->next = t;
    }
}