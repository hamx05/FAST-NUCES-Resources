#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;

    // Get the number of columns
    printf("Enter the number of columns: ");
    scanf("%d", &N);
  
    // Initialize variables for matrix input
    int value;
    int **matrix = NULL;
    int row = 0;

    // Dynamically allocate memory for the input matrix
    while (1) {
        printf("Enter values for row %d (type -1 to stop): ", row + 1);

        // Initialize matrix for the first row
        if (row == 0) {
            matrix = (int **)malloc(sizeof(int *));
            matrix[0] = (int *)malloc(N * sizeof(int));
        } else {
            // Allocate memory for the next row
            int **tempMatrix = (int **)malloc((row + 1) * sizeof(int *));
            for (int i = 0; i < row; ++i) {
                tempMatrix[i] = matrix[i];
            }
            tempMatrix[row] = (int *)malloc(N * sizeof(int));

            // Delete the old matrix
            free(matrix);
            matrix = tempMatrix;
        }

        // Read values for the current row
        for (int j = 0; j < N; ++j) {
            scanf("%d", &value);

            // Check for the stop condition
            if (value == -1) {
                break;
            }

            matrix[row][j] = value;
        }

        // Check for the stop condition
        if (value == -1) {
            break;
        }

        // Increment row counter
        ++row;
    }

    // Calculate dimensions for the result matrix
    int resultRows = row - 2;
    int resultCols = N - 2;

    // Check if the result matrix dimensions are valid
    if (resultRows <= 0 || resultCols <= 0) {
        fprintf(stderr, "Invalid dimensions for the result matrix. Exiting.\n");
        return 1;
    }

    // Allocate memory for the result matrix
    int **results = (int **)malloc(resultRows * sizeof(int *));
    for (int i = 0; i < resultRows; ++i) {
        results[i] = (int *)malloc(resultCols * sizeof(int));
    }

    // Populate the result matrix
    for (int i = 0; i < resultRows; ++i) {
        for (int j = 0; j < resultCols; ++j) {
            // Sum the 3x3 matrix centered at i+1, j+1
            results[i][j] = matrix[i + 1][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 2] +
                            matrix[i][j + 1] + matrix[i][j] + matrix[i][j + 2] +
                            matrix[i + 2][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 2];
        }
    }

    // Output the result matrix
    printf("Result Matrix:\n");
    for (int i = 0; i < resultRows; ++i) {
        for (int j = 0; j < resultCols; ++j) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for input matrix
    for (int i = 0; i <= row; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    // Deallocate memory for result matrix
    for (int i = 0; i < resultRows; ++i) {
        free(results[i]);
    }
    free(results);
       
    return 0;
}

