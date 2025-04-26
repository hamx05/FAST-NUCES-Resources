#include <stdio.h>

int main () {
printf("Student ID: 23K-2005\n");
printf("Student Name: Muhammad Hammad\n\n");
	
	int i, j, n, t, arr[10];
	
	printf("enter the length of the array: ");
	scanf("%d", &n);
	
	printf("enter the elements of the array: ");
	for (i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("enter the sum/target that you want to find: ");
	scanf("%d", &t);
		
	for (i=0; i<n; i++) { 
		for (j=i+1; j<n; j++) { 
			if (arr[i] + arr[j] == t) {
				printf("(%d, %d)",arr[i], arr[j]);
			}
		}
	}	
	
	return 0;
}

