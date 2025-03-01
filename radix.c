#include <stdio.h>
#include <limits.h>

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max_element = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    return max_element;
}

// Counting Sort for a specific digit place (pos)
void countSort(int arr[], int n, int pos) {
    int freq[10] = {0}; // Frequency array for digits 0-9
    int ans[n]; // Temporary output array

    // Counting occurrences of each digit at the current place value
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    // Cumulative frequency calculation
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Placing elements in sorted order based on the current digit
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }

    // Copy sorted values back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

// Radix Sort implementation
void radixSort(int arr[], int n) {
    int max_element = findMax(arr, n); // Find the max element in array

    // Apply counting sort for each digit position (units, tens, hundreds, etc.)
    for (int pos = 1; max_element / pos > 0; pos *= 10) {
        countSort(arr, n, pos);
    }
}

// Main function
int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; // Array of size n (no pointers)

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n); // Perform Radix Sort

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
