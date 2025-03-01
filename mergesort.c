#include <stdio.h>

void mergearrays(int arr[], int start, int mid, int end) {
    int n = end - start + 1;
    int temp[n];

    int left = start;
    int right = mid + 1;
    int index = 0;

    // Merge the two halves
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    // If there are remaining elements in the left half
    while (left <= mid) {
        temp[index] = arr[left];
        left++;
        index++;
    }

    // If there are remaining elements in the right half
    while (right <= end) {
        temp[index] = arr[right];
        right++;
        index++;
    }

    // Copy the merged elements back into the original array
    index = 0;
    while (start <= end) {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergesort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    // Sort the left half
    mergesort(arr, start, mid);

    // Sort the right half
    mergesort(arr, mid + 1, end);

    // Merge the sorted halves
    mergearrays(arr, start, mid, end);
}

int main() {
    int arr1[] = {5, 6, 1, 2, 8, 4, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int start=0;
    int end=n-1;

    // Sort the array using mergesort
    mergesort(arr1,start,end);

    // Print the sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}
