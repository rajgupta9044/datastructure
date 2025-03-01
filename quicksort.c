#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int pos = start;

    for (int i = start; i <end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i] , arr[pos]);
            pos++;
        }
    }

    return pos;
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

int main() {
    int arr1[] = {5, 6, 1, 2, 8, 4, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int start = 0;
    int end = n - 1;

    quicksort(arr1, start, end);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}
