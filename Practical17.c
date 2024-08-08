#include <stdio.h>
#include <string.h>

void Sort(char (*names)[50], int index) {
    int i, j;
    for (i = 0; i < index; i++) {
        for (j = 0; j < index - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarySearch(char arr[][50], int left, int right, char* Search) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], Search);

        if (cmp == 0) {
            return mid;  // Name found, return its position
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Name not found in the array
}

int main() {
    int Array_length, Name_Length, i, option;
    int index = 0;

    printf("Enter Your Array Size: ");
    scanf("%d", &Array_length);

    printf("Enter Your Name Character Size: ");
    scanf("%d", &Name_Length);

    char search_name[Name_Length];
    char names[Array_length][50];

    do {
        printf("\n\nSelect operations for the String Array:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Add Name In Array\n2. Search Name In Array\n3. Display Array\n0. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter Your name: ");
                scanf("%s", names[index]);
                if (index < Array_length) {
                    index++;
                    Sort(names, index);
                } else {
                    printf("Array is Full\n");
                }
                break;
            case 2:
                printf("Enter a name to search: ");
                scanf("%s", search_name);
                int position = binarySearch(names, 0, index - 1, search_name);
                if (position != -1) {
                    printf("%s found at position %d in the array.\n", search_name, position + 1);
                } else {
                    printf("%s not found in the array.\n", search_name);
                }
                break;
            case 3:
                printf("\nYou entered the following names:\n");
                for (i = 0; i < index; i++) {
                    printf("%d: %s\n", i + 1, names[i]);
                }
                break;
            case 0:
                printf("Program Exit\n");
                break;
            default:
                printf("Enter a valid Option\n");
                break;
        }
    } while (option != 0);

    return 0;
}

