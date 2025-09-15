#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int recursiveLinearSearch(int arr[], int n, int target) {
    if(n == 0) return -1;

    if(arr[n - 1] == target) return n - 1;

    return recursiveLinearSearch(arr, n - 1, target);
}
int main() {
    return 0;
}