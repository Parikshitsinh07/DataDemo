#include <stdio.h>

// Function to perform heapify operation on a subtree rooted at index i in the array arr[]
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as the root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap it with the root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on an array arr[] of size n
void heapSort(int arr[], int n) {
    // Build a max heap
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
	for ( i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Perform Heap Sort
    heapSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}

