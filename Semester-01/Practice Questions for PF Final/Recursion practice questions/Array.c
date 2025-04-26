#include <stdio.h>

void printArray (int arr[], int start, int length) {
	
	if (start==length) {
		return;
	}
	
	printf("%d ", arr[start]);
	
	printArray(arr, start+1, length);
	
}



int main () {
	
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	printArray (arr,0,10);
	
	
	return 0;
}
