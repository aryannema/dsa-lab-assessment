#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temporary arrays:
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }


    // merge two halves:
    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }


    // copy remaining elements:
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}



void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

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