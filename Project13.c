/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-BhavinSir
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right; 
    struct Node* down;  
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}


struct Node* createMatrix(int rows, int cols) {
    int i, j, data;
    struct Node* matrix[rows][cols];

 
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &data);
            matrix[i][j] = createNode(data);
        }
    }

 
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (j < cols - 1) {
                matrix[i][j]->right = matrix[i][j + 1];
            }
            if (i < rows - 1) {
                matrix[i][j]->down = matrix[i + 1][j];
            }
        }
    }

 
    return matrix[0][0];
}


void displayMatrix(struct Node* start) {
    struct Node* currentRow = start;


    while (currentRow != NULL) {
        struct Node* currentCol = currentRow;

   
        while (currentCol != NULL) {
            printf("%d ", currentCol->data);
            currentCol = currentCol->right;
        }

        printf("\n");
        currentRow = currentRow->down; 
    }
}

int main() {
    int rows, cols, choice;
    struct Node* matrix = NULL;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    do {
        printf("\nMenu:\n");
        printf("1. Create Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                matrix = createMatrix(rows, cols);
                printf("Matrix created successfully!\n");
                break;
            case 2:
                if (matrix != NULL) {
                    printf("Matrix:\n");
                    displayMatrix(matrix);
                } else {
                    printf("Matrix is not created yet. Please choose option 1 to create a matrix.\n");
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

