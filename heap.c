#include <stdio.h>

// Swap function using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void maxHeapify(int A[], int n, int i) {
    int largest = i;
    int l = 2 * i;     // Left child index
    int r = 2 * i + 1; // Right child index

    if (l <= n && A[l] > A[largest])
        largest = l;
    
    if (r <= n && A[r] > A[largest])
        largest = r;
    
    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int A[], int n) {
    for (int i = n / 2; i >= 1; i--)
        maxHeapify(A, n, i);
}

// Heap Sort function
void heapSort(int A[], int n) {
    buildMaxHeap(A, n);  // Step 1: Build a max heap
   
    //after building max heap delete the top elemeny
    for (int i = n; i > 1; i--) {
        swap(&A[1], &A[i]);  // Step 2: Move the max element to the end
        maxHeapify(A, i - 1, 1);  // Step 3: Restore the heap property
    }
}

// Driver Code
int main() {
    int A[] = {0, 30, 17, 20, 1, 5, 10, 15}; // Array indexed from 1; A[0] is unused
    int n = sizeof(A) / sizeof(A[0]) - 1;   // Number of valid elements

    printf("Original Array: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    heapSort(A, n);  // Perform Heap Sort

    printf("Sorted Array: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
