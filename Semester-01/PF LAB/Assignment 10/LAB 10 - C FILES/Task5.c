#include <stdio.h>
#include <stdlib.h>

void SortFunction(int *arr, int size, int order) {
	int i,j, temp=0;
	printf("\n");
	if (order==1) {
		for (i=0; i<size; i++) {
			for (j=0; j<size-1; j++) {
				if (arr[j] > arr[j+1]) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		for (i=0; i<size; i++) {
			printf("Sorted in ascending order: %d", arr[i]);
		}
	}
	
	else if (order==2) {
		for (i=0; i<size; i++) {
			for (j=0; j<size-1; j++) {
				if (arr[j] < arr[j+1]) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		printf("Sorted in descending order: ");
		for (i=0; i<size; i++) {
			printf("%d, ", arr[i]);
		}
	}
	
	else {
		printf("Invalid choice.");
		exit(1);
	}
	
}

int main () {
	int i,j, size, order;
	
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	int *arr = (int *)malloc(size*sizeof(int));
	printf("Enter %d integers: ", size);
	for (i=0; i<size; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Enter the order (1 for ascending, 2 for descending): ");
	scanf("%d", &order);
	
	SortFunction(*arr, size, order);
	
	free(arr);
	return 0;
}
