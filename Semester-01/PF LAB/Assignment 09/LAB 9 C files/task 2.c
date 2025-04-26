#include <stdio.h>
void reverse(int *, int );
int main () {
	
	int i,size, arr[10], result;
	
	printf("enter the size of the array: ");
	scanf("%d", &size);
	for (i=0;i<size;i++) {
	printf("enter the element %d of the array: ", i+1);
	scanf("%d", &arr[i]);
	}
	
	printf("\nThe entered array is: ");
	for (i=0;i<size;i++) {
	printf("%d, ", arr[i]);
	}
	
	reverse(arr,size);
	
	return 0;
}

void reverse(int *arr, int size) {
	int i;
	
	printf("\nThe reversed array is: ");
	for (i=size-1;i>=0;i--) {
	printf("%d, ", arr[i]);
	
	}
	
}
