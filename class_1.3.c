#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void upperTriangular(int **matrix, int **upper, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i <= j) {
                upper[i][j] = matrix[i][j];
            } else {
                upper[i][j] = 0;
            }
        }
    }
}

void lowerTriangular(int **matrix, int **lower, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= j) {
                lower[i][j] = matrix[i][j];
            } else {
                lower[i][j] = 0;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int **result = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *)malloc(size * sizeof(int));
    }

    int choice;
    printf("Enter 1 for Upper Triangular Matrix or 2 for Lower Triangular Matrix: ");
    scanf("%d", &choice);

    if (choice == 1) {
        upperTriangular(matrix, result, size);
        printf("\nUpper Triangular Matrix:\n");
    } else if (choice == 2) {
        lowerTriangular(matrix, result, size);
        printf("\nLower Triangular Matrix:\n");
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printMatrix(result, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}