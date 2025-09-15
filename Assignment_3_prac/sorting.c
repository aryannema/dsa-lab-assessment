#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1) bubble sort:
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int flag = 0;

        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 1;
            }
        }

        if(flag == 0) break;
    }
}



// 2) selection sort:
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
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
        if(L[i] < R[j]) {
            arr[k++] = L[i++];
        }

        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];


}


void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main() {
    int size;
    printf("Enter the size of the array: \n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // original array:
    printf("The original array is: \n");
    printArray(arr, size);

    printf("The sorted array: \n");
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}