#include <stdio.h>

void insertSorted(int arr[], int *size, int element) {
    int i;

    for (i = *size - 1; i >= 0 && arr[i] > element; --i) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = element;
    (*size)++;
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2, i, k = 0; // Declare 'k' here

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter %d elements for the first array in sorted order:\n", size1);
    for (i = 0; i < size1; ++i) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int arr2[size2];
    printf("Enter %d elements for the second array in sorted order:\n", size2);
    for (i = 0; i < size2; ++i) {
        scanf("%d", &arr2[i]);
    }

    int sizeResult = size1 + size2;
    int result[sizeResult];

    for (i = 0; i < size1; ++i) {
        insertSorted(result, &k, arr1[i]);
    }

    for (i = 0; i < size2; ++i) {
        insertSorted(result, &k, arr2[i]);
    }

    printf("Merged Array in Sorted Order:\n");
    for (i = 0; i < sizeResult; ++i) {
        printf("%d ", result[i]);
    }

    return 0;
}

