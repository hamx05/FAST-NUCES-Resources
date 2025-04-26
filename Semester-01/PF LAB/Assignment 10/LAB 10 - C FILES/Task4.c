#include <stdio.h>

void PrintTranspose(int **matrix, int rows, int cols) {
	int **transpose = (int**)calloc(rows,sizeof(int *));
    for (int i=0; i<rows; ++i) {
        transpose[i] = (int*)calloc(cols,sizeof(int));
    }
	
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}
	
	printf("Transposed matrix: \n");
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			printf("%d ", transpose[i][j]);
		} 
		printf("\n");
	}
}

int main () {
	int i, j, rows, cols;	
	
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("Enter the number of columns: ");
	scanf("%d", &cols);
	
	int **matrix = (int**)calloc(rows,sizeof(int *));
    for (int i=0; i<rows; ++i) {
        matrix[i] = (int*)calloc(cols,sizeof(int));
    }

	printf("Enter the elements of the matrix: ");
	for (i=0; i<rows; i++) {
		for (j=0; j<cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("Original matrix: \n");
	for (i=0; i<rows; i++) {
		for (j=0; j<cols; j++) {
			printf("%d ", matrix[i][j]);
		} 
		printf("\n");
	}
	
	PrintTranspose(matrix, rows, cols);
	free(matrix);
	return 0;
}


