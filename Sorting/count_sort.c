#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n)  {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}


void countSort(int arr[], int n) {
    int max = findMax(arr, n);

    int *count = (int *)calloc(max + 1, sizeof(int));

    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int j = 0;

    for(int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }

    free(count);
}

int main() {
    return 0;
}