#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


// Sorting:
// 1) Bubble sort:
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int flag = 1;

        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if(flag == 0) return;
    }
}

// 2) selection sort:
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 3) insertion sort:
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


// 4) merge sort:
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }

}


void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

    }
}








// Stack:
struct Stack {

    int size;
    int top;
    int *S;

};


void createStack(struct Stack *st) {
    st->top = -1;
    printf("Enter the size of the stack: \n");
    scanf("%d", &st->size);

    st->S = (int *)malloc(sizeof(int) * st->size);

}

void push(struct Stack *st, int x) {
    if(st->top == st->size - 1) {
        printf("Stack Overflow\n");
        return;
    }

    else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;

    if(st->top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    else {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}


int peek(struct Stack *st, int pos) {
    int x = -1;

    if(st->size - pos + 1 < 0) {
        printf("Invalid position\n");
        return;
    }

    else {
        x = st->S[st->size - pos + 1];
    }

    return x;
}





// Queues:
// 1) linear queue using arrays:

struct Queue {

    int size;
    int front;
    int rear;
    int *Q;

};


void createQueue(struct Queue *q) {
    q->front = q->rear = -1;
    printf("Enter the queue size: \n");
    scanf("%d", &q->size);

    q->Q = (int *)malloc(sizeof(int) * q->size);
    
}


















































int main() {
    int size = 5;
    // printf("Enter the size of the array: \n");
    // scanf("%d", &size);

    // int arr[size];
    // printf("Enter the array elements: \n");
    // for(int i = 0; i < size; i++) {
    //     scanf("%d", &arr[i]);
    // }

    int arr[5] = {30, 50, 20, 10, 40};
    

    printf("Original array: \n");
    printArray(arr, size);
    printf("\n");

    printf("Sorted array: \n");
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}