#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for ( i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


void addressCalculationSort(int arr[], int n) {
    int max = findMax(arr, n);
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
	int i;

    for ( i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for ( i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for ( i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

   
    for ( i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}


void printArray(int arr[], int n) {
    int i;
	for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n,i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Sort the array using Address Calculation Sort\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addressCalculationSort(arr, n);
                printf("Array sorted using Address Calculation Sort.\n");
                printf("Sorted array: ");
                printArray(arr, n);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

