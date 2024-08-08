/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-BhavinSir
*/

#include <stdio.h>

void matrixAddition(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int columns) {
    int i,j;
	for ( i = 0; i < rows; i++) {
        for ( j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixMultiplication(int matrix1[][10], int matrix2[][10], int result[][10], int rows1, int columns1, int columns2) {
   	int i,j,k;
    for ( i = 0; i < rows1; i++) {
        for ( j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for ( k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, columns1, rows2, columns2,i,j;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &columns1);

    printf("Enter the elements of matrix 1:\n");
    for ( i = 0; i < rows1; i++) {
        for ( j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &columns2);

    printf("Enter the elements of matrix 2:\n");
    for ( i = 0; i < rows2; i++) {
        for ( j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int choice;
    do{
    printf("Menu:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rows1 == rows2 && columns1 == columns2) {
                matrixAddition(matrix1, matrix2, result, rows1, columns1);
                printf("Resultant matrix after addition:\n");
                for ( i = 0; i < rows1; i++) {
                    for ( j = 0; j < columns1; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Matrix addition is not possible.\n");
            }
            break;
        case 2:
            if (columns1 == rows2) {
                matrixMultiplication(matrix1, matrix2, result, rows1, columns1, columns2);
                printf("Resultant matrix after multiplication:\n");
                for ( i = 0; i < rows1; i++) {
                    for ( j = 0; j < columns2; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Matrix multiplication is not possible.\n");
            }
            break;
        case 3:
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    }while(choice!=3);
    return 0;
}
