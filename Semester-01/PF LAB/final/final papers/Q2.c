#include <stdio.h>

int main () {
	
	int i=0, j=0, k=0, M, N;
	int matrix[10][10];
	int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0;
	
	printf("enter the no. of columns: ");
	scanf("%d", &N);
	
	matrix[i][j] = 0;
	
	
	printf("enter the elements: ");
	
	while (matrix[i][j] != -1) {
		printf("enter row %d:\n",i+1);
		for (j=0; j<N; j++) {
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] == -1) {
				printf("-1 found. exit\n\n");
				break;
			}
		}
		if (matrix[i][j] == -1) {
				break;
			}
		i++;
	}
	M = i;
	
	// Now, taking sum of 3x3 matrix
	
	for (i=0; i<3; i++) { // 1
		for (j=0; j<3; j++) {
			sum1 += matrix[i][j];
		}
	}
	
	for (i=0; i<3; i++) { // 2
		for (j=0; j<3; j++) {
			sum2 += matrix[i][j+1];
		}
	}
	
	for (i=0; i<3; i++) { // 3
		for (j=0; j<3; j++) {
			sum3 += matrix[i+1][j];
		}
	}
	
	for (i=0; i<3; i++) { // 4
		for (j=0; j<3; j++) {
			sum4 += matrix[i+1][j+1];
		}
	}
	
	for (i=0; i<3; i++) { // 5
		for (j=0; j<3; j++) {
			sum5 += matrix[i+2][j];
		}
	}
	
	for (i=0; i<3; i++) { // 6
		for (j=0; j<3; j++) {
			sum6 += matrix[i+2][j+1];
		}
	}
	
	for (i=0; i<3; i++) { // 7
		for (j=0; j<3; j++) {
			sum7 += matrix[i+3][j];
		}
	}
	
	for (i=0; i<3; i++) { // 8
		for (j=0; j<3; j++) {
			sum8 += matrix[i+3][j+1];
		}
	}

	i=j=0;
	
	int **result = (int **)calloc(M-2, sizeof(int *));  
	for (int i = 0; i < M-2; i++) {
        result[i] = (int *)calloc(N-2, sizeof(int));
	}
	
	result[M-2][N-2] = {{sum1,sum2}, {sum3,sum4}, {sum5,sum6},{sum7,sum8}};

	for (i=0; i<M-2; i++) {
		for (j=0; j<N-2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}


	
	
	return 0;
}
