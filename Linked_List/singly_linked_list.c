#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;


void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}


void display(struct Node *p) {
    while(p != NULL){
        printf("%d", p->data);
        p = p->next;
    }
}


// counting the number of nodes:
int count(struct Node *p) {
    int c = 0; 
    while(p) {
        c++;
        p = p->next;
    }
    return c;
}

// finding maximum value:
int max(struct Node *p) {
    int m = INT_MIN;

    while(p) {
        if(p->data > m) {
            m = p -> data;
        }
        p = p->next;
    }

    return m;
}


// insert an element at a particular position (this covers for adding the start too):
void insert(struct Node *p, int pos, int x) {

    if(pos < 0 || pos > count(p)) return;

    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;


    if(pos == 0) {
        t->next = first;
        first = t;
    }

    else {
        for(int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}


void insertLast(struct Node *p, int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL){
        first = last = t;
    }

    else {
        last ->next = t;
        last = t;

    }
}


int Delete(struct Node *p, int index) {
    struct Node *q = NULL;

    int x = -1;
    if(index < 1 || index > count(p)) {
        return -1;
    }

    if(index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;

    }

    else {
        for(int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        return x;
    }
}


int main() {
    return 0;
}