#include <stdio.h>
#include <stdlib.h>

int main() {

    int i = 0, j = 0, k, M, N;
    int matrix[10][10];
    int** result;

    printf("enter the no. of columns: ");
    scanf("%d", &N);

    printf("enter the elements: ");

    // Initialize the matrix elements
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matrix[i][j] = 0; // You can choose a default value here
        }
    }

    i = 0;
    j = 0;

    while (matrix[i][j] != -1) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == -1) {
                printf("-1 found. exit");
                break;
            }
        }
        if (matrix[i][j] == -1) {
            break;
        }
        i++;
    }
    M = i;

    result = (int**)calloc(M - 2, sizeof(int*));
    for (i = 0; i < M - 2; i++) {
        result[i] = (int*)calloc(N - 2, sizeof(int));
    }

    // Now, taking the sum of the 3x3 matrix
    for (i = 0; i < M - 2; i++) {
        for (j = 0; j < N - 2; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += matrix[i + k][j]; // Corrected indices
            }
        }
    }

    // Print the result
    for (i = 0; i < M - 2; i++) {
        for (j = 0; j < N - 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < M - 2; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

