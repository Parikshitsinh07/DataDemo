#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Node structure for the sparse matrix
struct Node {
    struct SparseElement data;
    struct Node* nextRow; // Link to the next element in the same row
    struct Node* nextCol; // Link to the next element in the same column
};

// Function to create a new node with a sparse element
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data.row = row;
    newNode->data.col = col;
    newNode->data.value = value;
    newNode->nextRow = NULL;
    newNode->nextCol = NULL;
    return newNode;
}

// Function to create a multilinked sparse matrix
struct Node* createSparseMatrix(int rows, int cols) {
    int i, j, value;
    struct Node* matrix[rows][cols];

    // Input data for each element and create nodes
    printf("Enter sparse matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &value);

            // Create a node only for non-zero values
            if (value != 0) {
                matrix[i][j] = createNode(i, j, value);
            } else {
                matrix[i][j] = NULL;
            }
        }
    }

    // Link the nodes to create the multilinked structure
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != NULL) {
                // Link to the next element in the same row
                matrix[i][j]->nextRow = matrix[i][(j + 1) % cols];
                // Link to the next element in the same column
                matrix[i][j]->nextCol = matrix[(i + 1) % rows][j];
            }
        }
    }

    // Return the top-left node of the matrix
    return matrix[0][0];
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* start, int rows, int cols) {
    int i, j;

    // Loop through each row
    for (i = 0; i < rows; i++) {
        struct Node* current = start;

        // Loop through each column
        for (j = 0; j < cols; j++) {
            if (current != NULL && current->data.row == i && current->data.col == j) {
                // If the current node exists and matches the current position, print its value
                printf("%d\t", current->data.value);
                current = current->nextRow; // Move to the next element in the row
            } else {
                // If the current node doesn't exist or doesn't match the position, print 0
                printf("0\t");
            }
        }

        printf("\n");
    }
}

// Function to add two sparse matrices
struct Node* addSparseMatrices(struct Node* matrix1, struct Node* matrix2, int rows, int cols) {
    int i, j;
    struct Node* resultMatrix[rows][cols];

    // Initialize result matrix with NULL
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            resultMatrix[i][j] = NULL;
        }
    }

    // Traverse both matrices and add corresponding elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix1 != NULL && matrix1->data.row == i && matrix1->data.col == j) {
                // If the current node in matrix1 exists and matches the position, add its value
                resultMatrix[i][j] = createNode(i, j, matrix1->data.value);
                matrix1 = matrix1->nextRow; // Move to the next element in matrix1's row
            }
            if (matrix2 != NULL && matrix2->data.row == i && matrix2->data.col == j) {
                // If the current node in matrix2 exists and matches the position, add its value
                if (resultMatrix[i][j] == NULL) {
                    resultMatrix[i][j] = createNode(i, j, matrix2->data.value);
                } else {
                    resultMatrix[i][j]->data.value += matrix2->data.value;
                }
                matrix2 = matrix2->nextRow; // Move to the next element in matrix2's row
            }
        }
    }

    // Link the nodes to create the multilinked structure for the result matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (resultMatrix[i][j] != NULL) {
                resultMatrix[i][j]->nextRow = resultMatrix[i][(j + 1) % cols];
                resultMatrix[i][j]->nextCol = resultMatrix[(i + 1) % rows][j];
            }
        }
    }

    // Return the top-left node of the result matrix
    return resultMatrix[0][0];
}

// Function to multiply two sparse matrices
struct Node* multiplySparseMatrices(struct Node* matrix1, struct Node* matrix2, int rows1, int cols1, int cols2) {
    int i, j, k;
    struct Node* resultMatrix[rows1][cols2];

    // Initialize result matrix with NULL
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            resultMatrix[i][j] = NULL;
        }
    }

    // Traverse both matrices and perform multiplication
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            int sum = 0;

            for (k = 0; k < cols1; k++) {
                // Traverse the corresponding row in matrix1 and column in matrix2
                struct Node* node1 = matrix1;
                struct Node* node2 = matrix2;

                while (node1 != NULL && node1->data.col != k) {
                    node1 = node1->nextRow;
                }

                while (node2 != NULL && node2->data.row != k) {
                    node2 = node2->nextCol;
                }

                if (node1 != NULL && node2 != NULL) {
                    sum += node1->data.value * node2->data.value;
                }
            }

            // If the sum is not zero, create a node in the result matrix
            if (sum != 0) {
                resultMatrix[i][j] = createNode(i, j, sum);
            }
        }
    }

    // Link the nodes to create the multilinked structure for the result matrix
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            if (resultMatrix[i][j] != NULL) {
                resultMatrix[i][j]->nextRow = resultMatrix[i][(j + 1) % cols2];
                resultMatrix[i][j]->nextCol = resultMatrix[(i + 1) % rows1][j];
            }
        }
    }

    // Return the top-left node of the result matrix
    return resultMatrix[0][0];
}

// Function to free the memory allocated for a sparse matrix
void freeSparseMatrix(struct Node* start) {
    struct Node* currentRow = start;
    struct Node* tempRow;

    // Traverse rows
    while (currentRow != NULL) {
        struct Node* currentCol = currentRow;
        struct Node* tempCol;

        // Traverse columns in the current row
        while (currentCol != NULL) {
            tempCol = currentCol;
            currentCol = currentCol->nextRow; // Move to the next element in the row
            free(tempCol); // Free the memory for the current element
        }

        tempRow = currentRow;
        currentRow = currentRow->nextCol; // Move to the next row
        free(tempRow); // Free the memory for the current row
    }
}

int main() {
    int rows1, cols1, rows2, cols2, choice;
    struct Node* matrix1 = NULL;
    struct Node* matrix2 = NULL;
    struct Node* resultMatrix = NULL;

    // Input dimensions for the first matrix
    printf("Enter the number of rows in the first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns in the first matrix: ");
    scanf("%d", &cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows in the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Exiting program.\n");
        return 1;
    }

    // Create the first sparse matrix
    printf("\nCreate the first sparse matrix:\n");
    matrix1 = createSparseMatrix(rows1, cols1);
    printf("Sparse matrix 1 created successfully!\n");

    // Create the second sparse matrix
    printf("\nCreate the second sparse matrix:\n");
    matrix2 = createSparseMatrix(rows2, cols2);
    printf("Sparse matrix 2 created successfully!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Display Sparse Matrices\n");
        printf("2. Add Sparse Matrices\n");
        printf("3. Multiply Sparse Matrices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSparse Matrix 1:\n");
                displaySparseMatrix(matrix1, rows1, cols1);
                printf("\nSparse Matrix 2:\n");
                displaySparseMatrix(matrix2, rows2, cols2);
                break;
            case 2:
                resultMatrix = addSparseMatrices(matrix1, matrix2, rows1, cols1);
                printf("\nResultant Matrix (Matrix 1 + Matrix 2):\n");
                displaySparseMatrix(resultMatrix, rows1, cols1);
                freeSparseMatrix(resultMatrix);
                break;
            case 3:
                resultMatrix = multiplySparseMatrices(matrix1, matrix2, rows1, cols1, cols2);
                printf("\nResultant Matrix (Matrix 1 * Matrix 2):\n");
                displaySparseMatrix(resultMatrix, rows1, cols2);
                freeSparseMatrix(resultMatrix);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the sparse matrices
    freeSparseMatrix(matrix1);
    freeSparseMatrix(matrix2);

    return 0;
}

