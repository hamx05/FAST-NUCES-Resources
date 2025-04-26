#include <stdio.h>

int main () {
	
	int freq[100]={0,0,0,0,0}, n, i, j, k=i-1, count, arr[100];
	 
	printf("enter the length of the array: ");
	scanf("%d", &n);

	
	for (i=0; i<n; i++) {
		printf("enter the element %d of the array: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	
	for (i=0; i<n; i++) { // {2,4,2,3,5,5,4,4}
		count=1;
		for (j=i+1; j<n; j++) {
				if (arr[i]==arr[j]) {
				count++;
				freq[j] = -1; // ye element ko processed mark krdega
				}
		}
				if (freq[i] != -1) { // ye check krega if the number is repeated or not
				printf("Frequency of %d is %d\n", arr[i], count);
				}
	}
	
	
	
	return 0;
}
