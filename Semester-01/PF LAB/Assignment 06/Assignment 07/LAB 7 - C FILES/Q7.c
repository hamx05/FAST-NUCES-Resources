#include <stdio.h> 

int main () {
	
	int i, j, k, null[2][2] = {{0,0} ,{0,0}}, matrix1[2][2], matrix2[2][2], multiply[2][2]={0,0,0,0}, result[2][2]={0,0,0,0};
	
	printf("enter the first matrix: ");
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {
			scanf("%d" , &matrix1[i][j]);
		}
	}
	
	printf("enter the second matrix: ");
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {
			scanf("%d" , &matrix2[i][j]);
		}
	}                             
	                                 // |a1  b1|   |a2  b2|  ->  |a1*a2 + b1*c2   a1*b2 + b1*d2|
									 // |c1  d1|   |c2  d2|  ->  |c1*a2 + d1*c2   c1*b2 + d1*d2|
	
	
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {	
			result [i][j]=0;
			for (k=0;k<2;k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
	//			result[i][j] = result[i][j] + result[i][j];
	// result[i][j] = matrix1[i][j] * matrix2[j][i] + matrix1[i][k] * matrix2[k][i];
	//	 printf("%d  ", result[i][j]);
	//	 printf("\n");
	//	 result[i][j] = result [i][j] + multiply [i][j];
			}
		}
		 	
	}
	
	printf("Resultant matrix = \n");
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {
			printf("%d  ", result[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
