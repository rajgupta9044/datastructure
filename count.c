#include <stdio.h>
#include <limits.h>

void countsort(int arr[], int n) {
    int max_element = INT_MIN;

    // Find max element
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    int freq[max_element + 1]; // Frequency array

    // Initialize frequency array
    for (int i = 0; i <= max_element; i++) {
        freq[i] = 0;
    }

    // Count frequency of elements
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Cumulative frequency
    for (int i = 1; i <= max_element; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    int ans[n]; // Output array

    // Sorting
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[arr[i]]] = arr[i];
    }

    // Copy sorted values back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

int main() {
    int arr[] = {1, 2, 5, 3, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    countsort(arr, n);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
