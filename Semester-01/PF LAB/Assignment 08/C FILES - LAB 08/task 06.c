#include <stdio.h>

int main () {
	int sum, min, max;
	processArray(sum,min,max);
	return 0;
}

void processArray (int sum, int min, int max) {
	int i, n, arr[5];
	sum=0, min=999999, max=0;
	
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
	printf("Enter the elements of the array: ");
	scanf("%d", &arr[i]);
	}
	
	for (i=0; i<n; i++) {
		sum += arr[i];
		if (min>arr[i]) {
			min = arr [i];
		}
		if (max<arr[i]) {
			max = arr [i];
		}
	}

	printf("The sum of the array is: %d\n", sum);
	printf("The minimum value of the array is: %d\n", min);
	printf("The maximum value of the array is: %d\n", max);
	
}
