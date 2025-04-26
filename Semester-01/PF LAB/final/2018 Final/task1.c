#include <stdio.h>

int main () {
	
	int i, n, sum=0;
	int arr[10];
	
	printf("enter the size of the array: ");
	scanf("%d", &n);
	
	printf("enter %d elements: ", n);
	for (i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}
	
	for (i=0;i<n;i++) {
		sum += arr[i];
	}
	
	printf("\nThe sum of the array is: %d", sum);
	
	
	return 0;
}
