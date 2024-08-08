//13.	Write a program that performs matrix multiplication.

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void multiplyMatrices(int firstMatrix[MAX_ROWS][MAX_COLS], int secondMatrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    int i,j,k;
	if (cols1 != rows2) {
        printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");
        return;
    }

    for ( i = 0; i < rows1; ++i) {
        for ( j = 0; j < cols2; ++j) {
            result[i][j] = 0;
        }
    }

    for ( i = 0; i < rows1; ++i) {
        for ( j = 0; j < cols2; ++j) {
            for ( k = 0; k < cols1; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i,j;
	for ( i = 0; i < rows; ++i) {
        for ( j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int firstMatrix[MAX_ROWS][MAX_COLS], secondMatrix[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2,i,j;

    printf("Enter the dimensions of the first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of the first matrix:\n");
    for ( i = 0; i < rows1; ++i) {
        for ( j = 0; j < cols1; ++j) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter the dimensions of the second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of the second matrix:\n");
    for ( i = 0; i < rows2; ++i) {
        for ( j = 0; j < cols2; ++j) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, result, rows1, cols1, rows2, cols2);

    printf("Product of the matrices:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}

