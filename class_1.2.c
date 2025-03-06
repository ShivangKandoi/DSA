#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];
    int rows = 3, cols = 3;

    printf("Input for matrix 1:\n");
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Input for matrix 2:\n");
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\n");

    printf("What operation do you want; (1) Addition (2) Subtraction (3) Multiplication:\n");
    int operation;
    scanf("%d", &operation);

    if (operation == 1) {
        // Addition of matrices
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printf("Result of addition:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else if (operation == 2) {
        // Subtraction of matrices
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        printf("Result of subtraction:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else if (operation == 3) {
        // Multiplication of matrices
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("Result of multiplication:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid operation\n");
        return 1;
    }

    return 0;
}
